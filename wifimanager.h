#pragma once
#include <QObject>
#include <QVariantMap>
#include <functional>

struct WifiNetwork {
    QString path;
    QByteArray ssid;
    int strength = 0;
    QString security;
};

class WifiManager : public QObject
{
    Q_OBJECT
public:
    explicit WifiManager(QObject *parent = nullptr);
    QList<WifiNetwork> networks() const { return networks_; }
    QString status() const { return status_; }
    int strength() const { return strength_; } // -1: disconnected
    bool busy() const { return busy_; }
    void refresh();
    void scan();
    void enableWifi();
    void connectNetwork(const WifiNetwork &network, const QString &password);
    void disconnectNetwork();
signals:
    void changed();
    void message(QString text);
private:
    void call(const QString &path, const QString &interface, const QString &method,
              const QVariantList &arguments, std::function<void(QVariantList, QString)> done);
    void properties(const QString &path, const QString &interface,
                    std::function<void(QVariantMap, QString)> done);
    void readDevice(const QString &path);
    void finishOperation(const QString &error);
    QString device_, status_ = tr("WLAN wird geprüft …");
    QList<WifiNetwork> networks_;
    int strength_ = -1;
    bool refreshing_ = false, busy_ = false;
};
