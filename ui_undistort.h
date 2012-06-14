/********************************************************************************
** Form generated from reading UI file 'undistort.ui'
**
** Created: Thu Jun 14 12:00:47 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNDISTORT_H
#define UI_UNDISTORT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Undistort
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QFrame *frame;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Undistort)
    {
        if (Undistort->objectName().isEmpty())
            Undistort->setObjectName(QString::fromUtf8("Undistort"));
        Undistort->resize(473, 344);
        layoutWidget = new QWidget(Undistort);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 317, 103));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 2, 1, 1);

        frame = new QFrame(layoutWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame, 2, 0, 1, 1);

        frame_2 = new QFrame(layoutWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        gridLayout->addWidget(frame_2, 2, 1, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 2, 1, 1);


        retranslateUi(Undistort);

        QMetaObject::connectSlotsByName(Undistort);
    } // setupUi

    void retranslateUi(QDialog *Undistort)
    {
        Undistort->setWindowTitle(QApplication::translate("Undistort", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Undistort", "Camera parameters", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Undistort", "Initial image", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Undistort", "Load image", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Undistort", "Browse", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Undistort", "Undistort", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Undistort: public Ui_Undistort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNDISTORT_H
