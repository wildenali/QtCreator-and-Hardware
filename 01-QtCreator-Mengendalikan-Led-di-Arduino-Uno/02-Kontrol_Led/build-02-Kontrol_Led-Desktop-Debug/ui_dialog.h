/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_Led1;
    QLabel *label_Led2;
    QLabel *label_Led3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QSlider *horizontalSlider_Led1;
    QSlider *horizontalSlider_Led2;
    QSlider *horizontalSlider_Led3;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_Led1_Value;
    QLabel *label_Led2_Value;
    QLabel *label_Led3_Value;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(657, 207);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 101, 131));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_Led1 = new QLabel(layoutWidget);
        label_Led1->setObjectName(QStringLiteral("label_Led1"));
        label_Led1->setLayoutDirection(Qt::LeftToRight);
        label_Led1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_Led1);

        label_Led2 = new QLabel(layoutWidget);
        label_Led2->setObjectName(QStringLiteral("label_Led2"));
        label_Led2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_Led2);

        label_Led3 = new QLabel(layoutWidget);
        label_Led3->setObjectName(QStringLiteral("label_Led3"));
        label_Led3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_Led3);

        layoutWidget1 = new QWidget(Dialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(130, 30, 401, 131));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSlider_Led1 = new QSlider(layoutWidget1);
        horizontalSlider_Led1->setObjectName(QStringLiteral("horizontalSlider_Led1"));
        horizontalSlider_Led1->setEnabled(true);
        horizontalSlider_Led1->setMaximum(255);
        horizontalSlider_Led1->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_Led1);

        horizontalSlider_Led2 = new QSlider(layoutWidget1);
        horizontalSlider_Led2->setObjectName(QStringLiteral("horizontalSlider_Led2"));
        horizontalSlider_Led2->setMaximum(255);
        horizontalSlider_Led2->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_Led2);

        horizontalSlider_Led3 = new QSlider(layoutWidget1);
        horizontalSlider_Led3->setObjectName(QStringLiteral("horizontalSlider_Led3"));
        horizontalSlider_Led3->setMaximum(255);
        horizontalSlider_Led3->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_Led3);

        layoutWidget2 = new QWidget(Dialog);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(550, 30, 91, 131));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_Led1_Value = new QLabel(layoutWidget2);
        label_Led1_Value->setObjectName(QStringLiteral("label_Led1_Value"));

        verticalLayout_3->addWidget(label_Led1_Value);

        label_Led2_Value = new QLabel(layoutWidget2);
        label_Led2_Value->setObjectName(QStringLiteral("label_Led2_Value"));

        verticalLayout_3->addWidget(label_Led2_Value);

        label_Led3_Value = new QLabel(layoutWidget2);
        label_Led3_Value->setObjectName(QStringLiteral("label_Led3_Value"));

        verticalLayout_3->addWidget(label_Led3_Value);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        label_Led1->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:20pt; color:#5500ff;\">Led 1</span></p></body></html>", 0));
        label_Led2->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:20pt; color:#ff0000;\">Led 2</span></p></body></html>", 0));
        label_Led3->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:20pt; color:#55aa00;\">Led 3</span></p></body></html>", 0));
        label_Led1_Value->setText(QApplication::translate("Dialog", "0", 0));
        label_Led2_Value->setText(QApplication::translate("Dialog", "0", 0));
        label_Led3_Value->setText(QApplication::translate("Dialog", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
