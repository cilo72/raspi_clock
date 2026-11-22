#include "music.h"

#include <QDir>
#include <QFileInfo>
#include <QStorageInfo>
#include <QDirIterator>

Music * Music::player()
{
    static Music player;
    return &player;
}

Music::Music()
    : player_(new QMediaPlayer(this))
    , alarmPlaylist_(new QMediaPlaylist(this))
{
    connect(this, &Music::signal_start, this, &Music::on_start);
    connect(this, &Music::signal_stop, this, &Music::on_stop);
    connect(this, &Music::signal_volume, this, &Music::on_volume);
}

Music::~Music()
{
    delete alarmPlaylist_;
    delete player_;
}

QString Music::directory()
{
    QStringList usbDirectories;
    for (const QStorageInfo &storage : QStorageInfo::mountedVolumes())
    {
        if (!storage.isValid() || !storage.isReady())
            continue;

        // Resolve device aliases, then inspect the Linux device ancestry. This
        // distinguishes USB drives from the Raspberry Pi's SD card and disks.
        const QString device = QFileInfo(QString::fromLocal8Bit(storage.device())).canonicalFilePath();
        if (device.isEmpty())
            continue;
        const QString devicePath = QFileInfo(QStringLiteral("/sys/class/block/")
                                            + QFileInfo(device).fileName()).canonicalFilePath();
        if (devicePath.contains(QStringLiteral("/usb")))
            usbDirectories.append(storage.rootPath());
    }

    return Music::fromUsbMounts(usbDirectories);
}

QString Music::fromUsbMounts(QStringList mountPaths)
{
    // Pick consistently when several USB drives or partitions are mounted.
    mountPaths.sort();
    return mountPaths.isEmpty() ? QDir::home().filePath("Music")
                               : mountPaths.first();
}

void Music::start(int volume)
{
    emit signal_start(volume);
}

void Music::stop()
{
    emit signal_stop();
}

void Music::setVolume(int volume)
{
    emit signal_volume(volume);
}

void Music::on_start(int volume)
{
    player_->stop();
    player_->setVolume(volume);
    player_->setPlaylist(nullptr);
    alarmPlaylist_->clear();

    // Read the directory for each alarm so newly added music is included.
    const QString directory = Music::directory();
    QDirIterator files(directory, QDir::Files | QDir::Readable, QDirIterator::Subdirectories);
    QStringList tracks;
    while (files.hasNext())
    {
        files.next();
        if (files.fileInfo().suffix().compare("mp3", Qt::CaseInsensitive) == 0)
            tracks.append(files.filePath());
    }
    for (const QString &track : tracks)
    {
        alarmPlaylist_->addMedia(QUrl::fromLocalFile(track));
    }

    //if (alarmPlaylist_->isEmpty())
    //{
    //    qWarning() << "Keine lesbaren MP3-Dateien in" << directory;
    //    if (alarmActive_)
    //        ui->labelAlarmTime->setText(tr("Keine MP3 in %1").arg(directory));
    //    //emit playbackError(tr("Keine lesbaren MP3-Dateien in %1").arg(directory));
    //    return;
    //}

    // Start each alarm or preview with a newly shuffled order.
    alarmPlaylist_->shuffle();
    player_->setPlaylist(alarmPlaylist_);
    alarmPlaylist_->setCurrentIndex(0);
    player_->play();
}

void Music::on_stop()
{
    player_->stop();
}

void Music::on_volume(int volume)
{
    player_->setVolume(volume);
}