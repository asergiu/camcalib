/********************************************************************************
** Form generated from reading UI file 'undistort.ui'
**
** Created: Thu Jun 14 13:29:08 2012
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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Undistort
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *camParamLabel;
    QLineEdit *camParam;
    QLabel *imgLabel;
    QLineEdit *img;
    QPushButton *borwseImg;
    QPushButton *browseParam;
    QPushButton *undistort;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Undistort)
    {
        if (Undistort->objectName().isEmpty())
            Undistort->setObjectName(QString::fromUtf8("Undistort"));
        Undistort->resize(473, 344);
        verticalLayout_2 = new QVBoxLayout(Undistort);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        camParamLabel = new QLabel(Undistort);
        camParamLabel->setObjectName(QString::fromUtf8("camParamLabel"));

        gridLayout->addWidget(camParamLabel, 0, 0, 1, 1);

        camParam = new QLineEdit(Undistort);
        camParam->setObjectName(QString::fromUtf8("camParam"));

        gridLayout->addWidget(camParam, 0, 1, 1, 1);

        imgLabel = new QLabel(Undistort);
        imgLabel->setObjectName(QString::fromUtf8("imgLabel"));

        gridLayout->addWidget(imgLabel, 1, 0, 1, 1);

        img = new QLineEdit(Undistort);
        img->setObjectName(QString::fromUtf8("img"));

        gridLayout->addWidget(img, 1, 1, 1, 1);

        borwseImg = new QPushButton(Undistort);
        borwseImg->setObjectName(QString::fromUtf8("borwseImg"));

        gridLayout->addWidget(borwseImg, 1, 2, 1, 1);

        browseParam = new QPushButton(Undistort);
        browseParam->setObjectName(QString::fromUtf8("browseParam"));

        gridLayout->addWidget(browseParam, 0, 2, 1, 1);

        undistort = new QPushButton(Undistort);
        undistort->setObjectName(QString::fromUtf8("undistort"));

        gridLayout->addWidget(undistort, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        retranslateUi(Undistort);

        QMetaObject::connectSlotsByName(Undistort);
    } // setupUi

    void retranslateUi(QDialog *Undistort)
    {
        Undistort->setWindowTitle(QApplication::translate("Undistort", "Dialog", 0, QApplication::UnicodeUTF8));
        camParamLabel->setText(QApplication::translate("Undistort", "Camera parameters", 0, QApplication::UnicodeUTF8));
        imgLabel->setText(QApplication::translate("Undistort", "Initial image", 0, QApplication::UnicodeUTF8));
        borwseImg->setText(QApplication::translate("Undistort", "Load image", 0, QApplication::UnicodeUTF8));
        browseParam->setText(QApplication::translate("Undistort", "Browse", 0, QApplication::UnicodeUTF8));
        undistort->setText(QApplication::translate("Undistort", "Undistort", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Undistort: public Ui_Undistort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNDISTORT_H
