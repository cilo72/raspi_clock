#pragma once

#include <QVariant>
#include <QTime>

class Globals
{
public:
    static void setFullScreen(bool value);
    static bool isFullScreen();
    static QTime alarm();
    static void setAlarm(const QTime & value);
    static QTime alarm1();
    static void setAlarm1(const QTime & value);
    static QTime alarm2();
    static void setAlarm2(const QTime & value);
    static QTime alarm3();
    static void setAlarm3(const QTime & value);
    static int volume();
    static void setVolume(int value);
private:
    static bool isFullScreen_;
    static QTime alarm_;
    static int volume_;
    static void writeSetting(QString key, const QVariant &value);
    static QVariant readSetting(QString key, const QVariant &defaultValue);
};
