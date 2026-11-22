#include "formmain.h"
#include "ui_formmain.h"
#include "clock.h"
#include "musicdirectory.h"
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QDir>
#include <QDirIterator>
#include <QFileInfo>

static const char * styleSheetPushButtonSetAlarmOn = R"V0G0N(
QPushButton {
    background-color: rgb(99, 69, 44);
    border-style: outset;
    border-width: 3px;
    border-radius: 10px;
    border-color: rgb(230, 225, 201);
    padding: 6px;
    image: url(:/icons/icons/alarm-on-on.svg);
}

QPushButton:pressed {
    border-style: inset;
    border-color: rgb(172, 147,98);
    image: url(:/icons/icons/alarm-on-off.svg);
}
)V0G0N";

static const char * styleSheetPushButtonSetAlarmOnStrong = R"V0G0N(
QPushButton {
    background-color: rgb(99, 69, 44);
    border-style: outset;
    border-width: 6px;
    border-radius: 10px;
    border-color: rgb(230, 225, 201);
    padding: 6px;
    image: url(:/icons/icons/alarm-on-on.svg);
}

QPushButton:pressed {
    border-style: inset;
    border-color: rgb(172, 147,98);
    image: url(:/icons/icons/alarm-on-off.svg);
}
)V0G0N";


static const char * styleSheetPushButtonSetAlarmOff = R"V0G0N(
QPushButton {
    background-color: rgb(99, 69, 44);
    border-style: outset;
    border-width: 3px;
    border-radius: 10px;
    border-color: rgb(230, 225, 201);
    padding: 6px;
    image: url(:/icons/icons/alarm-off-on.svg);
}

QPushButton:pressed {
    border-style: inset;
    border-color: rgb(172, 147,98);
    image: url(:/icons/icons/alarm-off-off.svg);
}
)V0G0N";

static const char * KEY_ALARM_TIME = "main/alarm_time";
static const char * KEY_VOLUME     = "main/volume";

FormMain::FormMain(QWidget *parent, std::function<QString()> directoryProvider)
    : QWidget(parent)
    , ui(new Ui::FormMain)
    , directoryProvider_(directoryProvider)
    , timer_(new QTimer)
    , timerPlayer_(new QTimer)
    , player_(new QMediaPlayer(this))
    , alarmPlaylist_(new QMediaPlaylist(this))
    , alarmArmed_(false)
    , alarmActive_(false)
    , alarmTime_(QTime(6, 2))
    , volume_(80)
    , alarmStrong_(false)
{
    alarmTime_ = Clock::readSetting(KEY_ALARM_TIME, alarmTime_).toTime();
    volume_    = Clock::readSetting(KEY_VOLUME, volume_).toInt();
    ui->setupUi(this);
    //wifiStatus_ = new QLabel(this);
    //wifiStatus_->setFixedSize(88, 60);
    //ui->horizontalLayout_2->insertWidget(1, wifiStatus_);
    setWifiStatus(-1, tr("WLAN wird geprüft …"));
    connect(timer_, &QTimer::timeout, this, &FormMain::timeout);
    timer_->start(1000);

    connect(timerPlayer_, &QTimer::timeout, this, &FormMain::onPlayStop);
    timerPlayer_->setSingleShot(true);
    alarmPlaylist_->setPlaybackMode(QMediaPlaylist::Loop);

    updatePushButtonSetAlarm(alarmArmed_);
    updateAlarmTime(alarmTime_);
    ui->labelAlarmTime->setText(" ");
}

FormMain::~FormMain()
{
    delete player_;
    delete timerPlayer_;
    delete timer_;
    delete ui;
}

void FormMain::timeout()
{
    QTime now = QTime::currentTime();
    ui->labelTime->setText(time2Text(now));
    if((alarmArmed_ == true) and (alarmActive_ == false))
    {
        if((now.hour() == alarmTime_.hour()) and (now.minute() == alarmTime_.minute()))
        {
            timerPlayer_->start(60*10*1000);
            alarmActive_ = true;
            play(volume_);
        }
    }

    if(alarmActive_)
    {
        alarmStrong_ = not alarmStrong_;
        ui->pushButtonSetAlarm->setStyleSheet(alarmStrong_ ? styleSheetPushButtonSetAlarmOn : styleSheetPushButtonSetAlarmOnStrong);
    }
}

void FormMain::on_pushButtonSetAlarm_clicked()
{
    if(alarmArmed_ == true)
    {
        alarmArmed_ = false;
        alarmActive_ = false;
        timerPlayer_->stop();
        player_->stop();
        ui->labelAlarmTime->setText(" ");
    }
    else
    {
        emit onSetAlarmTimeRequest();
    }
    updatePushButtonSetAlarm(alarmArmed_);
}

void FormMain::updatePushButtonSetAlarm(bool alarmArmed)
{
    ui->pushButtonSetAlarm->setStyleSheet(alarmArmed ? styleSheetPushButtonSetAlarmOn : styleSheetPushButtonSetAlarmOff);
}

void FormMain::onSetAlarmTimeDone(QTime newTime)
{
    alarmTime_ = newTime;
    alarmArmed_ = true;
    updateAlarmTime(alarmTime_);
    updatePushButtonSetAlarm(alarmArmed_);
    Clock::writeSetting(KEY_ALARM_TIME, alarmTime_);
}

QString FormMain::time2Text(QTime newTime)
{
    return QString("%1:%2").arg(newTime.hour(), 2, 10, QChar('0')).arg(newTime.minute(), 2, 10, QChar('0'));
}

void FormMain::updateAlarmTime(QTime time)
{        
    ui->labelAlarmTime->setText(time2Text(time));
}

void FormMain::play(int volume)
{
    player_->stop();
    player_->setPlaylist(nullptr);
    alarmPlaylist_->clear();

    // Read the directory for each alarm so newly added music is included.
    const QString directory = directoryProvider_();
    QDirIterator files(directory, QDir::Files | QDir::Readable,
                       QDirIterator::Subdirectories);
    QStringList tracks;
    while (files.hasNext())
    {
        files.next();
        if (files.fileInfo().suffix().compare("mp3", Qt::CaseInsensitive) == 0)
            tracks.append(files.filePath());
    }
    for (const QString &track : tracks)
        alarmPlaylist_->addMedia(QUrl::fromLocalFile(track));

    if (alarmPlaylist_->isEmpty())
    {
        qWarning() << "Keine lesbaren MP3-Dateien in" << directory;
        if (alarmActive_)
            ui->labelAlarmTime->setText(tr("Keine MP3 in %1").arg(directory));
        emit playbackError(tr("Keine lesbaren MP3-Dateien in %1").arg(directory));
        return;
    }

    // Start each alarm or preview with a newly shuffled order.
    alarmPlaylist_->shuffle();
    onVolumeChanged(volume);
    player_->setPlaylist(alarmPlaylist_);
    alarmPlaylist_->setCurrentIndex(0);
    player_->play();
}

void FormMain::on_pushButtonSettings_clicked()
{
    emit onSettingsRequest();
}

void FormMain::onPlayStart(int volume)
{
    play(volume);
}

void FormMain::onPlayStop()
{
    player_->stop();
}

void FormMain::onVolumeChanged(int volume)
{
    player_->setVolume(volume);
}

void FormMain::onSettingsDone(int volume)
{
    volume_ = volume;

    Clock::writeSetting(KEY_VOLUME, volume_);
}
void FormMain::setWifiStatus(int strength, const QString &status)
{
    //QPixmap pixmap(88, 60);
    //pixmap.fill(Qt::transparent);
    //QPainter painter(&pixmap);
    //painter.setRenderHint(QPainter::Antialiasing);
    //const int bars = strength < 0 ? 0 : qMax(1, (strength + 24) / 25);
    //for (int i = 0; i < 4; ++i) {
    //    painter.setBrush(i < bars ? QColor(230, 225, 201) : QColor(135, 108, 75));
    //    painter.setPen(Qt::NoPen);
    //    painter.drawRoundedRect(8 + i * 18, 34 - i * 7, 12, 10 + i * 7, 2, 2);
    //}
    //painter.setPen(QColor(230, 225, 201));
    //painter.drawText(QRect(0, 44, 88, 16), Qt::AlignCenter, strength < 0 ? tr("WLAN —") : QString::number(strength) + " %");
    //wifiStatus_->setPixmap(pixmap);
    //wifiStatus_->setToolTip(status);
}
