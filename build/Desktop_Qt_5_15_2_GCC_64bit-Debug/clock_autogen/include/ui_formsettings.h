/********************************************************************************
** Form generated from reading UI file 'formsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSETTINGS_H
#define UI_FORMSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormSettings
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *musicLayout;
    QToolButton *pushButtonTest;
    QLabel *labelMusicStatus;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonVolumeDecrement;
    QLabel *labelVolume;
    QPushButton *pushButtonVolumeIncrement;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonExit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonWlan;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonDone;

    void setupUi(QWidget *FormSettings)
    {
        if (FormSettings->objectName().isEmpty())
            FormSettings->setObjectName(QString::fromUtf8("FormSettings"));
        FormSettings->resize(732, 400);
        FormSettings->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: rgb(99, 69, 44);\n"
"    border-style: outset;\n"
"    border-width: 3px;\n"
"    border-radius: 10px;\n"
"    border-color: rgb(230, 225, 201);\n"
"    padding: 6px;\n"
"   color: rgb(230, 225, 201);\n"
"\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"    border-style: inset;\n"
"	border-color: rgb(172, 147,98);\n"
"}\n"
"\n"
"QToolButton:checked {\n"
"    border-style: inset;\n"
"	border-color: rgb(230, 225, 201);\n"
"	color: rgb(172, 147,98);\n"
"}"));
        verticalLayout = new QVBoxLayout(FormSettings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        musicLayout = new QVBoxLayout();
        musicLayout->setObjectName(QString::fromUtf8("musicLayout"));
        pushButtonTest = new QToolButton(FormSettings);
        pushButtonTest->setObjectName(QString::fromUtf8("pushButtonTest"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonTest->sizePolicy().hasHeightForWidth());
        pushButtonTest->setSizePolicy(sizePolicy);
        pushButtonTest->setMinimumSize(QSize(0, 100));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        pushButtonTest->setFont(font);
        pushButtonTest->setCheckable(true);
        pushButtonTest->setToolButtonStyle(Qt::ToolButtonTextOnly);

        musicLayout->addWidget(pushButtonTest);

        labelMusicStatus = new QLabel(FormSettings);
        labelMusicStatus->setObjectName(QString::fromUtf8("labelMusicStatus"));
        labelMusicStatus->setAlignment(Qt::AlignCenter);
        labelMusicStatus->setWordWrap(true);

        musicLayout->addWidget(labelMusicStatus);


        horizontalLayout->addLayout(musicLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 3, -1, -1);
        pushButtonVolumeDecrement = new QPushButton(FormSettings);
        pushButtonVolumeDecrement->setObjectName(QString::fromUtf8("pushButtonVolumeDecrement"));
        pushButtonVolumeDecrement->setMinimumSize(QSize(0, 75));
        pushButtonVolumeDecrement->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(99, 69, 44);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 10px;\n"
"    border-color: rgb(230, 225, 201);\n"
"    padding: 6px;\n"
"	image: url(:/icons/icons/minus-on.svg);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"	border-color: rgb(172, 147,98);\n"
"\n"
"	image: url(:/icons/icons/minus-off.svg);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    border-style: inset;\n"
"	border-color: rgb(0, 147,98);\n"
"\n"
"	image: url(:/icons/icons/minus-off.svg);\n"
"}"));

        verticalLayout_2->addWidget(pushButtonVolumeDecrement);

        labelVolume = new QLabel(FormSettings);
        labelVolume->setObjectName(QString::fromUtf8("labelVolume"));
        labelVolume->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: rgb(99, 69, 44);\n"
"   border-style: outset;\n"
"   border-width: 0px;\n"
"   border-radius: 10px;\n"
"   border-color: rgb(230, 225, 201);\n"
"   padding: 6px;\n"
"  image: url(:/icons/icons/volume-0.svg);\n"
" }"));
        labelVolume->setScaledContents(false);
        labelVolume->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelVolume);

        pushButtonVolumeIncrement = new QPushButton(FormSettings);
        pushButtonVolumeIncrement->setObjectName(QString::fromUtf8("pushButtonVolumeIncrement"));
        pushButtonVolumeIncrement->setMinimumSize(QSize(0, 75));
        pushButtonVolumeIncrement->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(99, 69, 44);\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 10px;\n"
"    border-color: rgb(230, 225, 201);\n"
"    padding: 6px;\n"
"	image: url(:/icons/icons/plus-on.svg);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"	border-color: rgb(172, 147,98);\n"
"\n"
"	image: url(:/icons/icons/plus-off.svg);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    border-style: inset;\n"
"	border-color: rgb(0, 147,98);\n"
"\n"
"	image: url(:/icons/icons/plus-off.svg);\n"
"}"));

        verticalLayout_2->addWidget(pushButtonVolumeIncrement);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButtonExit = new QPushButton(FormSettings);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));
        pushButtonExit->setMinimumSize(QSize(100, 100));
        pushButtonExit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(99, 69, 44);\n"
"    border-style: outset;\n"
"    border-width: 3px;\n"
"    border-radius: 10px;\n"
"    border-color: rgb(230, 225, 201);\n"
"    padding: 6px;\n"
"	image: url(:/icons/icons/x-icon-on.svg);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"	border-color: rgb(172, 147,98);\n"
"\n"
"	image: url(:/icons/icons/x-icon-off.svg);\n"
"}"));

        horizontalLayout_2->addWidget(pushButtonExit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButtonWlan = new QPushButton(FormSettings);
        pushButtonWlan->setObjectName(QString::fromUtf8("pushButtonWlan"));
        pushButtonWlan->setMinimumSize(QSize(100, 100));
        pushButtonWlan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(99, 69, 44);\n"
"    border-style: outset;\n"
"    border-width: 3px;\n"
"    border-radius: 10px;\n"
"    border-color: rgb(230, 225, 201);\n"
"    padding: 6px;\n"
"	image: url(:/icons/icons/wlan.svg);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"	border-color: rgb(172, 147,98);\n"
"\n"
"	image: url(:/icons/icons/wlan.svg);\n"
"}"));

        horizontalLayout_2->addWidget(pushButtonWlan);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButtonDone = new QPushButton(FormSettings);
        pushButtonDone->setObjectName(QString::fromUtf8("pushButtonDone"));
        pushButtonDone->setMinimumSize(QSize(100, 100));
        pushButtonDone->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(99, 69, 44);\n"
"    border-style: outset;\n"
"    border-width: 3px;\n"
"    border-radius: 10px;\n"
"    border-color: rgb(230, 225, 201);\n"
"    padding: 6px;\n"
"	image: url(:/icons/icons/ok-on.svg);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"	border-color: rgb(172, 147,98);\n"
"\n"
"	image: url(:/icons/icons/ok-off.svg);\n"
"}"));

        horizontalLayout_2->addWidget(pushButtonDone);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(FormSettings);

        QMetaObject::connectSlotsByName(FormSettings);
    } // setupUi

    void retranslateUi(QWidget *FormSettings)
    {
        FormSettings->setWindowTitle(QCoreApplication::translate("FormSettings", "Form", nullptr));
        pushButtonTest->setText(QCoreApplication::translate("FormSettings", "Musik testen", nullptr));
        labelMusicStatus->setText(QCoreApplication::translate("FormSettings", "MP3-Dateien aus ~/Music", nullptr));
        pushButtonVolumeDecrement->setText(QString());
        labelVolume->setText(QString());
        pushButtonVolumeIncrement->setText(QString());
        pushButtonExit->setText(QString());
        pushButtonWlan->setText(QString());
        pushButtonDone->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormSettings: public Ui_FormSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETTINGS_H
