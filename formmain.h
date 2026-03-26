#ifndef FORMMAIN_H
#define FORMMAIN_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QtMultimedia/QMediaPlayer>

namespace Ui {
class FormMain;
}

class FormMain : public QWidget
{
    Q_OBJECT

public:
    explicit FormMain(QWidget *parent = nullptr);
    ~FormMain();
    const QTime & alarmTime() const { return alarmTime_; }
    int volume() const { return volume_; }
    const QString & station() const { return station_; }
public slots:
    void onSetAlarmTimeDone(QTime newTime);
    void onPlayStart(QString url);
    void onPlayStop();
    void onVolumeChanged(int volume);
    void onSettingsDone(int volume, QString station);
signals:
    void onSetAlarmTimeRequest();
    void onSettingsRequest();
private:
    Ui::FormMain *ui;
    QTimer * timer_;
    QTimer * timerPlayer_;
    QMediaPlayer * player_;
    bool alarmArmed_;
    bool alarmActive_;
    QTime alarmTime_;
    int volume_;
    bool alarmStrong_;
    QString station_;
    void updatePushButtonSetAlarm(bool alarmArmed);
    void updateAlarmTime(QTime time);
    QString time2Text(QTime newTime);
    void play();
private slots:
    void timeout();
    void on_pushButtonSetAlarm_clicked();
    void on_pushButtonSettings_clicked();
};

#endif // FORMMAIN_H
