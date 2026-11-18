#ifndef FORMMAIN_H
#define FORMMAIN_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>

namespace Ui {
class FormMain;
}

class FormMain : public QWidget
{
    Q_OBJECT

public:
    explicit FormMain(QWidget *parent = nullptr);
    ~FormMain();
    void setWifiStatus(int strength, const QString &status);
    const QTime & alarmTime() const { return alarmTime_; }
    int volume() const { return volume_; }
public slots:
    void onSetAlarmTimeDone(QTime newTime);
    void onPlayStart(int volume);
    void onPlayStop();
    void onVolumeChanged(int volume);
    void onSettingsDone(int volume);
signals:
    void playbackError(const QString &message);
    void onSetAlarmTimeRequest();
    void onSettingsRequest();
private:
    Ui::FormMain *ui;
//    QLabel *wifiStatus_;
    QTimer * timer_;
    QTimer * timerPlayer_;
    QMediaPlayer * player_;
    QMediaPlaylist * alarmPlaylist_;
    bool alarmArmed_;
    bool alarmActive_;
    QTime alarmTime_;
    int volume_;
    bool alarmStrong_;
    void updatePushButtonSetAlarm(bool alarmArmed);
    void updateAlarmTime(QTime time);
    QString time2Text(QTime newTime);
    void play(int volume);
private slots:
    void timeout();
    void on_pushButtonSetAlarm_clicked();
    void on_pushButtonSettings_clicked();
};

#endif // FORMMAIN_H
