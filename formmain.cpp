#include "formmain.h"
#include "ui_formmain.h"
#include "clock.h"

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

static const char * KEY_ALARM_TIME = "main/alarm_time";
static const char * KEY_VOLUME     = "main/volume";
static const char * KEY_STATION    = "main/station";

FormMain::FormMain(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormMain)
    , timer_(new QTimer)
    , timerPlayer_(new QTimer)
    , player_(new QMediaPlayer)
    , alarmArmed_(false)
    , alarmActive_(false)
    , alarmTime_(QTime(6, 2))
    , volume_(80)
    , alarmStrong_(false)
    , station_(Clock::stationRpMainMix())
{
    alarmTime_ = Clock::readSetting(KEY_ALARM_TIME, alarmTime_).toTime();
    volume_    = Clock::readSetting(KEY_VOLUME, volume_).toInt();
    station_   = Clock::readSetting(KEY_STATION, station_).toString();
    ui->setupUi(this);
    connect(timer_, &QTimer::timeout, this, &FormMain::timeout);
    timer_->start(1000);

    connect(timerPlayer_, &QTimer::timeout, this, &FormMain::onPlayStop);
    timerPlayer_->setSingleShot(true);

    updatePushButtonSetAlarm(alarmArmed_);
    updateAlarmTime(alarmTime_);
    ui->labelAlarmTime->setText(" ");
}

FormMain::~FormMain()
{
    delete player_;
    delete timerPlayer_;
    delete timer_;
    delete ui;
}

void FormMain::timeout()
{
    QTime now = QTime::currentTime();
    ui->labelTime->setText(time2Text(now));
    if((alarmArmed_ == true) and (alarmActive_ == false))
    {
        if((now.hour() == alarmTime_.hour()) and (now.minute() == alarmTime_.minute()))
        {
            timerPlayer_->start(60*10*1000);
            alarmActive_ = true;
            play();
        }
    }

    if(alarmActive_)
    {
        alarmStrong_ = not alarmStrong_;
        ui->pushButtonSetAlarm->setStyleSheet(alarmStrong_ ? styleSheetPushButtonSetAlarmOn : styleSheetPushButtonSetAlarmOnStrong);
    }
}

void FormMain::on_pushButtonSetAlarm_clicked()
{
    if(alarmArmed_ == true)
    {
        alarmArmed_ = false;
        alarmActive_ = false;
        player_->stop();
        ui->labelAlarmTime->setText(" ");
    }
    else
    {
        emit onSetAlarmTimeRequest();
    }
    updatePushButtonSetAlarm(alarmArmed_);
}

void FormMain::updatePushButtonSetAlarm(bool alarmArmed)
{
    ui->pushButtonSetAlarm->setStyleSheet(alarmArmed ? styleSheetPushButtonSetAlarmOn : styleSheetPushButtonSetAlarmOff);
}

void FormMain::onSetAlarmTimeDone(QTime newTime)
{
    alarmTime_ = newTime;
    alarmArmed_ = true;
    updateAlarmTime(alarmTime_);
    updatePushButtonSetAlarm(alarmArmed_);
    Clock::writeSetting(KEY_ALARM_TIME, alarmTime_);
}

QString FormMain::time2Text(QTime newTime)
{
    return QString("%1:%2").arg(newTime.hour(), 2, 10, QChar('0')).arg(newTime.minute(), 2, 10, QChar('0'));
}

void FormMain::updateAlarmTime(QTime time)
{        
    ui->labelAlarmTime->setText(time2Text(time));
}

void FormMain::play()
{
    onVolumeChanged(volume_);
    onPlayStart(station_);
}

void FormMain::on_pushButtonSettings_clicked()
{
    emit onSettingsRequest();
}

void FormMain::onPlayStart(QString url)
{
    player_->setMedia(QUrl(url));
    player_->play();
}

void FormMain::onPlayStop()
{
    player_->stop();
}

void FormMain::onVolumeChanged(int volume)
{
    player_->setVolume(volume);
}

void FormMain::onSettingsDone(int volume, QString station)
{
    volume_ = volume;
    station_ = station;

    Clock::writeSetting(KEY_VOLUME, volume_);
    Clock::writeSetting(KEY_STATION, station_);
}