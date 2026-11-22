#pragma once

#include <QWidget>
#include <QTime>

namespace Ui
{
class DialogSetTimeOrAlarm;
}

class DialogSetTimeOrAlarm : public QWidget
{
    Q_OBJECT

public:
    explicit DialogSetTimeOrAlarm(const QTime &time, QWidget *parent = nullptr);
    ~DialogSetTimeOrAlarm();

signals:
    void timeChanged(QTime time);

private:
    Ui::DialogSetTimeOrAlarm *ui;

    void updateTime(const QTime &time);

    QTime time_;

private slots:
    void on_pushButton_Hh_mm_plus_clicked();

    void on_pushButton_Hh_mm_minus_clicked();

    void on_pushButton_hH_mm_plus_clicked();

    void on_pushButton_hH_mm_minus_clicked();

    void on_pushButton_hh_Mm_plus_clicked();

    void on_pushButton_hh_Mm_minus_clicked();

    void on_pushButton_hh_mM_plus_clicked();

    void on_pushButton_hh_mM_minus_clicked();


    void on_pushButtonExit_clicked();
    void on_pushButtonDone_clicked();
};
