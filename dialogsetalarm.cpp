#include "dialogsetalarm.h"
#include "dialogsettimeoralarm.h"
#include "ui_dialogsetalarm.h"
#include "globals.h"
#include "guihelper.h"

static QString time2Text(QTime newTime)
{
    return QString("%1:%2").arg(newTime.hour(), 2, 10, QChar('0')).arg(newTime.minute(), 2, 10, QChar('0'));
}


DialogSetAlarm::DialogSetAlarm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DialogSetAlarm)
    , alarm1_(QTime(5, 50))
    , alarm2_(QTime(6, 10))
    , alarm3_(QTime(7, 01))
{
    alarm_  = Globals::alarm();
    alarm1_ = Globals::alarm1();
    alarm2_ = Globals::alarm2();
    alarm3_ = Globals::alarm3();
    ui->setupUi(this);

    updateButtons();

    if (alarm_ == alarm1_)
    {
        ui->pushButtonAlarm1->setChecked(true);
    }
    else if (alarm_ == alarm2_)
    {
        ui->pushButtonAlarm2->setChecked(true);
    }
    else if (alarm_ == alarm3_)
    {
        ui->pushButtonAlarm3->setChecked(true);
    }
    else
    {
        alarm3_ = alarm_;
        ui->pushButtonAlarm3->setChecked(true);
    }
    updateButtons();
}

DialogSetAlarm::~DialogSetAlarm()
{
    delete ui;
}

void DialogSetAlarm::on_pushButtonExit_clicked()
{
    close();
}

void DialogSetAlarm::on_pushButtonDone_clicked()
{
    if (ui->pushButtonAlarm1->isChecked())
    {
        emit signal_alarmChanged(alarm1_);
    }
    else if (ui->pushButtonAlarm2->isChecked())
    {
        emit signal_alarmChanged(alarm2_);
    }
    else
    {
        emit signal_alarmChanged(alarm3_);
    }
    close();
}

void DialogSetAlarm::updateButtons()
{
    ui->pushButtonAlarm1->setText(time2Text(alarm1_));
    ui->pushButtonAlarm2->setText(time2Text(alarm2_));
    ui->pushButtonAlarm3->setText(time2Text(alarm3_));
}

void DialogSetAlarm::on_pushButtonSetAlarm_clicked()
{
    if (ui->pushButtonAlarm1->isChecked())
    {
        alarm_ = alarm1_;
    }
    else if (ui->pushButtonAlarm2->isChecked())
    {
        alarm_ = alarm2_;
    }
    else
    {
        alarm_ = alarm3_;
    }
    auto * dialog = new DialogSetTimeOrAlarm(alarm_, this);
    connect(dialog, &DialogSetTimeOrAlarm::timeChanged, this, &DialogSetAlarm::on_timeChanged );
    GuiHelper::showModal(dialog);
}

void DialogSetAlarm::on_timeChanged(QTime time)
{
    if (ui->pushButtonAlarm1->isChecked())
    {
        Globals::setAlarm1(time);
     }
    else if (ui->pushButtonAlarm2->isChecked())
    {
        Globals::setAlarm2(time);
     }
    else
    {
        Globals::setAlarm3(time);
     }

    emit signal_alarmChanged(time);
    close();
}