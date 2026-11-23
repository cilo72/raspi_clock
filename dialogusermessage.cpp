#include "dialogusermessage.h"
#include "ui_dialogusermessage.h"
#include <QIcon>
#include <QStyle>

DialogUserMessage::DialogUserMessage(const QString &title, const QString &message, IconType iconType, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogUserMessage)
{
    ui->setupUi(this);
    ui->labelTitle->setText(title);
    ui->labelMessage->setText(message);

    QIcon icon;
    switch(iconType)
    {
    case IconType::Information:
        icon = style()->standardIcon(QStyle::SP_MessageBoxInformation);
        break;

    case IconType::Warning:
        icon = style()->standardIcon(QStyle::SP_MessageBoxWarning);
        break;
    }

    ui->labelIcon->setPixmap(icon.pixmap(48, 48));

    ui->labelIcon->setAlignment(Qt::AlignCenter);
}

DialogUserMessage::~DialogUserMessage()
{
    delete ui;
}

void DialogUserMessage::on_pushButtonDone_clicked()
{
    close();
}
