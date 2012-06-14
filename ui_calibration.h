/********************************************************************************
** Form generated from reading UI file 'calibration.ui'
**
** Created: Wed Jun 13 14:50:01 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATION_H
#define UI_CALIBRATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Calibration
{
public:
    QPushButton *pushButton;
    QListWidget *listWidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Calibration)
    {
        if (Calibration->objectName().isEmpty())
            Calibration->setObjectName(QString::fromUtf8("Calibration"));
        Calibration->resize(400, 375);
        pushButton = new QPushButton(Calibration);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(14, 20, 91, 23));
        listWidget = new QListWidget(Calibration);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(120, 20, 256, 192));
        pushButton_2 = new QPushButton(Calibration);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 300, 101, 23));
        pushButton_3 = new QPushButton(Calibration);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 340, 101, 23));
        label = new QLabel(Calibration);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 240, 71, 16));
        label_2 = new QLabel(Calibration);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 240, 46, 13));

        retranslateUi(Calibration);

        QMetaObject::connectSlotsByName(Calibration);
    } // setupUi

    void retranslateUi(QDialog *Calibration)
    {
        Calibration->setWindowTitle(QApplication::translate("Calibration", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Calibration", "Load images", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Calibration", "Find corners", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Calibration", "Calibrate camera", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Calibration", "Board width", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Calibration", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Calibration: public Ui_Calibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATION_H
