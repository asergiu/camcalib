/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Jun 15 16:09:35 2012
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
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
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
    QGridLayout *gridLayout_9;
    QMdiArea *mdiArea;
    QWidget *findCorners;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QGraphicsView *imageCorners;
    QPushButton *okBtn;
    QPushButton *notOkBtn;
    QWidget *calibration;
    QGridLayout *gridLayout_4;
    QPushButton *findCornersBtn;
    QPushButton *calibrateCamBtn;
    QPushButton *undistortBtn;
    QSplitter *splitter_2;
    QGroupBox *imagesGB;
    QGridLayout *gridLayout_8;
    QLabel *loadImageLabel;
    QListWidget *imageList;
    QSpacerItem *horizontalSpacer;
    QToolButton *removeImage;
    QPushButton *pushButton;
    QGroupBox *paramInfoGB;
    QGridLayout *gridLayout_3;
    QLabel *widthLabel;
    QLineEdit *width;
    QGraphicsView *smallImg;
    QLabel *heightLabel;
    QLineEdit *height;
    QWidget *calibrationResult;
    QGridLayout *gridLayout_5;
    QFormLayout *formLayout_2;
    QTextBrowser *camParamText;
    QPushButton *saveResult;
    QWidget *undistortsubwindow;
    QGridLayout *gridLayout_6;
    QLabel *camParamLabel;
    QLineEdit *camParamFile;
    QPushButton *browseParam;
    QLabel *label;
    QTextEdit *textEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *imgLabel;
    QLineEdit *undstImgFile;
    QPushButton *borwseImg;
    QPushButton *undistort;
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
        MainWindow->resize(783, 533);
        actionCalibration = new QAction(MainWindow);
        actionCalibration->setObjectName(QString::fromUtf8("actionCalibration"));
        actionUndistortion = new QAction(MainWindow);
        actionUndistortion->setObjectName(QString::fromUtf8("actionUndistortion"));
        actionCalibrate_cameras = new QAction(MainWindow);
        actionCalibrate_cameras->setObjectName(QString::fromUtf8("actionCalibrate_cameras"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_9 = new QGridLayout(centralWidget);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        findCorners = new QWidget();
        findCorners->setObjectName(QString::fromUtf8("findCorners"));
        gridLayout_2 = new QGridLayout(findCorners);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        imageCorners = new QGraphicsView(findCorners);
        imageCorners->setObjectName(QString::fromUtf8("imageCorners"));

        gridLayout->addWidget(imageCorners, 0, 0, 1, 4);

        okBtn = new QPushButton(findCorners);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        gridLayout->addWidget(okBtn, 1, 1, 1, 1);

        notOkBtn = new QPushButton(findCorners);
        notOkBtn->setObjectName(QString::fromUtf8("notOkBtn"));

        gridLayout->addWidget(notOkBtn, 1, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        mdiArea->addSubWindow(findCorners);
        calibration = new QWidget();
        calibration->setObjectName(QString::fromUtf8("calibration"));
        gridLayout_4 = new QGridLayout(calibration);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        findCornersBtn = new QPushButton(calibration);
        findCornersBtn->setObjectName(QString::fromUtf8("findCornersBtn"));

        gridLayout_4->addWidget(findCornersBtn, 0, 1, 1, 1);

        calibrateCamBtn = new QPushButton(calibration);
        calibrateCamBtn->setObjectName(QString::fromUtf8("calibrateCamBtn"));

        gridLayout_4->addWidget(calibrateCamBtn, 1, 1, 1, 1);

        undistortBtn = new QPushButton(calibration);
        undistortBtn->setObjectName(QString::fromUtf8("undistortBtn"));

        gridLayout_4->addWidget(undistortBtn, 2, 1, 1, 1);

        splitter_2 = new QSplitter(calibration);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        imagesGB = new QGroupBox(splitter_2);
        imagesGB->setObjectName(QString::fromUtf8("imagesGB"));
        gridLayout_8 = new QGridLayout(imagesGB);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        loadImageLabel = new QLabel(imagesGB);
        loadImageLabel->setObjectName(QString::fromUtf8("loadImageLabel"));

        gridLayout_8->addWidget(loadImageLabel, 0, 0, 1, 1);

        imageList = new QListWidget(imagesGB);
        imageList->setObjectName(QString::fromUtf8("imageList"));
        imageList->setMinimumSize(QSize(0, 0));
        imageList->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_8->addWidget(imageList, 0, 1, 1, 3);

        horizontalSpacer = new QSpacerItem(155, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer, 1, 0, 1, 2);

        removeImage = new QToolButton(imagesGB);
        removeImage->setObjectName(QString::fromUtf8("removeImage"));

        gridLayout_8->addWidget(removeImage, 1, 2, 1, 1);

        pushButton = new QPushButton(imagesGB);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_8->addWidget(pushButton, 1, 3, 1, 1);

        splitter_2->addWidget(imagesGB);
        paramInfoGB = new QGroupBox(splitter_2);
        paramInfoGB->setObjectName(QString::fromUtf8("paramInfoGB"));
        gridLayout_3 = new QGridLayout(paramInfoGB);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widthLabel = new QLabel(paramInfoGB);
        widthLabel->setObjectName(QString::fromUtf8("widthLabel"));

        gridLayout_3->addWidget(widthLabel, 0, 0, 1, 1);

        width = new QLineEdit(paramInfoGB);
        width->setObjectName(QString::fromUtf8("width"));

        gridLayout_3->addWidget(width, 0, 1, 1, 1);

        smallImg = new QGraphicsView(paramInfoGB);
        smallImg->setObjectName(QString::fromUtf8("smallImg"));
        smallImg->setMaximumSize(QSize(90, 90));

        gridLayout_3->addWidget(smallImg, 0, 2, 2, 1);

        heightLabel = new QLabel(paramInfoGB);
        heightLabel->setObjectName(QString::fromUtf8("heightLabel"));

        gridLayout_3->addWidget(heightLabel, 1, 0, 1, 1);

        height = new QLineEdit(paramInfoGB);
        height->setObjectName(QString::fromUtf8("height"));

        gridLayout_3->addWidget(height, 1, 1, 1, 1);

        splitter_2->addWidget(paramInfoGB);

        gridLayout_4->addWidget(splitter_2, 0, 0, 5, 1);

        mdiArea->addSubWindow(calibration);
        calibrationResult = new QWidget();
        calibrationResult->setObjectName(QString::fromUtf8("calibrationResult"));
        gridLayout_5 = new QGridLayout(calibrationResult);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        camParamText = new QTextBrowser(calibrationResult);
        camParamText->setObjectName(QString::fromUtf8("camParamText"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, camParamText);

        saveResult = new QPushButton(calibrationResult);
        saveResult->setObjectName(QString::fromUtf8("saveResult"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, saveResult);


        gridLayout_5->addLayout(formLayout_2, 0, 0, 1, 1);

        mdiArea->addSubWindow(calibrationResult);
        undistortsubwindow = new QWidget();
        undistortsubwindow->setObjectName(QString::fromUtf8("undistortsubwindow"));
        gridLayout_6 = new QGridLayout(undistortsubwindow);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        camParamLabel = new QLabel(undistortsubwindow);
        camParamLabel->setObjectName(QString::fromUtf8("camParamLabel"));

        gridLayout_6->addWidget(camParamLabel, 0, 0, 1, 1);

        camParamFile = new QLineEdit(undistortsubwindow);
        camParamFile->setObjectName(QString::fromUtf8("camParamFile"));

        gridLayout_6->addWidget(camParamFile, 0, 1, 1, 1);

        browseParam = new QPushButton(undistortsubwindow);
        browseParam->setObjectName(QString::fromUtf8("browseParam"));

        gridLayout_6->addWidget(browseParam, 0, 2, 1, 1);

        label = new QLabel(undistortsubwindow);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_6->addWidget(label, 1, 0, 1, 1);

        textEdit = new QTextEdit(undistortsubwindow);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_6->addWidget(textEdit, 1, 1, 2, 1);

        horizontalSpacer_2 = new QSpacerItem(108, 91, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        label_2 = new QLabel(undistortsubwindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_6->addWidget(label_2, 3, 0, 1, 1);

        lineEdit = new QLineEdit(undistortsubwindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_6->addWidget(lineEdit, 3, 1, 1, 1);

        imgLabel = new QLabel(undistortsubwindow);
        imgLabel->setObjectName(QString::fromUtf8("imgLabel"));

        gridLayout_6->addWidget(imgLabel, 4, 0, 1, 1);

        undstImgFile = new QLineEdit(undistortsubwindow);
        undstImgFile->setObjectName(QString::fromUtf8("undstImgFile"));

        gridLayout_6->addWidget(undstImgFile, 4, 1, 1, 1);

        borwseImg = new QPushButton(undistortsubwindow);
        borwseImg->setObjectName(QString::fromUtf8("borwseImg"));

        gridLayout_6->addWidget(borwseImg, 4, 2, 1, 1);

        undistort = new QPushButton(undistortsubwindow);
        undistort->setObjectName(QString::fromUtf8("undistort"));

        gridLayout_6->addWidget(undistort, 5, 2, 1, 1);

        mdiArea->addSubWindow(undistortsubwindow);

        gridLayout_9->addWidget(mdiArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 783, 21));
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
        QObject::connect(undistort, SIGNAL(clicked()), MainWindow, SLOT(undistort()));
        QObject::connect(borwseImg, SIGNAL(clicked()), MainWindow, SLOT(loadImage()));
        QObject::connect(saveResult, SIGNAL(clicked()), MainWindow, SLOT(saveResults()));
        QObject::connect(browseParam, SIGNAL(clicked()), MainWindow, SLOT(browseParam()));
        QObject::connect(findCornersBtn, SIGNAL(clicked()), MainWindow, SLOT(openFindCornersWnd()));
        QObject::connect(okBtn, SIGNAL(clicked()), MainWindow, SLOT(cornersOk()));
        QObject::connect(notOkBtn, SIGNAL(clicked()), MainWindow, SLOT(cornersNotOk()));
        QObject::connect(removeImage, SIGNAL(clicked()), MainWindow, SLOT(removeImage()));
        QObject::connect(undistortBtn, SIGNAL(clicked()), MainWindow, SLOT(openUndistortionWnd()));
        QObject::connect(calibrateCamBtn, SIGNAL(clicked()), MainWindow, SLOT(calibrate()));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(loadPatternImages()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionCalibration->setText(QApplication::translate("MainWindow", "Calibration", 0, QApplication::UnicodeUTF8));
        actionUndistortion->setText(QApplication::translate("MainWindow", "Undistortion", 0, QApplication::UnicodeUTF8));
        actionCalibrate_cameras->setText(QApplication::translate("MainWindow", "Calibrate cameras", 0, QApplication::UnicodeUTF8));
        findCorners->setWindowTitle(QApplication::translate("MainWindow", "Find corners", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("MainWindow", "ok", 0, QApplication::UnicodeUTF8));
        notOkBtn->setText(QApplication::translate("MainWindow", "not ok", 0, QApplication::UnicodeUTF8));
        calibration->setWindowTitle(QApplication::translate("MainWindow", "Calibration", 0, QApplication::UnicodeUTF8));
        findCornersBtn->setText(QApplication::translate("MainWindow", "Find corners", 0, QApplication::UnicodeUTF8));
        calibrateCamBtn->setText(QApplication::translate("MainWindow", "Calibrate camera", 0, QApplication::UnicodeUTF8));
        undistortBtn->setText(QApplication::translate("MainWindow", "Undistort image", 0, QApplication::UnicodeUTF8));
        imagesGB->setTitle(QApplication::translate("MainWindow", "Images", 0, QApplication::UnicodeUTF8));
        loadImageLabel->setText(QApplication::translate("MainWindow", " Images", 0, QApplication::UnicodeUTF8));
        removeImage->setText(QApplication::translate("MainWindow", " - ", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Load images", 0, QApplication::UnicodeUTF8));
        paramInfoGB->setTitle(QApplication::translate("MainWindow", "Pattern info", 0, QApplication::UnicodeUTF8));
        widthLabel->setText(QApplication::translate("MainWindow", "Board width", 0, QApplication::UnicodeUTF8));
        heightLabel->setText(QApplication::translate("MainWindow", "Board height", 0, QApplication::UnicodeUTF8));
        calibrationResult->setWindowTitle(QApplication::translate("MainWindow", "Calibration results", 0, QApplication::UnicodeUTF8));
        camParamText->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
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
        saveResult->setText(QApplication::translate("MainWindow", "Save results", 0, QApplication::UnicodeUTF8));
        undistortsubwindow->setWindowTitle(QApplication::translate("MainWindow", "Undistortion", 0, QApplication::UnicodeUTF8));
        camParamLabel->setText(QApplication::translate("MainWindow", "Camera parameters", 0, QApplication::UnicodeUTF8));
        browseParam->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Camera intrinsics", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Distortion coefficients", 0, QApplication::UnicodeUTF8));
        imgLabel->setText(QApplication::translate("MainWindow", "Initial image", 0, QApplication::UnicodeUTF8));
        borwseImg->setText(QApplication::translate("MainWindow", "Load image", 0, QApplication::UnicodeUTF8));
        undistort->setText(QApplication::translate("MainWindow", "Undistort", 0, QApplication::UnicodeUTF8));
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
