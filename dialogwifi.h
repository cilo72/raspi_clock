#pragma once
#include <QWidget>
#include "wifimanager.h"
class QLabel;
class QListWidget;
class QLineEdit;
class QPushButton;
class QStackedWidget;
namespace Ui { class DialogWifi; }
class DialogWifi : public QWidget
{
    Q_OBJECT
public:
    explicit DialogWifi(QWidget *parent = nullptr);
    ~DialogWifi();
    void init();
signals:
    void onWifiExit();
private:
    void updateStatus();
    void updateNetworks();
    void selectNetwork();
    Ui::DialogWifi *ui;
    WifiManager *manager_;
    QLabel *status_, *message_, *selected_;
    QListWidget *networks_;
    QLineEdit *password_;
    QPushButton *scan_, *disconnect_, *connect_;
    QStackedWidget *pages_;
    QList<WifiNetwork> displayed_;
    WifiNetwork network_;
};
