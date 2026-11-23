#include "dialogsettings.h"
#include "ui_dialogsettings.h"
#include "music.h"
#include "guihelper.h"
#include "globals.h"
#include "music.h"
#include "dialogsettimeoralarm.h"
#include "systemclock.h"
#include <QApplication>
#include <QMessageBox>
#include <QPushButton>

static const char * styleSheetVolume = R"V0G0N(
QLabel {
    background-color: rgb(99, 69, 44);
    border-style: outset;
    border-width: 0px;
    border-radius: 10px;
    border-color: rgb(230, 225, 201);
padding: 6px;
image: url(:/icons/icons/volume-%1.svg);
}
)V0G0N";

DialogSettings::DialogSettings(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DialogSettings)
    , volume_(80)
{
    ui->setupUi(this);
    volume_ = Globals::volume();
//    ui->labelMusicStatus->setText(directoryProvider_());
    ui->labelMusicStatus->setTextFormat(Qt::PlainText);
    incrementVolume();
    //connect(ui->pushButtonWlan, &QPushButton::clicked, this, &FormSettings::onWifiRequest);

}

DialogSettings::~DialogSettings()
{
    delete ui;
}

void DialogSettings::init(int volume)
{
    ui->pushButtonTest->setChecked(false);
    ui->pushButtonTest->setText(tr("Musik testen"));
    //ui->labelMusicStatus->setText(directoryProvider_());
    volume_ = volume;
    incrementVolume();
}

void DialogSettings::on_pushButtonVolumeDecrement_clicked()
{
    incrementVolume(-10);
}

void DialogSettings::on_pushButtonVolumeIncrement_clicked()
{
    incrementVolume(10);
}

void DialogSettings::incrementVolume(int increment)
{
    volume_+=increment;
    if(volume_ >= 100)
    {
        volume_ = 100;
        ui->pushButtonVolumeIncrement->setEnabled(false);
    }
    else
    {
        ui->pushButtonVolumeIncrement->setEnabled(true);
    }

    if(volume_ <= 0)
    {
        volume_ = 0;
        ui->pushButtonVolumeDecrement->setEnabled(false);
    }
    else
    {
        ui->pushButtonVolumeDecrement->setEnabled(true);
    }

    if(volume_ == 0)
    {
        ui->labelVolume->setStyleSheet(QString(styleSheetVolume).arg(0));
    }
    else if(volume_ <= 33)
    {
        ui->labelVolume->setStyleSheet(QString(styleSheetVolume).arg(1));
    }
    else if(volume_ <= 66)
    {
        ui->labelVolume->setStyleSheet(QString(styleSheetVolume).arg(2));
    }
    else
    {
        ui->labelVolume->setStyleSheet(QString(styleSheetVolume).arg(3));
    }

    if(increment != 0)
    {
        Music::player()->setVolume(volume_);
    }
}

void DialogSettings::on_pushButtonExit_clicked()
{
    Music::player()->stop();
    close();
}

void DialogSettings::on_pushButtonDone_clicked()
{
    Music::player()->stop();
    Globals::setVolume(volume_);
    close();
}

void DialogSettings::on_pushButtonTest_clicked()
{
    if (ui->pushButtonTest->isChecked())
    {
        ui->pushButtonTest->setText(tr("Test stoppen"));
        //ui->labelMusicStatus->setText(directoryProvider_());
        Music::player()->start(volume_);
    }
    else
    {
        ui->pushButtonTest->setText(tr("Musik testen"));
        Music::player()->stop();
    }
}

//void DialogSettings::onPlaybackError(const QString &message)
//{
//    ui->pushButtonTest->setChecked(false);
//    ui->pushButtonTest->setText(tr("Musik testen"));
//    ui->labelMusicStatus->setText(message);
//}

void DialogSettings::on_pushButtonTime_clicked()
{
    auto * dialog = new DialogSetTimeOrAlarm(QTime::currentTime(), this);
    connect(dialog, &DialogSetTimeOrAlarm::timeChanged, this, &DialogSettings::timeChanged );
    GuiHelper::showModal(dialog);
}

void DialogSettings::timeChanged(QTime time)
{
    ui->pushButtonTime->setEnabled(false);
    // Finish the system operation even if the settings window is closed.
    auto *clock = new SystemClock(qApp);
    connect(clock, &SystemClock::finished, clock, &QObject::deleteLater);
    connect(clock, &SystemClock::finished, this, [this](bool success, const QString &message) {
        ui->pushButtonTime->setEnabled(true);
        if (success)
            QMessageBox::information(this, tr("Uhrzeit"), message);
        else
            QMessageBox::warning(this, tr("Uhrzeit"),
                                 message + tr("\nBitte die Berechtigungen für den Zeitdienst prüfen."));
    });
    clock->setTime(time);
}
