#ifndef FORMSETALARMTIME_H
#define FORMSETALARMTIME_H

#include <QWidget>
#include <QTime>
#include <QLabel>

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

    void on_pushButton_Hh_mm_plus_clicked();

    void on_pushButton_Hh_mm_minus_clicked();

    void on_pushButton_hH_mm_plus_clicked();

    void on_pushButton_hH_mm_minus_clicked();

    void on_pushButton_hh_Mm_plus_clicked();

    void on_pushButton_hh_Mm_minus_clicked();

    void on_pushButton_hh_mM_plus_clicked();

    void on_pushButton_hh_mM_minus_clicked();

private:
    Ui::FormSetAlarmTime *ui;
    QTime alarmTime1_;
    QTime alarmTime2_;
    QTime alarmTime3_;
    QTime alarmTime_;
    void updateButtons();
    void updateTime(const QTime &time);
};

#endif // FORMSETALARMTIME_H
