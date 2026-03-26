#pragma once

#include <QObject>
#include <QSettings>

class Clock
{

public:
    static QString stationRpMainMix();
    static QString stationRpMellowMix();
    static QString stationSf3();
    static QString stationFlux80();
    static void     writeSetting(QString key, const QVariant &value);
    static QVariant readSetting(QString key, const QVariant &defaultValue);
};

