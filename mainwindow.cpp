#include "mainwindow.h"
#include "dialogsettings.h"
#include "dialogsetalarm.h"
#include "guihelper.h"
#include "./ui_mainwindow.h"
#include "globals.h"
#include "music.h"


static const char * styleSheetPushButtonSetAlarmOn = R"V0G0N(
QPushButton {
    background-color: rgb(99, 69, 44);
    border-style: outset;
    border-width: 3px;
    border-radius: 10px;
    border-color: rgb(230, 225, 201);
    padding: 6px;
    image: url(:/icons/icons/alarm-on-on.svg);
}

QPushButton:pressed {
    border-style: inset;
    border-color: rgb(172, 147,98);
    image: url(:/icons/icons/alarm-on-off.svg);
}
)V0G0N";

static const char * styleSheetPushButtonSetAlarmOnStrong = R"V0G0N(
QPushButton {
    background-color: rgb(99, 69, 44);
    border-style: outset;
    border-width: 6px;
    border-radius: 10px;
    border-color: rgb(230, 225, 201);
    padding: 6px;
    image: url(:/icons/icons/alarm-on-on.svg);
}

QPushButton:pressed {
    border-style: inset;
    border-color: rgb(172, 147,98);
    image: url(:/icons/icons/alarm-on-off.svg);
}
)V0G0N";


static const char * styleSheetPushButtonSetAlarmOff = R"V0G0N(
QPushButton {
    background-color: rgb(99, 69, 44);
    border-style: outset;
    border-width: 3px;
    border-radius: 10px;
    border-color: rgb(230, 225, 201);
    padding: 6px;
    image: url(:/icons/icons/alarm-off-on.svg);
}

QPushButton:pressed {
    border-style: inset;
    border-color: rgb(172, 147,98);
    image: url(:/icons/icons/alarm-off-off.svg);
}
)V0G0N";

//static const char * KEY_ALARM_TIME = "main/alarm_time";
//static const char * KEY_VOLUME     = "main/volume";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer_(new QTimer)
    , timerPlayer_(new QTimer)
    , alarmArmed_(false)
    , alarmActive_(false)
    , alarm_(QTime(6, 2))
    , alarmStrong_(false)
{
    ui->setupUi(this);
    alarm_ = Globals::alarm();

    timeout();
    connect(timer_, &QTimer::timeout, this, &MainWindow::timeout);
    connect(timerPlayer_, &QTimer::timeout, this, &MainWindow::timeoutPlayer);
    timerPlayer_->setSingleShot(true);
    update();
    timer_->start(1000);
}

MainWindow::~MainWindow()
{
    delete timer_;
    delete timerPlayer_;
    delete ui;
}

void MainWindow::timeout()
{
    QTime now = QTime::currentTime();
    ui->labelTime->setText(time2Text(now));
    if((alarmArmed_ == true) and (alarmActive_ == false))
    {
        if((now.hour() == alarm_.hour()) and (now.minute() == alarm_.minute()))
        {
            timerPlayer_->start(60*10*1000);
            alarmActive_ = true;
            Music::player()->start(Globals::volume());
        }
    }

    if(alarmActive_)
    {
        alarmStrong_ = not alarmStrong_;
        ui->pushButtonSetAlarm->setStyleSheet(alarmStrong_ ? styleSheetPushButtonSetAlarmOn : styleSheetPushButtonSetAlarmOnStrong);
    }
}

QString MainWindow::time2Text(QTime newTime)
{
    return QString("%1:%2").arg(newTime.hour(), 2, 10, QChar('0')).arg(newTime.minute(), 2, 10, QChar('0'));
}

void MainWindow::on_pushButtonSettings_clicked()
{
    GuiHelper::showModal(new DialogSettings(this));
}

void MainWindow::on_pushButtonSetAlarm_clicked()
{
    if(alarmArmed_ == true)
    {
        alarmArmed_ = false;
        alarmActive_ = false;
        alarmStrong_ = false;
        timerPlayer_->stop();
        Music::player()->stop();        
    }
    else
    {
        auto * dialog = new DialogSetAlarm();
        connect(dialog, &DialogSetAlarm::signal_alarmChanged, this, &MainWindow::on_alarmChanged);
        GuiHelper::showModal(dialog);
    }
    update();
}

void MainWindow::timeoutPlayer()
{
    timerPlayer_->stop();
    alarmActive_ = false;
    alarmStrong_ = false;
    Music::player()->stop();
    update();
}

void MainWindow::on_alarmChanged(QTime newTime)
{
    alarm_ = newTime;
    alarmArmed_ = true;
    update();
    Globals::setAlarm(alarm_);
}

void MainWindow::update()
{
    ui->pushButtonSetAlarm->setStyleSheet(alarmArmed_ ? styleSheetPushButtonSetAlarmOn : styleSheetPushButtonSetAlarmOff);
    ui->labelAlarm->setText(alarmArmed_ ? time2Text(alarm_) : " ");
}
