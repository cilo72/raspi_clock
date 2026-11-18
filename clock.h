#pragma once

#include <QObject>
#include <QSettings>

class Clock
{

public:
    static void     writeSetting(QString key, const QVariant &value);
    static QVariant readSetting(QString key, const QVariant &defaultValue);
};

