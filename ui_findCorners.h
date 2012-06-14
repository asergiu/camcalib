/********************************************************************************
** Form generated from reading UI file 'findCorners.ui'
**
** Created: Thu Jun 14 10:24:19 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDCORNERS_H
#define UI_FINDCORNERS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDialog>
#include <QtGui/QDockWidget>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calibration
{
public:
    QDockWidget *FindCorners;
    QWidget *dockWidgetContents;
    QGraphicsView *graphicsView;
    QCommandLinkButton *commandLinkButton;

    void setupUi(QDialog *Calibration)
    {
        if (Calibration->objectName().isEmpty())
            Calibration->setObjectName(QString::fromUtf8("Calibration"));
        Calibration->resize(527, 391);
        FindCorners = new QDockWidget(Calibration);
        FindCorners->setObjectName(QString::fromUtf8("FindCorners"));
        FindCorners->setGeometry(QRect(180, 30, 280, 278));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        graphicsView = new QGraphicsView(dockWidgetContents);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(9, 9, 256, 192));
        commandLinkButton = new QCommandLinkButton(dockWidgetContents);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(100, 210, 81, 31));
        FindCorners->setWidget(dockWidgetContents);

        retranslateUi(Calibration);

        QMetaObject::connectSlotsByName(Calibration);
    } // setupUi

    void retranslateUi(QDialog *Calibration)
    {
        Calibration->setWindowTitle(QApplication::translate("Calibration", "Dialog", 0, QApplication::UnicodeUTF8));
        commandLinkButton->setText(QApplication::translate("Calibration", "Next", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Calibration: public Ui_Calibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDCORNERS_H
