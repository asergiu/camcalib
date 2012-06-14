/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jun 14 12:00:47 2012
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
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCalibration;
    QAction *actionUndistortion;
    QAction *actionCalibrate_cameras;
    QWidget *centralWidget;
    QMdiArea *mdiArea;
    QWidget *findCorners;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QFrame *frame;
    QPushButton *ok;
    QPushButton *notOk;
    QFrame *frame_2;
    QWidget *Calibration;
    QGridLayout *gridLayout_4;
    QSplitter *splitter_2;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QLabel *label;
    QListWidget *listWidget;
    QToolButton *toolButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QGraphicsView *graphicsView_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *calibrationResult;
    QGridLayout *gridLayout_5;
    QFormLayout *formLayout_2;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuCamera_calibration;
    QMenu *menuStereo_calibration;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(602, 518);
        actionCalibration = new QAction(MainWindow);
        actionCalibration->setObjectName(QString::fromUtf8("actionCalibration"));
        actionUndistortion = new QAction(MainWindow);
        actionUndistortion->setObjectName(QString::fromUtf8("actionUndistortion"));
        actionCalibrate_cameras = new QAction(MainWindow);
        actionCalibrate_cameras->setObjectName(QString::fromUtf8("actionCalibrate_cameras"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setGeometry(QRect(-150, 0, 853, 533));
        findCorners = new QWidget();
        findCorners->setObjectName(QString::fromUtf8("findCorners"));
        gridLayout_2 = new QGridLayout(findCorners);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(findCorners);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 4);

        frame = new QFrame(findCorners);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame, 1, 0, 1, 1);

        ok = new QPushButton(findCorners);
        ok->setObjectName(QString::fromUtf8("ok"));

        gridLayout->addWidget(ok, 1, 1, 1, 1);

        notOk = new QPushButton(findCorners);
        notOk->setObjectName(QString::fromUtf8("notOk"));

        gridLayout->addWidget(notOk, 1, 2, 1, 1);

        frame_2 = new QFrame(findCorners);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_2, 1, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        mdiArea->addSubWindow(findCorners);
        Calibration = new QWidget();
        Calibration->setObjectName(QString::fromUtf8("Calibration"));
        gridLayout_4 = new QGridLayout(Calibration);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        splitter_2 = new QSplitter(Calibration);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        groupBox_2 = new QGroupBox(splitter_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        listWidget = new QListWidget(groupBox_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMaximumSize(QSize(200, 200));

        formLayout->setWidget(0, QFormLayout::FieldRole, listWidget);

        toolButton = new QToolButton(groupBox_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        formLayout->setWidget(1, QFormLayout::FieldRole, toolButton);

        splitter_2->addWidget(groupBox_2);
        groupBox = new QGroupBox(splitter_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_3->addWidget(lineEdit, 0, 1, 1, 1);

        graphicsView_2 = new QGraphicsView(groupBox);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setMaximumSize(QSize(90, 90));

        gridLayout_3->addWidget(graphicsView_2, 0, 2, 2, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_3->addWidget(lineEdit_2, 1, 1, 1, 1);

        splitter_2->addWidget(groupBox);

        gridLayout_4->addWidget(splitter_2, 0, 0, 4, 1);

        pushButton = new QPushButton(Calibration);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_4->addWidget(pushButton, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(Calibration);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_4->addWidget(pushButton_2, 1, 1, 1, 1);

        mdiArea->addSubWindow(Calibration);
        calibrationResult = new QWidget();
        calibrationResult->setObjectName(QString::fromUtf8("calibrationResult"));
        gridLayout_5 = new QGridLayout(calibrationResult);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        textBrowser = new QTextBrowser(calibrationResult);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, textBrowser);

        pushButton_3 = new QPushButton(calibrationResult);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pushButton_3);


        gridLayout_5->addLayout(formLayout_2, 0, 0, 1, 1);

        mdiArea->addSubWindow(calibrationResult);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 602, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuCamera_calibration = new QMenu(menuBar);
        menuCamera_calibration->setObjectName(QString::fromUtf8("menuCamera_calibration"));
        menuStereo_calibration = new QMenu(menuBar);
        menuStereo_calibration->setObjectName(QString::fromUtf8("menuStereo_calibration"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuCamera_calibration->menuAction());
        menuBar->addAction(menuStereo_calibration->menuAction());
        menuCamera_calibration->addAction(actionCalibration);
        menuCamera_calibration->addAction(actionUndistortion);
        menuStereo_calibration->addAction(actionCalibrate_cameras);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionCalibration->setText(QApplication::translate("MainWindow", "Calibration", 0, QApplication::UnicodeUTF8));
        actionUndistortion->setText(QApplication::translate("MainWindow", "Undistortion", 0, QApplication::UnicodeUTF8));
        actionCalibrate_cameras->setText(QApplication::translate("MainWindow", "Calibrate cameras", 0, QApplication::UnicodeUTF8));
        findCorners->setWindowTitle(QApplication::translate("MainWindow", "Find corners", 0, QApplication::UnicodeUTF8));
        ok->setText(QApplication::translate("MainWindow", "ok", 0, QApplication::UnicodeUTF8));
        notOk->setText(QApplication::translate("MainWindow", "not ok", 0, QApplication::UnicodeUTF8));
        Calibration->setWindowTitle(QApplication::translate("MainWindow", "Calibration", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Images", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", " Load images", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Pattern info", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Board width", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Board height", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Find corners", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Calibrate camera", 0, QApplication::UnicodeUTF8));
        calibrationResult->setWindowTitle(QApplication::translate("MainWindow", "Calibration results", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Intrinsic coefficients:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">0 0 0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">0 0 0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-"
                        "size:8pt;\">0 0 0</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Distortion coefficients:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">0 0 0 0 0</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Save results", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuCamera_calibration->setTitle(QApplication::translate("MainWindow", "Camera calibration", 0, QApplication::UnicodeUTF8));
        menuStereo_calibration->setTitle(QApplication::translate("MainWindow", "Stereo calibration", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
