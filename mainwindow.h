#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonSettings_clicked();

    void on_pushButtonSetAlarm_clicked();

    void on_alarmChanged(QTime newTime);

private:
    friend class AlarmPlaybackTest;
    Ui::MainWindow *ui;
    QTimer * timer_;
    QTimer * timerPlayer_;
    bool alarmArmed_;
    bool alarmActive_;
    QTime alarm_;
    bool alarmStrong_;
    void timeout();
    void timeoutPlayer();
    QString time2Text(QTime newTime);
    void update();
};
