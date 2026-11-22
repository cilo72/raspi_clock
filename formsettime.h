#pragma once

#include <QDialog>

namespace Ui
{
class FormSetTime;
}

class FormSetTime : public QDialog
{
    Q_OBJECT

public:
    explicit FormSetTime(QWidget *parent = nullptr);
    ~FormSetTime();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FormSetTime *ui;
};
