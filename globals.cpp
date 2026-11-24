#include "globals.h"
#include <QSettings>

bool Globals::isFullScreen_ = false;
QTime Globals::alarm_ = QTime(6, 2);
int Globals::volume_ = 80;

static const char * iniFileName = "clock.ini";
static const char * KEY_ALARM   = "main/alarm_time";
static const char * KEY_VOLUME  = "main/volume";
static const char * KEY_ALARM_1 = "set_alarm_time/alarm_time1";
static const char * KEY_ALARM_2 = "set_alarm_time/alarm_time2";
static const char * KEY_ALARM_3 = "set_alarm_time/alarm_time3";

void Globals::setFullScreen(bool value)
{
    isFullScreen_ = value;
}

bool Globals::isFullScreen()
{
    return isFullScreen_;
}

void Globals::writeSetting(QString key, const QVariant &value)
{
    QSettings settings(iniFileName, QSettings::IniFormat);
    settings.setValue(key, value);
}

QVariant Globals::readSetting(QString key, const QVariant &defaultValue)
{
    QSettings settings(iniFileName, QSettings::IniFormat);
    QVariant v = settings.value(key, defaultValue);
    return v;
}

QTime Globals::alarm()
{
    return readSetting(KEY_ALARM, alarm_).toTime();
}

void Globals::setAlarm(const QTime & value)
{
    writeSetting(KEY_ALARM, value);
}

QTime Globals::alarm1()
{
    return readSetting(KEY_ALARM_1, alarm_).toTime();
}

void Globals::setAlarm1(const QTime & value)
{
    writeSetting(KEY_ALARM_1, value);
}

QTime Globals::alarm2()
{
    return readSetting(KEY_ALARM_2, alarm_).toTime();
}

void Globals::setAlarm2(const QTime & value)
{
    writeSetting(KEY_ALARM_2, value);
}

QTime Globals::alarm3()
{
    return readSetting(KEY_ALARM_3, alarm_).toTime();
}

void Globals::setAlarm3(const QTime & value)
{
    writeSetting(KEY_ALARM_3, value);
}

int Globals::volume()
{
    return readSetting(KEY_VOLUME, volume_).toInt();
}

void Globals::setVolume(int value)
{
    writeSetting(KEY_VOLUME, value);
}
