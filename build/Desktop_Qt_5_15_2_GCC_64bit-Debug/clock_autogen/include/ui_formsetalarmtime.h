/********************************************************************************
** Form generated from reading UI file 'formsetalarmtime.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSETALARMTIME_H
#define UI_FORMSETALARMTIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormSetAlarmTime
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageSetTimeButtons;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButtonSetAlarmTime;
    QPushButton *pushButtonAlarmTime3;
    QPushButton *pushButtonAlarmTime2;
    QPushButton *pushButtonAlarmTime1;
    QWidget *pageSetTime;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_4;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_hh_mM;
    QLabel *label_hH_mm;
    QPushButton *pushButton_Hh_mm_plus;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_Hh_mm;
    QLabel *label_hh_Mm;
    QPushButton *pushButton_Hh_mm_minus;
    QPushButton *pushButton_hH_mm_minus;
    QPushButton *pushButton_hh_Mm_minus;
    QPushButton *pushButton_hh_mM_minus;
    QPushButton *pushButton_hH_mm_plus;
    QPushButton *pushButton_hh_Mm_plus;
    QPushButton *pushButton_hh_mM_plus;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButtonExit;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButtonDone;

    void setupUi(QWidget *FormSetAlarmTime)
    {
        if (FormSetAlarmTime->objectName().isEmpty())
            FormSetAlarmTime->setObjectName(QString::fromUtf8("FormSetAlarmTime"));
        FormSetAlarmTime->resize(822, 410);
        FormSetAlarmTime->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(99, 69, 44);\n"
"	color: rgb(230, 225, 201);\n"
"    border-style: outset;\n"
"    border-width: 3px;\n"
"    border-radius: 10px;\n"
"    border-color: rgb(230, 225, 201);\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"	border-color: rgb(172, 147,98);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    border-style: inset;\n"
"	border-color: rgb(230, 225, 201);\n"
"	color: rgb(172, 147,98);\n"
"}\n"
"\n"
"QLabel {\n"
"    background-color: rgb(99, 69, 44);\n"
"	color: rgb(230, 225, 201);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(FormSetAlarmTime);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(FormSetAlarmTime);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        pageSetTimeButtons = new QWidget();
        pageSetTimeButtons->setObjectName(QString::fromUtf8("pageSetTimeButtons"));
        horizontalLayout = new QHBoxLayout(pageSetTimeButtons);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonSetAlarmTime = new QPushButton(pageSetTimeButtons);
        pushButtonSetAlarmTime->setObjectName(QString::fromUtf8("pushButtonSetAlarmTime"));
        QFont font;
        font.setFamily(QString::fromUtf8("Liberation Sans"));
        font.setPointSize(80);
        font.setBold(true);
        font.setItalic(false);
        pushButtonSetAlarmTime->setFont(font);

        gridLayout->addWidget(pushButtonSetAlarmTime, 1, 1, 1, 1);

        pushButtonAlarmTime3 = new QPushButton(pageSetTimeButtons);
        pushButtonAlarmTime3->setObjectName(QString::fromUtf8("pushButtonAlarmTime3"));
        pushButtonAlarmTime3->setFont(font);
        pushButtonAlarmTime3->setStyleSheet(QString::fromUtf8(""));
        pushButtonAlarmTime3->setCheckable(true);
        pushButtonAlarmTime3->setAutoExclusive(true);

        gridLayout->addWidget(pushButtonAlarmTime3, 1, 0, 1, 1);

        pushButtonAlarmTime2 = new QPushButton(pageSetTimeButtons);
        pushButtonAlarmTime2->setObjectName(QString::fromUtf8("pushButtonAlarmTime2"));
        pushButtonAlarmTime2->setMaximumSize(QSize(16777215, 16777215));
        pushButtonAlarmTime2->setFont(font);
        pushButtonAlarmTime2->setCheckable(true);
        pushButtonAlarmTime2->setAutoExclusive(true);

        gridLayout->addWidget(pushButtonAlarmTime2, 0, 1, 1, 1);

        pushButtonAlarmTime1 = new QPushButton(pageSetTimeButtons);
        pushButtonAlarmTime1->setObjectName(QString::fromUtf8("pushButtonAlarmTime1"));
        pushButtonAlarmTime1->setFont(font);
        pushButtonAlarmTime1->setCheckable(true);
        pushButtonAlarmTime1->setChecked(false);
        pushButtonAlarmTime1->setAutoExclusive(true);

        gridLayout->addWidget(pushButtonAlarmTime1, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        stackedWidget->addWidget(pageSetTimeButtons);
        pageSetTime = new QWidget();
        pageSetTime->setObjectName(QString::fromUtf8("pageSetTime"));
        verticalLayout_2 = new QVBoxLayout(pageSetTime);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_6 = new QLabel(pageSetTime);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Liberation Sans"));
        font1.setPointSize(120);
        font1.setBold(true);
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_6, 1, 3, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_8, 1, 6, 1, 1);

        label_hh_mM = new QLabel(pageSetTime);
        label_hh_mM->setObjectName(QString::fromUtf8("label_hh_mM"));
        label_hh_mM->setFont(font1);
        label_hh_mM->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_hh_mM, 1, 5, 1, 1);

        label_hH_mm = new QLabel(pageSetTime);
        label_hH_mm->setObjectName(QString::fromUtf8("label_hH_mm"));
        label_hH_mm->setFont(font1);
        label_hH_mm->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_hH_mm, 1, 2, 1, 1);

        pushButton_Hh_mm_plus = new QPushButton(pageSetTime);
        pushButton_Hh_mm_plus->setObjectName(QString::fromUtf8("pushButton_Hh_mm_plus"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_Hh_mm_plus->sizePolicy().hasHeightForWidth());
        pushButton_Hh_mm_plus->setSizePolicy(sizePolicy);
        pushButton_Hh_mm_plus->setMinimumSize(QSize(100, 0));
        pushButton_Hh_mm_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}"));

        gridLayout_4->addWidget(pushButton_Hh_mm_plus, 0, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_9, 1, 0, 1, 1);

        label_Hh_mm = new QLabel(pageSetTime);
        label_Hh_mm->setObjectName(QString::fromUtf8("label_Hh_mm"));
        label_Hh_mm->setFont(font1);
        label_Hh_mm->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_Hh_mm, 1, 1, 1, 1);

        label_hh_Mm = new QLabel(pageSetTime);
        label_hh_Mm->setObjectName(QString::fromUtf8("label_hh_Mm"));
        label_hh_Mm->setFont(font1);
        label_hh_Mm->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_hh_Mm, 1, 4, 1, 1);

        pushButton_Hh_mm_minus = new QPushButton(pageSetTime);
        pushButton_Hh_mm_minus->setObjectName(QString::fromUtf8("pushButton_Hh_mm_minus"));
        sizePolicy.setHeightForWidth(pushButton_Hh_mm_minus->sizePolicy().hasHeightForWidth());
        pushButton_Hh_mm_minus->setSizePolicy(sizePolicy);
        pushButton_Hh_mm_minus->setMinimumSize(QSize(100, 0));
        pushButton_Hh_mm_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}"));

        gridLayout_4->addWidget(pushButton_Hh_mm_minus, 2, 1, 1, 1);

        pushButton_hH_mm_minus = new QPushButton(pageSetTime);
        pushButton_hH_mm_minus->setObjectName(QString::fromUtf8("pushButton_hH_mm_minus"));
        sizePolicy.setHeightForWidth(pushButton_hH_mm_minus->sizePolicy().hasHeightForWidth());
        pushButton_hH_mm_minus->setSizePolicy(sizePolicy);
        pushButton_hH_mm_minus->setMinimumSize(QSize(100, 0));
        pushButton_hH_mm_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}"));

        gridLayout_4->addWidget(pushButton_hH_mm_minus, 2, 2, 1, 1);

        pushButton_hh_Mm_minus = new QPushButton(pageSetTime);
        pushButton_hh_Mm_minus->setObjectName(QString::fromUtf8("pushButton_hh_Mm_minus"));
        sizePolicy.setHeightForWidth(pushButton_hh_Mm_minus->sizePolicy().hasHeightForWidth());
        pushButton_hh_Mm_minus->setSizePolicy(sizePolicy);
        pushButton_hh_Mm_minus->setMinimumSize(QSize(100, 0));
        pushButton_hh_Mm_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}"));

        gridLayout_4->addWidget(pushButton_hh_Mm_minus, 2, 4, 1, 1);

        pushButton_hh_mM_minus = new QPushButton(pageSetTime);
        pushButton_hh_mM_minus->setObjectName(QString::fromUtf8("pushButton_hh_mM_minus"));
        sizePolicy.setHeightForWidth(pushButton_hh_mM_minus->sizePolicy().hasHeightForWidth());
        pushButton_hh_mM_minus->setSizePolicy(sizePolicy);
        pushButton_hh_mM_minus->setMinimumSize(QSize(100, 0));
        pushButton_hh_mM_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}"));

        gridLayout_4->addWidget(pushButton_hh_mM_minus, 2, 5, 1, 1);

        pushButton_hH_mm_plus = new QPushButton(pageSetTime);
        pushButton_hH_mm_plus->setObjectName(QString::fromUtf8("pushButton_hH_mm_plus"));
        sizePolicy.setHeightForWidth(pushButton_hH_mm_plus->sizePolicy().hasHeightForWidth());
        pushButton_hH_mm_plus->setSizePolicy(sizePolicy);
        pushButton_hH_mm_plus->setMinimumSize(QSize(100, 0));
        pushButton_hH_mm_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}"));

        gridLayout_4->addWidget(pushButton_hH_mm_plus, 0, 2, 1, 1);

        pushButton_hh_Mm_plus = new QPushButton(pageSetTime);
        pushButton_hh_Mm_plus->setObjectName(QString::fromUtf8("pushButton_hh_Mm_plus"));
        sizePolicy.setHeightForWidth(pushButton_hh_Mm_plus->sizePolicy().hasHeightForWidth());
        pushButton_hh_Mm_plus->setSizePolicy(sizePolicy);
        pushButton_hh_Mm_plus->setMinimumSize(QSize(100, 0));
        pushButton_hh_Mm_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}"));

        gridLayout_4->addWidget(pushButton_hh_Mm_plus, 0, 4, 1, 1);

        pushButton_hh_mM_plus = new QPushButton(pageSetTime);
        pushButton_hh_mM_plus->setObjectName(QString::fromUtf8("pushButton_hh_mM_plus"));
        sizePolicy.setHeightForWidth(pushButton_hh_mM_plus->sizePolicy().hasHeightForWidth());
        pushButton_hh_mM_plus->setSizePolicy(sizePolicy);
        pushButton_hh_mM_plus->setMinimumSize(QSize(100, 0));
        pushButton_hh_mM_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}"));

        gridLayout_4->addWidget(pushButton_hh_mM_plus, 0, 5, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        stackedWidget->addWidget(pageSetTime);

        verticalLayout->addWidget(stackedWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButtonExit = new QPushButton(FormSetAlarmTime);
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

        horizontalLayout_4->addWidget(pushButtonExit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        pushButtonDone = new QPushButton(FormSetAlarmTime);
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

        horizontalLayout_4->addWidget(pushButtonDone);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(FormSetAlarmTime);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(FormSetAlarmTime);
    } // setupUi

    void retranslateUi(QWidget *FormSetAlarmTime)
    {
        FormSetAlarmTime->setWindowTitle(QCoreApplication::translate("FormSetAlarmTime", "Form", nullptr));
        pushButtonSetAlarmTime->setText(QCoreApplication::translate("FormSetAlarmTime", "...", nullptr));
        pushButtonAlarmTime3->setText(QCoreApplication::translate("FormSetAlarmTime", "07:00", nullptr));
        pushButtonAlarmTime2->setText(QCoreApplication::translate("FormSetAlarmTime", "06:10", nullptr));
        pushButtonAlarmTime1->setText(QCoreApplication::translate("FormSetAlarmTime", "05:50", nullptr));
        label_6->setText(QCoreApplication::translate("FormSetAlarmTime", ":", nullptr));
        label_hh_mM->setText(QCoreApplication::translate("FormSetAlarmTime", "3", nullptr));
        label_hH_mm->setText(QCoreApplication::translate("FormSetAlarmTime", "3", nullptr));
        pushButton_Hh_mm_plus->setText(QString());
        label_Hh_mm->setText(QCoreApplication::translate("FormSetAlarmTime", "3", nullptr));
        label_hh_Mm->setText(QCoreApplication::translate("FormSetAlarmTime", "3", nullptr));
        pushButton_Hh_mm_minus->setText(QString());
        pushButton_hH_mm_minus->setText(QString());
        pushButton_hh_Mm_minus->setText(QString());
        pushButton_hh_mM_minus->setText(QString());
        pushButton_hH_mm_plus->setText(QString());
        pushButton_hh_Mm_plus->setText(QString());
        pushButton_hh_mM_plus->setText(QString());
        pushButtonExit->setText(QString());
        pushButtonDone->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormSetAlarmTime: public Ui_FormSetAlarmTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETALARMTIME_H
