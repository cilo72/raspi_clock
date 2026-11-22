#include "formsetalarmtime.h"
#include "ui_formsetalarmtime.h"
#include "clock.h"

static QString time2Text(QTime newTime)
{
    return QString("%1:%2").arg(newTime.hour(), 2, 10, QChar('0')).arg(newTime.minute(), 2, 10, QChar('0'));
}

static const char * KEY_ALARM_TIME_1 = "set_alarm_time/alarm_time1";
static const char * KEY_ALARM_TIME_2 = "set_alarm_time/alarm_time2";
static const char * KEY_ALARM_TIME_3 = "set_alarm_time/alarm_time3";

FormSetAlarmTime::FormSetAlarmTime(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormSetAlarmTime)
    , widgetSetTime_(new WidgetSetTime)
    , alarmTime1_(QTime(5, 50))
    , alarmTime2_(QTime(6, 10))
    , alarmTime3_(QTime(7, 01))
{
    alarmTime1_ = Clock::readSetting(KEY_ALARM_TIME_1, alarmTime1_).toTime();
    alarmTime2_ = Clock::readSetting(KEY_ALARM_TIME_2, alarmTime2_).toTime();
    alarmTime3_ = Clock::readSetting(KEY_ALARM_TIME_3, alarmTime3_).toTime();
    ui->setupUi(this);

    connect(widgetSetTime_, &WidgetSetTime::timeChanged, this, &FormSetAlarmTime::timeChanged);

    updateButtons();
    ui->stackedWidget->setCurrentWidget(ui->pageSetTimeButtons);

    ui->verticalLayoutSetTime->addWidget(widgetSetTime_);
}

FormSetAlarmTime::~FormSetAlarmTime()
{
    delete widgetSetTime_;
    delete ui;
}

void FormSetAlarmTime::init(const QTime &currentAlarmTime)
{
    if (currentAlarmTime == alarmTime1_)
    {
        ui->pushButtonAlarmTime1->setChecked(true);
    }
    else if (currentAlarmTime == alarmTime2_)
    {
        ui->pushButtonAlarmTime2->setChecked(true);
    }
    else if (currentAlarmTime == alarmTime3_)
    {
        ui->pushButtonAlarmTime3->setChecked(true);
    }
    else
    {
        alarmTime3_ = currentAlarmTime;
        ui->pushButtonAlarmTime3->setChecked(true);
    }
    updateButtons();
    ui->stackedWidget->setCurrentWidget(ui->pageSetTimeButtons);
}

void FormSetAlarmTime::on_pushButtonExit_clicked()
{
    emit onSetAlarmTimeExit();
}

void FormSetAlarmTime::on_pushButtonDone_clicked()
{
    if (ui->stackedWidget->currentWidget() == ui->pageSetTime)
    {
        if (ui->pushButtonAlarmTime1->isChecked())
        {
            alarmTime1_ = alarmTime_;
            Clock::writeSetting(KEY_ALARM_TIME_1, alarmTime1_);
        }
        else if (ui->pushButtonAlarmTime2->isChecked())
        {
            alarmTime2_ = alarmTime_;
            Clock::writeSetting(KEY_ALARM_TIME_2, alarmTime2_);
        }
        else
        {
            alarmTime3_ = alarmTime_;
            Clock::writeSetting(KEY_ALARM_TIME_3, alarmTime3_);
        }
        updateButtons();
    }

    if (ui->pushButtonAlarmTime1->isChecked())
    {
        emit onSetAlarmTimeDone(alarmTime1_);
    }
    else if (ui->pushButtonAlarmTime2->isChecked())
    {
        emit onSetAlarmTimeDone(alarmTime2_);
    }
    else if (ui->pushButtonAlarmTime3->isChecked())
    {
        emit onSetAlarmTimeDone(alarmTime3_);
    }
    else
    {
        ui->pushButtonAlarmTime3->setChecked(true);
        emit onSetAlarmTimeDone(alarmTime3_);
    }
}

void FormSetAlarmTime::updateButtons()
{
    ui->pushButtonAlarmTime1->setText(time2Text(alarmTime1_));
    ui->pushButtonAlarmTime2->setText(time2Text(alarmTime2_));
    ui->pushButtonAlarmTime3->setText(time2Text(alarmTime3_));
}

void FormSetAlarmTime::on_pushButtonSetAlarmTime_clicked()
{
    if (ui->pushButtonAlarmTime1->isChecked())
    {
        updateTime(alarmTime1_);
    }
    else if (ui->pushButtonAlarmTime2->isChecked())
    {
        updateTime(alarmTime2_);
    }
    else
    {
        updateTime(alarmTime3_);
    }

    ui->stackedWidget->setCurrentWidget(ui->pageSetTime);
}


void FormSetAlarmTime::updateTime(const QTime &time)
{
    alarmTime_ = time;
    widgetSetTime_->setTime(alarmTime_);
}

void FormSetAlarmTime::timeChanged(QTime time)
{
    alarmTime_ = time;
}