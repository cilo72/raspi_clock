#include "clock.h"

static const char * rpMainMix   = "http://stream.radioparadise.com/aac-128";
static const char * rpMellowMix = "http://stream.radioparadise.com/mellow-128";
static const char * sf3         = "http://stream.srg-ssr.ch/m/drs3/aacp_96";
static const char * flux80      = "http://channels.fluxfm.de/80s/externalembedflxhp/stream.aac";

static const char * iniFileName = "clock.ini";

QString Clock::stationRpMainMix()
{
    return rpMainMix;
}

QString Clock::stationRpMellowMix()
{
    return rpMellowMix;
}

QString Clock::stationSf3()
{
    return sf3;
}

QString Clock::stationFlux80()
{
    return flux80;
}

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
