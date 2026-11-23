#pragma once

#include <QObject>
#include <QTime>
#include <QDBusConnection>
#include <QDBusMessage>
#include <functional>

class SystemClock : public QObject
{
    Q_OBJECT
public:
    explicit SystemClock(QObject *parent = nullptr,
                         const QDBusConnection &bus = QDBusConnection::systemBus());
    void setTime(QTime time);

signals:
    void finished(bool success, const QString &message);

private:
    QDBusConnection bus_;
    QTime time_;
    bool busy_ = false;
    bool disabledNtp_ = false;
    void call(const QString &interface, const QString &method, const QVariantList &arguments,
              std::function<void(const QDBusMessage &)> done);
    void applyTime();
    void fail(const QString &message);
    void complete(bool success, const QString &message);
};
