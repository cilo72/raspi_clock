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
    void init(int volume, QString station);

signals:
    void onSettingsExit();
    void onSettingsDone(int volume, QString station);
    void onPlayStart(QString url);
    void onPlayStop();
    void onVolumeChanged(int volume);

private slots:
    void on_pushButtonVolumeDecrement_clicked();

    void on_pushButtonVolumeIncrement_clicked();

    void on_pushButtonExit_clicked();

    void on_pushButtonDone_clicked();

    void on_pushButtonFlux80_clicked();

    void on_pushButtonSf3_clicked();

    void on_pushButtonRpMainMix_clicked();

    void on_pushButtonQuit_clicked();

    void on_pushButtonRpMellowMix_clicked();

private:
    Ui::FormSettings *ui;
    int volume_;
    QString station_;
    bool isPlaying_;
    void incrementVolume(int increment = 0);
};
