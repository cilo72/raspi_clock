#include "formmain.h"
#include "formsettings.h"
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QPushButton>
#include <QTemporaryDir>
#include <QToolButton>
#include <QtTest>

class AlarmTest : public QObject
{
    Q_OBJECT

    void createFile(const QString &name)
    {
        QFile file(QDir::home().filePath("Music/" + name));
        QVERIFY(file.open(QIODevice::WriteOnly));
    }

    void triggerAlarm(FormMain &form)
    {
        form.onSetAlarmTimeDone(QTime::currentTime());
        QVERIFY(QMetaObject::invokeMethod(&form, "timeout", Qt::DirectConnection));
    }

private slots:
    void localMusic()
    {
        QVERIFY(QDir().mkpath(QDir::home().filePath("Music/Album")));
        createFile("01 Früh & spät #1.mp3");
        createFile("Album/02.MP3");
        createFile("ignored.txt");

        FormMain form;
        form.onSettingsDone(60);
        triggerAlarm(form);
        auto *player = form.findChild<QMediaPlayer *>();
        QVERIFY(player);
        auto *playlist = player->playlist();
        QVERIFY(playlist);
        QCOMPARE(playlist->mediaCount(), 2);
        QCOMPARE(playlist->playbackMode(), QMediaPlaylist::Loop);
        QCOMPARE(player->volume(), 60);
        QCOMPARE(playlist->media(0).request().url().toLocalFile(),
                 QDir::home().filePath("Music/01 Früh & spät #1.mp3"));
        QCOMPARE(playlist->media(1).request().url().toLocalFile(),
                 QDir::home().filePath("Music/Album/02.MP3"));

        auto *alarmButton = form.findChild<QPushButton *>("pushButtonSetAlarm");
        QVERIFY(alarmButton);
        alarmButton->click();
        QCOMPARE(player->state(), QMediaPlayer::StoppedState);

        // Re-scan at the next alarm, including files added since startup.
        createFile("03.mp3");
        triggerAlarm(form);
        QCOMPARE(player->playlist()->mediaCount(), 3);
        form.onPlayStop();
        QCOMPARE(player->state(), QMediaPlayer::StoppedState);

        // The preview uses the same local music with the unsaved volume.
        form.onPlayStart(40);
        QCOMPARE(player->playlist()->mediaCount(), 3);
        QCOMPARE(player->volume(), 40);
        QCOMPARE(form.volume(), 60);
        form.onPlayStop();
    }

    void settingsPreview()
    {
        FormMain form;
        FormSettings settings;
        connect(&settings, &FormSettings::onPlayStart, &form, &FormMain::onPlayStart);
        connect(&settings, &FormSettings::onPlayStop, &form, &FormMain::onPlayStop);
        connect(&settings, &FormSettings::onVolumeChanged, &form, &FormMain::onVolumeChanged);
        connect(&form, &FormMain::playbackError, &settings, &FormSettings::onPlaybackError);
        connect(&settings, &FormSettings::onSettingsDone, &form, &FormMain::onSettingsDone);
        settings.init(50);
        auto *test = settings.findChild<QToolButton *>("pushButtonTest");
        auto *player = form.findChild<QMediaPlayer *>();
        QVERIFY(test);
        QVERIFY(player);
        test->click();
        QVERIFY(test->isChecked());
        QCOMPARE(player->playlist()->mediaCount(), 3);
        QCOMPARE(player->volume(), 50);
        settings.findChild<QPushButton *>("pushButtonVolumeIncrement")->click();
        QCOMPARE(player->volume(), 60);
        test->click();
        QVERIFY(!test->isChecked());
        QCOMPARE(player->state(), QMediaPlayer::StoppedState);
        test->click();
        settings.findChild<QPushButton *>("pushButtonDone")->click();
        QCOMPARE(player->state(), QMediaPlayer::StoppedState);
        QCOMPARE(form.volume(), 60);
        settings.init(50);
        QVERIFY(!test->isChecked());
        test->click();
        settings.findChild<QPushButton *>("pushButtonExit")->click();
        QCOMPARE(player->state(), QMediaPlayer::StoppedState);
        QCOMPARE(form.volume(), 60);
    }

    void emptyOrMissingMusic_data()
    {
        QTest::addColumn<bool>("directoryExists");
        QTest::newRow("missing") << false;
        QTest::newRow("empty") << true;
    }

    void emptyOrMissingMusic()
    {
        QFETCH(bool, directoryExists);
        const QString music = QDir::home().filePath("Music");
        QVERIFY(QDir(music).removeRecursively());
        if (directoryExists)
            QVERIFY(QDir().mkpath(music));

        FormMain form;
        triggerAlarm(form);
        auto *player = form.findChild<QMediaPlayer *>();
        QVERIFY(player);
        QVERIFY(!player->playlist());
        QVERIFY(player->media().request().url().isEmpty());
        QCOMPARE(player->state(), QMediaPlayer::StoppedState);
        auto *label = form.findChild<QLabel *>("labelAlarmTime");
        QVERIFY(label);
        QVERIFY(label->text().contains("Keine MP3"));

        FormSettings settings;
        connect(&settings, &FormSettings::onPlayStart, &form, &FormMain::onPlayStart);
        connect(&form, &FormMain::playbackError, &settings, &FormSettings::onPlaybackError);
        settings.init(50);
        auto *test = settings.findChild<QToolButton *>("pushButtonTest");
        test->click();
        QVERIFY(!test->isChecked());
        QVERIFY(settings.findChild<QLabel *>("labelMusicStatus")->text().contains("Keine lesbaren MP3"));
    }
};

int main(int argc, char **argv)
{
    QTemporaryDir home;
    if (!home.isValid())
        return 1;
    qputenv("HOME", home.path().toUtf8());
    // Clock settings must also stay isolated from the user's clock.ini.
    const QString previousDirectory = QDir::currentPath();
    if (!QDir::setCurrent(home.path()))
        return 1;
    QApplication app(argc, argv);
    AlarmTest test;
    const int result = QTest::qExec(&test, argc, argv);
    QDir::setCurrent(previousDirectory);
    return result;
}

#include "alarm_test.moc"
