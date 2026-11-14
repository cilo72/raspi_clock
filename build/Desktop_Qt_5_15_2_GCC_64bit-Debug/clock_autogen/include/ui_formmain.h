/********************************************************************************
** Form generated from reading UI file 'formmain.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMMAIN_H
#define UI_FORMMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormMain
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelTime;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonSetAlarm;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelAlarmTime;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonSettings;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FormMain)
    {
        if (FormMain->objectName().isEmpty())
            FormMain->setObjectName(QString::fromUtf8("FormMain"));
        FormMain->resize(800, 400);
        verticalLayout = new QVBoxLayout(FormMain);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelTime = new QLabel(FormMain);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelTime->sizePolicy().hasHeightForWidth());
        labelTime->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Liberation Sans"));
        font.setPointSize(180);
        font.setBold(true);
        font.setItalic(false);
        font.setKerning(true);
        labelTime->setFont(font);
        labelTime->setStyleSheet(QString::fromUtf8("color: rgb(230, 225, 201);"));
        labelTime->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelTime);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButtonSetAlarm = new QPushButton(FormMain);
        pushButtonSetAlarm->setObjectName(QString::fromUtf8("pushButtonSetAlarm"));
        pushButtonSetAlarm->setMinimumSize(QSize(100, 100));
        pushButtonSetAlarm->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(99, 69, 44);\n"
"    border-style: outset;\n"
"    border-width: 3px;\n"
"    border-radius: 10px;\n"
"    border-color: rgb(230, 225, 201);\n"
"    padding: 6px;\n"
"	image: url(:/icons/icons/alarm-on-on.svg);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"	border-color: rgb(172, 147,98);\n"
"\n"
"	image: url(:/icons/icons/alarm-on-off.svg);\n"
"}"));
        pushButtonSetAlarm->setCheckable(false);
        pushButtonSetAlarm->setChecked(false);

        horizontalLayout_3->addWidget(pushButtonSetAlarm);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_3, 0, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelAlarmTime = new QLabel(FormMain);
        labelAlarmTime->setObjectName(QString::fromUtf8("labelAlarmTime"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelAlarmTime->sizePolicy().hasHeightForWidth());
        labelAlarmTime->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Liberation Sans"));
        font1.setPointSize(40);
        font1.setBold(true);
        font1.setItalic(false);
        labelAlarmTime->setFont(font1);
        labelAlarmTime->setStyleSheet(QString::fromUtf8("color: rgb(230, 225, 201);"));
        labelAlarmTime->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(labelAlarmTime);


        gridLayout->addLayout(horizontalLayout_4, 0, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButtonSettings = new QPushButton(FormMain);
        pushButtonSettings->setObjectName(QString::fromUtf8("pushButtonSettings"));
        pushButtonSettings->setMinimumSize(QSize(100, 100));
        pushButtonSettings->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(99, 69, 44);\n"
"    border-style: outset;\n"
"    border-width: 3px;\n"
"    border-radius: 10px;\n"
"    border-color: rgb(230, 225, 201);\n"
"    padding: 6px;\n"
"	image: url(:/icons/icons/settings-on.svg);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"	border-color: rgb(172, 147,98);\n"
"\n"
"	image: url(:/icons/icons/settings-off.svg);\n"
"}"));

        horizontalLayout_2->addWidget(pushButtonSettings);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);

        verticalLayout->addLayout(gridLayout);


        retranslateUi(FormMain);

        QMetaObject::connectSlotsByName(FormMain);
    } // setupUi

    void retranslateUi(QWidget *FormMain)
    {
        FormMain->setWindowTitle(QCoreApplication::translate("FormMain", "Form", nullptr));
        labelTime->setText(QCoreApplication::translate("FormMain", "12:23", nullptr));
        pushButtonSetAlarm->setText(QString());
        labelAlarmTime->setText(QCoreApplication::translate("FormMain", "14:44", nullptr));
        pushButtonSettings->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormMain: public Ui_FormMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMMAIN_H
