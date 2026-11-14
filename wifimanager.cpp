#include "wifimanager.h"
#include <QtDBus>
#include <QTimer>
#include <QUuid>
#include <algorithm>
#include <memory>

using Settings = QMap<QString, QVariantMap>;
Q_DECLARE_METATYPE(Settings)
namespace {
const QString service = QStringLiteral("org.freedesktop.NetworkManager");
const QString root = QStringLiteral("/org/freedesktop/NetworkManager");
const QString manager = service;
const QString deviceInterface = service + ".Device";
const QString wireless = deviceInterface + ".Wireless";
const QString apInterface = service + ".AccessPoint";
QString objectPath(const QVariant &v) { return qdbus_cast<QDBusObjectPath>(v).path(); }
}

WifiManager::WifiManager(QObject *parent) : QObject(parent)
{
    qDBusRegisterMetaType<Settings>();
    auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &WifiManager::refresh);
    timer->start(5000);
    QTimer::singleShot(0, this, &WifiManager::refresh);
}

void WifiManager::call(const QString &path, const QString &interface, const QString &method,
                       const QVariantList &arguments, std::function<void(QVariantList, QString)> done)
{
    auto request = QDBusMessage::createMethodCall(service, path, interface, method);
    request.setArguments(arguments);
    auto watcher = new QDBusPendingCallWatcher(QDBusConnection::systemBus().asyncCall(request, 10000), this);
    connect(watcher, &QDBusPendingCallWatcher::finished, this, [watcher, done] {
        const QDBusMessage reply = watcher->reply();
        watcher->deleteLater();
        done(reply.arguments(), reply.type() == QDBusMessage::ErrorMessage ? reply.errorMessage() : QString());
    });
}

void WifiManager::properties(const QString &path, const QString &interface,
                             std::function<void(QVariantMap, QString)> done)
{
    call(path, "org.freedesktop.DBus.Properties", "GetAll", {interface}, [done](QVariantList values, QString error) {
        done(values.isEmpty() ? QVariantMap() : qdbus_cast<QVariantMap>(values.first()), error);
    });
}

void WifiManager::refresh()
{
    if (refreshing_) return;
    refreshing_ = true;
    call(root, manager, "GetDevices", {}, [this](QVariantList values, QString error) {
        if (!error.isEmpty()) {
            device_.clear(); networks_.clear(); strength_ = -1;
            status_ = tr("NetworkManager nicht erreichbar: %1").arg(error);
            refreshing_ = false; emit changed(); return;
        }
        const auto paths = values.isEmpty() ? QList<QDBusObjectPath>() : qdbus_cast<QList<QDBusObjectPath>>(values.first());
        if (paths.isEmpty()) {
            device_.clear(); networks_.clear(); strength_ = -1;
            status_ = tr("Kein WLAN-Adapter"); refreshing_ = false; emit changed(); return;
        }
        auto remaining = std::make_shared<int>(paths.size());
        auto found = std::make_shared<bool>(false);
        for (const auto &path : paths) {
            properties(path.path(), deviceInterface, [this, path, remaining, found](QVariantMap p, QString) {
                if (p.value("DeviceType").toUInt() == 2 && !*found) {
                    *found = true; readDevice(path.path());
                }
                if (--*remaining == 0 && !*found) {
                    device_.clear(); networks_.clear(); strength_ = -1;
                    status_ = tr("Kein WLAN-Adapter"); refreshing_ = false; emit changed();
                }
            });
        }
    });
}

void WifiManager::readDevice(const QString &path)
{
    device_ = path;
    properties(path, deviceInterface, [this, path](QVariantMap p, QString error) {
        strength_ = -1;
        if (!error.isEmpty()) {
            status_ = error; refreshing_ = false; emit changed(); return;
        }
        const uint state = p.value("State").toUInt();
        const QString name = p.value("Interface").toString();
        status_ = state == 100 ? tr("%1: verbunden").arg(name)
                : state == 20 ? tr("%1: WLAN ausgeschaltet oder nicht verfügbar").arg(name)
                : state >= 40 && state <= 90 ? tr("%1: Verbindung wird aufgebaut …").arg(name)
                : state == 120 ? tr("%1: Verbindung fehlgeschlagen").arg(name)
                : tr("%1: nicht verbunden").arg(name);
        properties(path, wireless, [this, state](QVariantMap w, QString error) {
            if (!error.isEmpty()) {
                status_ = error; refreshing_ = false; emit changed(); return;
            }
            const QString active = objectPath(w.value("ActiveAccessPoint"));
            const auto paths = qdbus_cast<QList<QDBusObjectPath>>(w.value("AccessPoints"));
            auto result = std::make_shared<QList<WifiNetwork>>();
            auto remaining = std::make_shared<int>(paths.size());
            auto finish = [this, result] {
                std::sort(result->begin(), result->end(), [](const WifiNetwork &a, const WifiNetwork &b) { return a.strength > b.strength; });
                networks_.clear();
                for (const auto &network : *result) {
                    bool duplicate = false;
                    for (const auto &existing : networks_)
                        if (existing.ssid == network.ssid && existing.security == network.security) duplicate = true;
                    if (!duplicate) networks_.append(network);
                }
                refreshing_ = false; emit changed();
            };
            if (paths.isEmpty()) { finish(); return; }
            for (const auto &ap : paths) {
                properties(ap.path(), apInterface, [this, ap, active, state, result, remaining, finish](QVariantMap p, QString error) {
                    if (error.isEmpty()) {
                        WifiNetwork n;
                        n.path = ap.path(); n.ssid = p.value("Ssid").toByteArray();
                        n.strength = p.value("Strength").toInt();
                        const uint flags = p.value("WpaFlags").toUInt() | p.value("RsnFlags").toUInt();
                        n.security = (flags & 0x100) ? "wpa-psk" : (flags & 0x400) ? "sae"
                                   : (flags & 0x800) ? "owe" : (flags || (p.value("Flags").toUInt() & 1)) ? "unsupported" : "open";
                        if (!n.ssid.isEmpty()) result->append(n);
                        if (state == 100 && ap.path() == active) {
                            strength_ = n.strength;
                            status_ = tr("%1 · %2 %").arg(QString::fromUtf8(n.ssid)).arg(n.strength);
                        }
                    }
                    if (--*remaining == 0) finish();
                });
            }
        });
    });
}

void WifiManager::finishOperation(const QString &error)
{
    busy_ = false;
    emit message(error.isEmpty() ? tr("Auftrag angenommen. Verbindungsstatus wird aktualisiert …") : tr("WLAN: %1").arg(error));
    emit changed();
    refresh();
}

void WifiManager::enableWifi()
{
    if (busy_) return;
    busy_ = true; emit changed();
    call(root, "org.freedesktop.DBus.Properties", "Set",
         {manager, QString("WirelessEnabled"), QVariant::fromValue(QDBusVariant(true))},
         [this](QVariantList, QString error) { finishOperation(error); });
}

void WifiManager::scan()
{
    if (busy_ || device_.isEmpty()) return;
    busy_ = true; emit changed();
    call(device_, wireless, "RequestScan", {QVariantMap()}, [this](QVariantList, QString error) {
        finishOperation(error);
        QTimer::singleShot(2500, this, &WifiManager::refresh);
    });
}

void WifiManager::disconnectNetwork()
{
    if (busy_ || device_.isEmpty()) return;
    busy_ = true; emit changed();
    call(device_, deviceInterface, "Disconnect", {}, [this](QVariantList, QString error) { finishOperation(error); });
}

void WifiManager::connectNetwork(const WifiNetwork &network, const QString &password)
{
    if (busy_ || device_.isEmpty()) return;
    if (network.security == "unsupported") {
        emit message(tr("Dieses Netzwerk benötigt WEP oder Unternehmens-Anmeldedaten und wird nicht unterstützt.")); return;
    }
    busy_ = true; emit changed();
    // Match saved profiles by SSID, not by their display name or adapter name.
    const QString device = device_;
    properties(device, deviceInterface, [this, network, password, device](QVariantMap p, QString error) {
        if (!error.isEmpty()) { finishOperation(error); return; }
        const auto profiles = qdbus_cast<QList<QDBusObjectPath>>(p.value("AvailableConnections"));
        auto remaining = std::make_shared<int>(profiles.size());
        auto matched = std::make_shared<bool>(false);
        auto activate = [this, network, device](const QString &profile) {
            call(root, manager, "ActivateConnection", {QVariant::fromValue(QDBusObjectPath(profile)),
                 QVariant::fromValue(QDBusObjectPath(device)), QVariant::fromValue(QDBusObjectPath(network.path))},
                 [this](QVariantList, QString error) { finishOperation(error); });
        };
        auto create = [this, network, password, device] {
            if ((network.security == "wpa-psk" || network.security == "sae") && password.isEmpty()) {
                finishOperation(tr("Bitte ein Passwort eingeben.")); return;
            }
            Settings settings;
            settings["connection"] = {{"id", QString::fromUtf8(network.ssid)}, {"uuid", QUuid::createUuid().toString(QUuid::WithoutBraces)},
                                      {"type", "802-11-wireless"}, {"autoconnect", true}};
            settings["802-11-wireless"] = {{"ssid", network.ssid}, {"mode", "infrastructure"}};
            settings["ipv4"] = {{"method", "auto"}};
            settings["ipv6"] = {{"method", "auto"}};
            if (network.security != "open") {
                settings["802-11-wireless-security"] = {{"key-mgmt", network.security}};
                if (network.security != "owe") settings["802-11-wireless-security"]["psk"] = password;
            }
            call(root, manager, "AddAndActivateConnection", {QVariant::fromValue(settings),
                 QVariant::fromValue(QDBusObjectPath(device)), QVariant::fromValue(QDBusObjectPath(network.path))},
                 [this](QVariantList, QString error) { finishOperation(error); });
        };
        if (profiles.isEmpty()) { create(); return; }
        for (const auto &profile : profiles) {
            call(profile.path(), service + ".Settings.Connection", "GetSettings", {},
                 [this, network, password, profile, remaining, matched, activate, create](QVariantList values, QString error) {
                Settings settings;
                if (error.isEmpty() && !values.isEmpty()) settings = qdbus_cast<Settings>(values.first());
                if (!*matched && settings.value("802-11-wireless").value("ssid").toByteArray() == network.ssid) {
                    *matched = true;
                    if (password.isEmpty()) activate(profile.path());
                    else {
                        settings["802-11-wireless-security"]["key-mgmt"] = network.security;
                        settings["802-11-wireless-security"]["psk"] = password;
                        settings["802-11-wireless-security"]["psk-flags"] = uint(0);
                        call(profile.path(), service + ".Settings.Connection", "Update", {QVariant::fromValue(settings)},
                             [this, activate, profile](QVariantList, QString error) {
                            if (error.isEmpty()) activate(profile.path()); else finishOperation(error);
                        });
                    }
                }
                if (--*remaining == 0 && !*matched) create();
            });
        }
    });
}
