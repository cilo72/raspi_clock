#include "clock.h"

static const char * iniFileName = "clock.ini";

void Clock::writeSetting(QString key, const QVariant &value)
{
    QSettings settings(iniFileName, QSettings::IniFormat);
    settings.setValue(key, value);
}

QVariant Clock::readSetting(QString key, const QVariant &defaultValue)
{
    QSettings settings(iniFileName, QSettings::IniFormat);
    QVariant v = settings.value(key, defaultValue);
    return v;
}
