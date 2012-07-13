/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Jul 13 23:02:27 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonCalibrate;
    QSpinBox *spinBoxSampleCount;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBoxInterval;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spinBoxCornersX;
    QSpinBox *spinBoxCornersY;
    QLabel *label_5;
    QLineEdit *lineEditFilename;
    QPushButton *pushButtonLoad;
    QPushButton *pushButtonSave;
    QLabel *labelSampleTimeout;
    QLCDNumber *lcdNumber;
    QPushButton *calibrateCaera;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(543, 200);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(200, 200));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButtonCalibrate = new QPushButton(centralWidget);
        pushButtonCalibrate->setObjectName(QString::fromUtf8("pushButtonCalibrate"));
        pushButtonCalibrate->setEnabled(true);
        pushButtonCalibrate->setGeometry(QRect(420, 30, 101, 31));
        spinBoxSampleCount = new QSpinBox(centralWidget);
        spinBoxSampleCount->setObjectName(QString::fromUtf8("spinBoxSampleCount"));
        spinBoxSampleCount->setGeometry(QRect(130, 10, 46, 20));
        spinBoxSampleCount->setMinimum(3);
        spinBoxSampleCount->setValue(10);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 111, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 141, 31));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2->setWordWrap(true);
        spinBoxInterval = new QSpinBox(centralWidget);
        spinBoxInterval->setObjectName(QString::fromUtf8("spinBoxInterval"));
        spinBoxInterval->setGeometry(QRect(130, 40, 46, 21));
        spinBoxInterval->setMinimum(0);
        spinBoxInterval->setValue(5);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 111, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 100, 111, 20));
        spinBoxCornersX = new QSpinBox(centralWidget);
        spinBoxCornersX->setObjectName(QString::fromUtf8("spinBoxCornersX"));
        spinBoxCornersX->setGeometry(QRect(130, 70, 46, 20));
        spinBoxCornersX->setMinimum(3);
        spinBoxCornersX->setValue(10);
        spinBoxCornersY = new QSpinBox(centralWidget);
        spinBoxCornersY->setObjectName(QString::fromUtf8("spinBoxCornersY"));
        spinBoxCornersY->setGeometry(QRect(130, 100, 46, 20));
        spinBoxCornersY->setMinimum(3);
        spinBoxCornersY->setValue(7);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 130, 111, 20));
        lineEditFilename = new QLineEdit(centralWidget);
        lineEditFilename->setObjectName(QString::fromUtf8("lineEditFilename"));
        lineEditFilename->setGeometry(QRect(130, 130, 251, 20));
        pushButtonLoad = new QPushButton(centralWidget);
        pushButtonLoad->setObjectName(QString::fromUtf8("pushButtonLoad"));
        pushButtonLoad->setEnabled(true);
        pushButtonLoad->setGeometry(QRect(390, 130, 61, 21));
        pushButtonSave = new QPushButton(centralWidget);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));
        pushButtonSave->setEnabled(false);
        pushButtonSave->setGeometry(QRect(460, 130, 61, 21));
        labelSampleTimeout = new QLabel(centralWidget);
        labelSampleTimeout->setObjectName(QString::fromUtf8("labelSampleTimeout"));
        labelSampleTimeout->setGeometry(QRect(210, 10, 121, 20));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(210, 30, 171, 51));
        lcdNumber->setFrameShape(QFrame::Panel);
        lcdNumber->setFrameShadow(QFrame::Raised);
        lcdNumber->setLineWidth(1);
        lcdNumber->setSmallDecimalPoint(true);
        lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        calibrateCaera = new QPushButton(centralWidget);
        calibrateCaera->setObjectName(QString::fromUtf8("calibrateCaera"));
        calibrateCaera->setGeometry(QRect(420, 70, 101, 31));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(pushButtonCalibrate, SIGNAL(clicked()), MainWindow, SLOT(startCapture()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Stereo Calibration", 0, QApplication::UnicodeUTF8));
        pushButtonCalibrate->setText(QApplication::translate("MainWindow", "Capture frames", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Number of images:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Delay between images", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Board width", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Board height", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Calibration File:", 0, QApplication::UnicodeUTF8));
        lineEditFilename->setText(QString());
        pushButtonLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        pushButtonSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        labelSampleTimeout->setText(QApplication::translate("MainWindow", "Time left (in seconds):", 0, QApplication::UnicodeUTF8));
        calibrateCaera->setText(QApplication::translate("MainWindow", "Calibrate cameras", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
