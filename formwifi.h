#pragma once
#include <QWidget>
#include "wifimanager.h"
class QLabel;
class QListWidget;
class QLineEdit;
class QPushButton;
class QStackedWidget;
namespace Ui { class FormWifi; }
class FormWifi : public QWidget
{
    Q_OBJECT
public:
    explicit FormWifi(WifiManager *manager, QWidget *parent = nullptr);
    ~FormWifi();
    void init();
signals:
    void onWifiExit();
private:
    void updateStatus();
    void updateNetworks();
    void selectNetwork();
    Ui::FormWifi *ui;
    WifiManager *manager_;
    QLabel *status_, *message_, *selected_;
    QListWidget *networks_;
    QLineEdit *password_;
    QPushButton *scan_, *disconnect_, *connect_;
    QStackedWidget *pages_;
    QList<WifiNetwork> displayed_;
    WifiNetwork network_;
};
