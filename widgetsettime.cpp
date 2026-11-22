#include "widgetsettime.h"
#include "ui_widgetsettime.h"

WidgetSetTime::WidgetSetTime(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WidgetSetTime)
    , time_(QTime::currentTime())
{
    ui->setupUi(this);
}

WidgetSetTime::~WidgetSetTime()
{
    delete ui;
}

void WidgetSetTime::setTime(const QTime & time)
{
    updateTime(time);
}

void WidgetSetTime::updateTime(const QTime &time)
{
    time_ = time;
    ui->label_Hh_mm->setText(QString("%1").arg(time.hour() / 10));
    ui->label_hH_mm->setText(QString("%1").arg(time.hour() % 10));

    ui->label_hh_Mm->setText(QString("%1").arg(time.minute() / 10));
    ui->label_hh_mM->setText(QString("%1").arg(time.minute() % 10));

    emit timeChanged(time);
}

void WidgetSetTime::on_pushButton_Hh_mm_plus_clicked()
{
    updateTime(time_.addSecs(10 * 3600));
}

void WidgetSetTime::on_pushButton_Hh_mm_minus_clicked()
{
    updateTime(time_.addSecs(-10 * 3600));
}

void WidgetSetTime::on_pushButton_hH_mm_plus_clicked()
{
    updateTime(time_.addSecs(1 * 3600));
}

void WidgetSetTime::on_pushButton_hH_mm_minus_clicked()
{
    updateTime(time_.addSecs(-1 * 3600));
}

void WidgetSetTime::on_pushButton_hh_Mm_plus_clicked()
{
    updateTime(time_.addSecs(600));
}

void WidgetSetTime::on_pushButton_hh_Mm_minus_clicked()
{
    updateTime(time_.addSecs(-600));
}

void WidgetSetTime::on_pushButton_hh_mM_plus_clicked()
{
    updateTime(time_.addSecs(60));
}

void WidgetSetTime::on_pushButton_hh_mM_minus_clicked()
{
    updateTime(time_.addSecs(-60));
}
