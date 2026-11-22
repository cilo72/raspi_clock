#ifndef FORMSETALARMTIME_H
#define FORMSETALARMTIME_H

#include <QWidget>
#include <QTime>
#include <QLabel>
#include "widgetsettime.h"

namespace Ui {
class FormSetAlarmTime;
}

class FormSetAlarmTime : public QWidget
{
    Q_OBJECT

public:
    explicit FormSetAlarmTime(QWidget *parent = nullptr);
    ~FormSetAlarmTime();
    void init(const QTime & currentAlarmTime);
signals:
    void onSetAlarmTimeExit();
    void onSetAlarmTimeDone(QTime newTime);
private slots:
    void on_pushButtonExit_clicked();

    void on_pushButtonDone_clicked();

    void on_pushButtonSetAlarmTime_clicked();

    void timeChanged(QTime time);

private:
    Ui::FormSetAlarmTime *ui;
    WidgetSetTime * widgetSetTime_;
    QTime alarmTime1_;
    QTime alarmTime2_;
    QTime alarmTime3_;
    QTime alarmTime_;
    void updateButtons();
    void updateTime(const QTime &time);
};

#endif // FORMSETALARMTIME_H
