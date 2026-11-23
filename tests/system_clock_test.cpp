#include "systemclock.h"
#include <QtDBus>
#include <QtTest>

class TimeServiceMock : public QDBusVirtualObject
{
public:
    bool ntp = false;
    bool failRead = false, failDisable = false, failSet = false, failRestore = false;
    QStringList calls;
    QVariantList timeArguments;

    QString introspect(const QString &) const override { return {}; }
    bool handleMessage(const QDBusMessage &request, const QDBusConnection &bus) override
    {
        QString failure;
        QVariantList result;
        if (request.member() == "Get")
        {
            calls << "Get";
            if (failRead)
                failure = "Read denied";
            else
                result << QVariant::fromValue(QDBusVariant(ntp));
        }
        else if (request.member() == "SetNTP")
        {
            const bool enabled = request.arguments().first().toBool();
            calls << (enabled ? "EnableNTP" : "DisableNTP");
            if ((!enabled && failDisable) || (enabled && failRestore))
                failure = "NTP denied";
            else
                ntp = enabled;
        }
        else if (request.member() == "SetTime")
        {
            calls << "SetTime";
            timeArguments = request.arguments();
            if (failSet)
                failure = "Setting time denied";
        }
        else
            return false;
        bus.send(failure.isEmpty() ? request.createReply(result)
                 : request.createErrorReply("org.freedesktop.DBus.Error.AccessDenied", failure));
        return true;
    }
};

class SystemClockTest : public QObject
{
    Q_OBJECT
    TimeServiceMock mock_;

private slots:
    void init()
    {
        mock_.ntp = false;
        mock_.failRead = mock_.failDisable = mock_.failSet = mock_.failRestore = false;
        mock_.calls.clear();
        mock_.timeArguments.clear();
        auto bus = QDBusConnection::sessionBus();
        QVERIFY(bus.registerService("org.freedesktop.timedate1"));
        QVERIFY(bus.registerVirtualObject("/org/freedesktop/timedate1", &mock_));
    }

    void cleanup()
    {
        auto bus = QDBusConnection::sessionBus();
        bus.unregisterObject("/org/freedesktop/timedate1");
        bus.unregisterService("org.freedesktop.timedate1");
    }

    void setTime_data()
    {
        QTest::addColumn<bool>("ntp");
        QTest::newRow("manual-clock") << false;
        QTest::newRow("network-clock") << true;
    }

    void setTime()
    {
        QFETCH(bool, ntp);
        mock_.ntp = ntp;
        SystemClock clock(nullptr, QDBusConnection::sessionBus());
        QSignalSpy finished(&clock, &SystemClock::finished);
        const QDate before = QDate::currentDate();
        clock.setTime(QTime(9, 42, 59));
        // A second request during the first operation must not interleave calls.
        clock.setTime(QTime(12, 0));
        QTRY_COMPARE(finished.count(), 1);
        QVERIFY(finished.first().at(0).toBool());
        QCOMPARE(mock_.calls, ntp ? QStringList({"Get", "DisableNTP", "SetTime"})
                                  : QStringList({"Get", "SetTime"}));
        QVERIFY(!mock_.ntp);
        QCOMPARE(mock_.timeArguments.size(), 3);
        QCOMPARE(mock_.timeArguments.at(0).userType(), int(QMetaType::LongLong));
        const auto selected = QDateTime::fromMSecsSinceEpoch(mock_.timeArguments.at(0).toLongLong() / 1000);
        QCOMPARE(selected.time(), QTime(9, 42));
        QVERIFY(selected.date() == before || selected.date() == QDate::currentDate());
        QCOMPARE(mock_.timeArguments.at(1).toBool(), false); // Absolute UTC timestamp.
        QCOMPARE(mock_.timeArguments.at(2).toBool(), false); // No password prompt.
    }

    void failures_data()
    {
        QTest::addColumn<QString>("stage");
        QTest::addColumn<QStringList>("expectedCalls");
        QTest::newRow("properties") << "read" << QStringList({"Get"});
        QTest::newRow("disable-ntp") << "disable" << QStringList({"Get", "DisableNTP"});
        QTest::newRow("set-time") << "set" << QStringList({"Get", "DisableNTP", "SetTime", "EnableNTP"});
        QTest::newRow("restore-ntp") << "restore" << QStringList({"Get", "DisableNTP", "SetTime", "EnableNTP"});
        QTest::newRow("set-without-ntp") << "manual" << QStringList({"Get", "SetTime"});
    }

    void failures()
    {
        QFETCH(QString, stage);
        QFETCH(QStringList, expectedCalls);
        mock_.ntp = stage != "manual";
        mock_.failRead = stage == "read";
        mock_.failDisable = stage == "disable";
        mock_.failSet = stage == "set" || stage == "restore" || stage == "manual";
        mock_.failRestore = stage == "restore";
        SystemClock clock(nullptr, QDBusConnection::sessionBus());
        QSignalSpy finished(&clock, &SystemClock::finished);
        clock.setTime(QTime(8, 15));
        QTRY_COMPARE(finished.count(), 1);
        QVERIFY(!finished.first().at(0).toBool());
        QVERIFY(!finished.first().at(1).toString().isEmpty());
        QCOMPARE(mock_.calls, expectedCalls);
        if (stage == "set")
            QVERIFY(mock_.ntp);
        if (stage == "restore")
            QVERIFY(finished.first().at(1).toString().contains("wieder eingeschaltet"));
    }

    void invalidTime()
    {
        SystemClock clock(nullptr, QDBusConnection::sessionBus());
        QSignalSpy finished(&clock, &SystemClock::finished);
        clock.setTime(QTime());
        QCOMPARE(finished.count(), 1);
        QVERIFY(!finished.first().at(0).toBool());
        QVERIFY(mock_.calls.isEmpty());
    }
};

QTEST_GUILESS_MAIN(SystemClockTest)
#include "system_clock_test.moc"
