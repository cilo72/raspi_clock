#include "systemclock.h"

#include <QDateTime>
#include <QDBusPendingCallWatcher>
#include <QDBusVariant>
#include <QFile>
#include <QTimer>

namespace {
const QString service = QStringLiteral("org.freedesktop.timedate1");
const QString path = QStringLiteral("/org/freedesktop/timedate1");
}

bool SystemClock::isRaspberryPi()
{
    for (const QString &root : {QStringLiteral("/proc/device-tree"),
                                QStringLiteral("/sys/firmware/devicetree/base")})
    {
        QFile compatible(root + "/compatible");
        if (compatible.open(QIODevice::ReadOnly))
        {
            for (const QByteArray &entry : compatible.readAll().split('\0'))
                if (entry.startsWith("raspberrypi,"))
                    return true;
        }
        QFile model(root + "/model");
        if (model.open(QIODevice::ReadOnly) && model.readAll().startsWith("Raspberry Pi"))
            return true;
    }
    return false;
}

SystemClock::SystemClock(QObject *parent, const QDBusConnection &bus,
                         std::function<bool()> raspberryPiDetector)
    : QObject(parent), bus_(bus), raspberryPiDetector_(raspberryPiDetector)
{
}

void SystemClock::call(const QString &interface, const QString &method,
                       const QVariantList &arguments,
                       std::function<void(const QDBusMessage &)> done)
{
    auto request = QDBusMessage::createMethodCall(service, path, interface, method);
    request.setArguments(arguments);
    auto *watcher = new QDBusPendingCallWatcher(bus_.asyncCall(request, 30000), this);
    connect(watcher, &QDBusPendingCallWatcher::finished, this, [watcher, done] {
        const QDBusMessage reply = watcher->reply();
        watcher->deleteLater();
        done(reply);
    });
}

void SystemClock::setTime(QTime time)
{
    if (busy_)
        return;
    busy_ = true;
    disabledNtp_ = false;
    if (!time.isValid())
    {
        complete(false, tr("Ungültige Uhrzeit."));
        return;
    }
    time_ = QTime(time.hour(), time.minute(), 0);
    if (!raspberryPiDetector_())
    {
        // Complete after the time picker has closed, like the real D-Bus path.
        QTimer::singleShot(0, this, [this] {
            complete(true, tr("Simulation: Uhrzeit würde auf %1 gesetzt.\n"
                              "Auf diesem PC bleiben Systemzeit und NTP unverändert.")
                           .arg(time_.toString("HH:mm")));
        });
        return;
    }
    call("org.freedesktop.DBus.Properties", "Get", {service, QString("NTP")},
         [this](const QDBusMessage &reply) {
        if (reply.type() == QDBusMessage::ErrorMessage)
        {
            complete(false, tr("Zeitsynchronisierung konnte nicht geprüft werden: %1")
                           .arg(reply.errorMessage()));
            return;
        }
        if (reply.arguments().size() != 1
            || !reply.arguments().constFirst().canConvert<QDBusVariant>())
        {
            complete(false, tr("Ungültige Antwort des Zeitdienstes."));
            return;
        }
        const bool ntp = qvariant_cast<QDBusVariant>(reply.arguments().constFirst()).variant().toBool();
        if (!ntp)
        {
            applyTime();
            return;
        }
        call(service, "SetNTP", {false, false}, [this](const QDBusMessage &reply) {
            if (reply.type() == QDBusMessage::ErrorMessage)
            {
                complete(false, tr("Automatische Zeitsynchronisierung konnte nicht ausgeschaltet werden: %1")
                               .arg(reply.errorMessage()));
                return;
            }
            disabledNtp_ = true;
            applyTime();
        });
    });
}

void SystemClock::applyTime()
{
    // The dialog edits local hours/minutes. Keep today's date and reset seconds.
    const QDateTime target(QDate::currentDate(), time_, Qt::LocalTime);
    if (!target.isValid() || target.time() != time_)
    {
        fail(tr("Diese Uhrzeit ist am heutigen Datum nicht gültig (Zeitumstellung)."));
        return;
    }
    const qint64 microseconds = target.toMSecsSinceEpoch() * Q_INT64_C(1000);
    call(service, "SetTime", {QVariant::fromValue(microseconds), false, false},
         [this](const QDBusMessage &reply) {
        if (reply.type() == QDBusMessage::ErrorMessage)
        {
            fail(tr("Uhrzeit konnte nicht gesetzt werden: %1").arg(reply.errorMessage()));
            return;
        }
        complete(true, disabledNtp_
                 ? tr("Uhrzeit gesetzt. Automatische Zeitsynchronisierung ist ausgeschaltet.")
                 : tr("Uhrzeit gesetzt."));
    });
}

void SystemClock::fail(const QString &message)
{
    if (!disabledNtp_)
    {
        complete(false, message);
        return;
    }
    call(service, "SetNTP", {true, false}, [this, message](const QDBusMessage &reply) {
        complete(false, reply.type() == QDBusMessage::ErrorMessage
                 ? message + tr("\nAutomatische Zeitsynchronisierung konnte nicht wieder eingeschaltet werden: %1")
                             .arg(reply.errorMessage())
                 : message);
    });
}

void SystemClock::complete(bool success, const QString &message)
{
    busy_ = false;
    emit finished(success, message);
}
