#pragma once

#include <QWidget>

namespace Ui
{
class FormSettings;
}

class FormSettings : public QWidget
{
    Q_OBJECT

public:
    explicit FormSettings(QWidget *parent = nullptr);
    ~FormSettings();
    void init(int volume);

public slots:
    void onPlaybackError(const QString &message);

signals:
    void onWifiRequest();
    void onSettingsExit();
    void onSettingsDone(int volume);
    void onPlayStart(int volume);
    void onPlayStop();
    void onVolumeChanged(int volume);

private slots:
    void on_pushButtonVolumeDecrement_clicked();

    void on_pushButtonVolumeIncrement_clicked();

    void on_pushButtonExit_clicked();

    void on_pushButtonDone_clicked();

    void on_pushButtonTest_clicked();

private:
    Ui::FormSettings *ui;
    int volume_;
    void incrementVolume(int increment = 0);
};
