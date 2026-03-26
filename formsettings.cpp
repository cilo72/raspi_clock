#include "formsettings.h"
#include "ui_formsettings.h"
#include "clock.h"

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

FormSettings::FormSettings(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormSettings)
    , volume_(80)
    , isPlaying_(false)
    , station_(Clock::stationRpMainMix())
{
    ui->setupUi(this);
    incrementVolume();
}

FormSettings::~FormSettings()
{
    delete ui;
}

void FormSettings::init(int volume, QString station)
{
    if(station == Clock::stationRpMainMix())
    {
        ui->pushButtonRpMainMix->setChecked(true);
    }
    else if(station == Clock::stationRpMellowMix())
    {
        ui->pushButtonRpMellowMix->setChecked(true);
    }
    else if(station == Clock::stationSf3())
    {
        ui->pushButtonSf3->setChecked(true);
    }
    else if(station == Clock::stationFlux80())
    {
        ui->pushButtonFlux80->setChecked(true);
    }

    volume_ = volume;
    incrementVolume();
}

void FormSettings::on_pushButtonVolumeDecrement_clicked()
{
    incrementVolume(-10);
}

void FormSettings::on_pushButtonVolumeIncrement_clicked()
{
    incrementVolume(10);
}

void FormSettings::incrementVolume(int increment)
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
        emit onVolumeChanged(volume_);
        if(not isPlaying_)
        {
            isPlaying_ = true;

            emit onPlayStart(station_);
        }
    }
}

void FormSettings::on_pushButtonExit_clicked()
{
    emit onPlayStop();
    emit onSettingsExit();
}

void FormSettings::on_pushButtonDone_clicked()
{
    emit onPlayStop();
    emit onSettingsDone(volume_, station_);
}

void FormSettings::on_pushButtonFlux80_clicked()
{
    station_ = Clock::stationFlux80();
    emit onPlayStart(station_);
}

void FormSettings::on_pushButtonSf3_clicked()
{
    station_ = Clock::stationSf3();
    emit onPlayStart(station_);
}

void FormSettings::on_pushButtonRpMainMix_clicked()
{
    station_ = Clock::stationRpMainMix();
    emit onPlayStart(station_);
}

void FormSettings::on_pushButtonQuit_clicked()
{
    QApplication::exit();
}

void FormSettings::on_pushButtonRpMellowMix_clicked()
{
    station_ = Clock::stationRpMellowMix();
    emit onPlayStart(station_);
}
