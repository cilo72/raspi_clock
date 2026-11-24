#pragma once

#include <QObject>
#include <QStringList>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>

class Music : public QObject
{
    Q_OBJECT
public:
    static QString directory();
    static Music * player();
    void start(int volume);
    void stop();
    void setVolume(int volume);
private:
    Music();
    ~Music();
    static QString fromUsbMounts(QStringList mountPaths);
    QMediaPlayer * player_;
    QMediaPlaylist * alarmPlaylist_;

signals:
    void signal_start(int volume);
    void signal_stop();
    void signal_volume(int volume);

private slots:
    void on_start(int volume);
    void on_stop();
    void on_volume(int volume);
};

