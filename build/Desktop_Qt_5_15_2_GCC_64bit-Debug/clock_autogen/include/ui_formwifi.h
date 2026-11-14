/********************************************************************************
** Form generated from reading UI file 'formwifi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMWIFI_H
#define UI_FORMWIFI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormWifi
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *FormWifi)
    {
        if (FormWifi->objectName().isEmpty())
            FormWifi->setObjectName(QString::fromUtf8("FormWifi"));
        FormWifi->resize(740, 420);
        verticalLayout = new QVBoxLayout(FormWifi);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        retranslateUi(FormWifi);

        QMetaObject::connectSlotsByName(FormWifi);
    } // setupUi

    void retranslateUi(QWidget *FormWifi)
    {
        FormWifi->setWindowTitle(QCoreApplication::translate("FormWifi", "WLAN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormWifi: public Ui_FormWifi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMWIFI_H
