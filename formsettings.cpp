#include "formsettings.h"
#include "ui_formsettings.h"
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

FormSettings::FormSettings(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormSettings)
    , volume_(80)
{
    ui->setupUi(this);
    incrementVolume();
    connect(ui->pushButtonWlan, &QPushButton::clicked, this, &FormSettings::onWifiRequest);
}

FormSettings::~FormSettings()
{
    delete ui;
}

void FormSettings::init(int volume)
{
    ui->pushButtonTest->setChecked(false);
    ui->pushButtonTest->setText(tr("Musik testen"));
    ui->labelMusicStatus->setText(tr("MP3-Dateien aus ~/Music"));
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
    }
}

void FormSettings::on_pushButtonExit_clicked()
{
    ui->pushButtonTest->setChecked(false);
    ui->pushButtonTest->setText(tr("Musik testen"));
    emit onPlayStop();
    emit onSettingsExit();
}

void FormSettings::on_pushButtonDone_clicked()
{
    ui->pushButtonTest->setChecked(false);
    ui->pushButtonTest->setText(tr("Musik testen"));
    emit onPlayStop();
    emit onSettingsDone(volume_);
}

void FormSettings::on_pushButtonTest_clicked()
{
    if (ui->pushButtonTest->isChecked())
    {
        ui->pushButtonTest->setText(tr("Test stoppen"));
        ui->labelMusicStatus->setText(tr("MP3-Dateien aus ~/Music"));
        emit onPlayStart(volume_);
    }
    else
    {
        ui->pushButtonTest->setText(tr("Musik testen"));
        emit onPlayStop();
    }
}

void FormSettings::onPlaybackError(const QString &message)
{
    ui->pushButtonTest->setChecked(false);
    ui->pushButtonTest->setText(tr("Musik testen"));
    ui->labelMusicStatus->setText(message);
}
