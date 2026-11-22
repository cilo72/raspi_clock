#include "dialogsettimeoralarm.h"
#include "ui_dialogsettimeoralarm.h"

DialogSetTimeOrAlarm::DialogSetTimeOrAlarm(const QTime & time, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DialogSetTimeOrAlarm)
    , time_(time)
{
    ui->setupUi(this);
    updateTime(time);
}

DialogSetTimeOrAlarm::~DialogSetTimeOrAlarm()
{
    delete ui;
}

void DialogSetTimeOrAlarm::updateTime(const QTime &time)
{
    time_ = time;
    ui->label_Hh_mm->setText(QString("%1").arg(time.hour() / 10));
    ui->label_hH_mm->setText(QString("%1").arg(time.hour() % 10));

    ui->label_hh_Mm->setText(QString("%1").arg(time.minute() / 10));
    ui->label_hh_mM->setText(QString("%1").arg(time.minute() % 10));
}

void DialogSetTimeOrAlarm::on_pushButton_Hh_mm_plus_clicked()
{
    updateTime(time_.addSecs(10 * 3600));
}

void DialogSetTimeOrAlarm::on_pushButton_Hh_mm_minus_clicked()
{
    updateTime(time_.addSecs(-10 * 3600));
}

void DialogSetTimeOrAlarm::on_pushButton_hH_mm_plus_clicked()
{
    updateTime(time_.addSecs(1 * 3600));
}

void DialogSetTimeOrAlarm::on_pushButton_hH_mm_minus_clicked()
{
    updateTime(time_.addSecs(-1 * 3600));
}

void DialogSetTimeOrAlarm::on_pushButton_hh_Mm_plus_clicked()
{
    updateTime(time_.addSecs(600));
}

void DialogSetTimeOrAlarm::on_pushButton_hh_Mm_minus_clicked()
{
    updateTime(time_.addSecs(-600));
}

void DialogSetTimeOrAlarm::on_pushButton_hh_mM_plus_clicked()
{
    updateTime(time_.addSecs(60));
}

void DialogSetTimeOrAlarm::on_pushButton_hh_mM_minus_clicked()
{
    updateTime(time_.addSecs(-60));
}

void DialogSetTimeOrAlarm::on_pushButtonExit_clicked()
{
    close();
}

void DialogSetTimeOrAlarm::on_pushButtonDone_clicked()
{
    emit timeChanged(time_);
    close();
}
