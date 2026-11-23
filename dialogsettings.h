#pragma once

#include "music.h"
#include <QWidget>

namespace Ui
{
class DialogSettings;
}

class DialogSettings : public QWidget
{
    Q_OBJECT

public:
    explicit DialogSettings(QWidget *parent = nullptr);
    ~DialogSettings();

private slots:
    void on_pushButtonVolumeDecrement_clicked();

    void on_pushButtonVolumeIncrement_clicked();

    void on_pushButtonExit_clicked();

    void on_pushButtonDone_clicked();

    void on_pushButtonTest_clicked();

    void on_pushButtonTime_clicked();

    void timeChanged(QTime time);
    void on_pushButtonWlan_clicked();

private:
    Ui::DialogSettings *ui;
    int volume_;
    void incrementVolume(int increment = 0);
};
