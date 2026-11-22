#include "formsettime.h"
#include "ui_formsettime.h"

FormSetTime::FormSetTime(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FormSetTime)
{
    ui->setupUi(this);
}

FormSetTime::~FormSetTime()
{
    delete ui;
}

void FormSetTime::on_pushButton_clicked()
{
    close();
}
