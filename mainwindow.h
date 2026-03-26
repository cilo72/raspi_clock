#pragma once

#include <QMainWindow>
#include "formmain.h"
#include "formsetalarmtime.h"
#include "formsettings.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSetAlarmTimeRequest();
    void onSetAlarmTimeExit();
    void onSetAlarmTimeDone(QTime newTime);

    void onSettingsRequest();
    void onSettingsExit();
    void onSettingsDone(int volume, QString station);

private:
    Ui::MainWindow *ui;
    FormMain * formMain_;
    FormSetAlarmTime * formSetAlarmTime_;
    FormSettings * formSettings_;
};
