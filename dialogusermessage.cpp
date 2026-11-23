#include "dialogusermessage.h"
#include "ui_dialogusermessage.h"

DialogUserMessage::DialogUserMessage(const QString &title, const QString &message, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogUserMessage)
{
    ui->setupUi(this);
    ui->labelTitle->setText(title);
    ui->labelMessage->setText(message);
}

DialogUserMessage::~DialogUserMessage()
{
    delete ui;
}

void DialogUserMessage::on_pushButtonDone_clicked()
{
    close();
}
