#pragma once

#include <QDialog>

namespace Ui
{
class DialogUserMessage;
}

class DialogUserMessage : public QDialog
{
    Q_OBJECT

public:
    enum class IconType
    {
        Information,
        Warning
    };
    explicit DialogUserMessage(const QString &title, const QString &message, IconType iconType, QWidget *parent = nullptr);
    ~DialogUserMessage();

private slots:
    void on_pushButtonDone_clicked();

private:
    Ui::DialogUserMessage *ui;
};
