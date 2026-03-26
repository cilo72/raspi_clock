#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , formMain_(new FormMain)
    , formSetAlarmTime_(new FormSetAlarmTime)
    , formSettings_(new FormSettings)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->pageMain);

    ui->pageMain->layout()->addWidget(formMain_);
    ui->pageSetAlarmTime->layout()->addWidget(formSetAlarmTime_);
    ui->pageSettings->layout()->addWidget(formSettings_);

    connect(formMain_, &FormMain::onSetAlarmTimeRequest, this, &MainWindow::onSetAlarmTimeRequest);
    connect(formMain_, &FormMain::onSettingsRequest, this, &MainWindow::onSettingsRequest);

    connect(formSetAlarmTime_, &FormSetAlarmTime::onSetAlarmTimeExit, this, &MainWindow::onSetAlarmTimeExit);
    connect(formSetAlarmTime_, &FormSetAlarmTime::onSetAlarmTimeDone, formMain_, &FormMain::onSetAlarmTimeDone);
    connect(formSetAlarmTime_, &FormSetAlarmTime::onSetAlarmTimeDone, this, &MainWindow::onSetAlarmTimeDone);

    connect(formSettings_, &FormSettings::onSettingsExit, this, &MainWindow::onSettingsExit);
    connect(formSettings_, &FormSettings::onSettingsDone, this, &MainWindow::onSettingsDone);
    connect(formSettings_, &FormSettings::onSettingsDone, formMain_, &FormMain::onSettingsDone);

    connect(formSettings_, &FormSettings::onPlayStart, formMain_, &FormMain::onPlayStart);
    connect(formSettings_, &FormSettings::onPlayStop, formMain_, &FormMain::onPlayStop);
    connect(formSettings_, &FormSettings::onVolumeChanged, formMain_, &FormMain::onVolumeChanged);
}

MainWindow::~MainWindow()
{
    delete formSettings_;
    delete formSetAlarmTime_;
    delete formMain_;
    delete ui;
}

void MainWindow::onSetAlarmTimeRequest()
{
    formSetAlarmTime_->init(formMain_->alarmTime());
    ui->stackedWidget->setCurrentWidget(ui->pageSetAlarmTime);
}

void MainWindow::onSetAlarmTimeExit()
{
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
}

void MainWindow::onSetAlarmTimeDone(QTime newTime)
{
    Q_UNUSED(newTime);
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
}

void MainWindow::onSettingsRequest()
{
    formSettings_->init(formMain_->volume(), formMain_->station());
    ui->stackedWidget->setCurrentWidget(ui->pageSettings);
}

void MainWindow::onSettingsExit()
{
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
}

void MainWindow::onSettingsDone(int volume, QString station)
{
    Q_UNUSED(volume);
    Q_UNUSED(station);
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
}
