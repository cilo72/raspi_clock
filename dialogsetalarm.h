#pragma once

#include <QWidget>
#include <QTime>
#include <QLabel>

namespace Ui {
class DialogSetAlarm;
}

class DialogSetAlarm : public QWidget
{
    Q_OBJECT

public:
    explicit DialogSetAlarm(QWidget *parent = nullptr);
    ~DialogSetAlarm();

signals:
    void signal_alarmChanged(QTime time);
private slots:
    void on_pushButtonExit_clicked();

    void on_pushButtonDone_clicked();

    void on_pushButtonSetAlarm_clicked();

    void on_timeChanged(QTime time);

private:
    Ui::DialogSetAlarm *ui;
    QTime alarm1_;
    QTime alarm2_;
    QTime alarm3_;
    QTime alarm_;
    void updateButtons();  
};
