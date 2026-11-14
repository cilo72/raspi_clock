#include "formwifi.h"
#include <QtDBus>
#include <QtTest>
#include <QtWidgets>

using Settings = QMap<QString, QVariantMap>;
Q_DECLARE_METATYPE(Settings)
class NetworkManagerMock : public QDBusVirtualObject {
public:
    QStringList operations;
    bool saved = false;
    QString introspect(const QString &) const override { return {}; }
    bool handleMessage(const QDBusMessage &m, const QDBusConnection &bus) override {
        const QString root = "/org/freedesktop/NetworkManager";
        QVariantList reply;
        auto path = [](QString p) { return QVariant::fromValue(QDBusObjectPath(p)); };
        if (m.member() == "GetDevices") reply << QVariant::fromValue(QList<QDBusObjectPath>{QDBusObjectPath(root + "/Devices/42")});
        else if (m.member() == "GetAll") {
            const QString iface = m.arguments().first().toString();
            QVariantMap p;
            if (iface.endsWith("Device")) p = {{"DeviceType", uint(2)}, {"State", uint(100)}, {"Interface", "test-wifi"},
                {"AvailableConnections", QVariant::fromValue(saved ? QList<QDBusObjectPath>{QDBusObjectPath(root + "/Settings/1")} : QList<QDBusObjectPath>{})}};
            else if (iface.endsWith("Wireless")) p = {{"ActiveAccessPoint", path(root + "/AccessPoint/1")},
                {"AccessPoints", QVariant::fromValue(QList<QDBusObjectPath>{QDBusObjectPath(root + "/AccessPoint/1")})}};
            else p = {{"Ssid", QByteArray("Test: WLAN\\ä")}, {"Strength", uchar(73)}, {"RsnFlags", uint(0x100)}, {"Flags", uint(1)}};
            reply << p;
        } else if (m.member() == "GetSettings") {
            Settings s; s["802-11-wireless"] = {{"ssid", QByteArray("Test: WLAN\\ä")}};
            reply << QVariant::fromValue(s);
        } else {
            operations << m.member();
            if (m.member() == "AddAndActivateConnection") {
                auto s = qdbus_cast<Settings>(m.arguments().first());
                if (s.value("802-11-wireless-security").value("psk").toString() != "secret123!") return false;
                reply << path(root + "/Settings/2") << path(root + "/ActiveConnection/2");
            } else if (m.member() == "ActivateConnection") reply << path(root + "/ActiveConnection/1");
        }
        bus.send(m.createReply(reply)); return true;
    }
};
class WifiTest : public QObject {
    Q_OBJECT
private slots:
    void flow() {
        qDBusRegisterMetaType<Settings>();
        NetworkManagerMock mock;
        auto bus = QDBusConnection::systemBus();
        QVERIFY(bus.registerService("org.freedesktop.NetworkManager"));
        QVERIFY(bus.registerVirtualObject("/org/freedesktop/NetworkManager", &mock, QDBusConnection::SubPath));
        WifiManager manager;
        QSignalSpy messages(&manager, &WifiManager::message);
        QTRY_COMPARE(manager.strength(), 73);
        QCOMPARE(manager.networks().size(), 1);
        QVERIFY(manager.status().contains("73"));
        manager.scan(); QTRY_VERIFY(!manager.busy());
        QVERIFY(mock.operations.contains("RequestScan"));
        manager.connectNetwork(manager.networks().first(), "secret123!");
        QTRY_VERIFY(!manager.busy());
        QVERIFY(mock.operations.contains("AddAndActivateConnection"));
        mock.saved = true;
        manager.connectNetwork(manager.networks().first(), {});
        QTRY_VERIFY(!manager.busy());
        QVERIFY(mock.operations.contains("ActivateConnection"));
        manager.disconnectNetwork(); QTRY_VERIFY(!manager.busy());
        QVERIFY(mock.operations.contains("Disconnect"));
        FormWifi form(&manager);
        form.resize(740, 420); form.show();
        auto list = form.findChild<QListWidget*>();
        QCOMPARE(list->count(), 1); list->setCurrentRow(0);
        for (auto *b : form.findChildren<QPushButton*>()) if (b->text() == "Auswählen") b->click();
        auto input = form.findChild<QLineEdit*>();
        for (auto *b : form.findChildren<QPushButton*>()) if (b->text() == "q") b->click();
        QCOMPARE(input->text(), QString("q"));
        for (auto *b : form.findChildren<QPushButton*>()) if (b->text() == "ABC") b->click();
        for (auto *b : form.findChildren<QPushButton*>()) if (b->text() == "Q") b->click();
        QCOMPARE(input->text(), QString("qQ"));
        QCOMPARE(input->echoMode(), QLineEdit::Password);
        QVERIFY(form.minimumSizeHint().height() <= 420);
        QVERIFY(form.minimumSizeHint().width() <= 740);
        for (auto *b : form.findChildren<QPushButton*>()) if (b->text() == "Zurück") b->click();
        QVERIFY(input->text().isEmpty());
        bus.unregisterObject("/org/freedesktop/NetworkManager", QDBusConnection::UnregisterTree);
        bus.unregisterService("org.freedesktop.NetworkManager");
    }
};
QTEST_MAIN(WifiTest)
#include "wifi_test.moc"
