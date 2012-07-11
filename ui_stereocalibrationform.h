/********************************************************************************
** Form generated from reading UI file 'stereocalibrationform.ui'
**
** Created: Wed Jul 11 13:26:39 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEREOCALIBRATIONFORM_H
#define UI_STEREOCALIBRATIONFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StereoCalibrationForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *nImages;
    QLabel *label_2;
    QSpinBox *width;
    QLabel *label_3;
    QSpinBox *height;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *startCalib;
    QPushButton *capture;
    QPushButton *calibrateCam;
    QPushButton *rectifyImage;
    QHBoxLayout *horizontalLayout;
    QLabel *calibLabel;
    QLineEdit *calibFileName;
    QPushButton *loadCalibFile;
    QPushButton *saveCalibFile;
    QPlainTextEdit *imageLog;

    void setupUi(QDialog *StereoCalibrationForm)
    {
        if (StereoCalibrationForm->objectName().isEmpty())
            StereoCalibrationForm->setObjectName(QString::fromUtf8("StereoCalibrationForm"));
        StereoCalibrationForm->resize(476, 368);
        verticalLayout_2 = new QVBoxLayout(StereoCalibrationForm);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(StereoCalibrationForm);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        nImages = new QSpinBox(StereoCalibrationForm);
        nImages->setObjectName(QString::fromUtf8("nImages"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nImages);

        label_2 = new QLabel(StereoCalibrationForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        width = new QSpinBox(StereoCalibrationForm);
        width->setObjectName(QString::fromUtf8("width"));

        formLayout->setWidget(1, QFormLayout::FieldRole, width);

        label_3 = new QLabel(StereoCalibrationForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        height = new QSpinBox(StereoCalibrationForm);
        height->setObjectName(QString::fromUtf8("height"));

        formLayout->setWidget(2, QFormLayout::FieldRole, height);


        horizontalLayout_2->addLayout(formLayout);

        horizontalSpacer = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        startCalib = new QPushButton(StereoCalibrationForm);
        startCalib->setObjectName(QString::fromUtf8("startCalib"));

        verticalLayout->addWidget(startCalib);

        capture = new QPushButton(StereoCalibrationForm);
        capture->setObjectName(QString::fromUtf8("capture"));

        verticalLayout->addWidget(capture);

        calibrateCam = new QPushButton(StereoCalibrationForm);
        calibrateCam->setObjectName(QString::fromUtf8("calibrateCam"));

        verticalLayout->addWidget(calibrateCam);

        rectifyImage = new QPushButton(StereoCalibrationForm);
        rectifyImage->setObjectName(QString::fromUtf8("rectifyImage"));

        verticalLayout->addWidget(rectifyImage);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        calibLabel = new QLabel(StereoCalibrationForm);
        calibLabel->setObjectName(QString::fromUtf8("calibLabel"));

        horizontalLayout->addWidget(calibLabel);

        calibFileName = new QLineEdit(StereoCalibrationForm);
        calibFileName->setObjectName(QString::fromUtf8("calibFileName"));

        horizontalLayout->addWidget(calibFileName);

        loadCalibFile = new QPushButton(StereoCalibrationForm);
        loadCalibFile->setObjectName(QString::fromUtf8("loadCalibFile"));

        horizontalLayout->addWidget(loadCalibFile);

        saveCalibFile = new QPushButton(StereoCalibrationForm);
        saveCalibFile->setObjectName(QString::fromUtf8("saveCalibFile"));
        saveCalibFile->setEnabled(false);

        horizontalLayout->addWidget(saveCalibFile);


        verticalLayout_2->addLayout(horizontalLayout);

        imageLog = new QPlainTextEdit(StereoCalibrationForm);
        imageLog->setObjectName(QString::fromUtf8("imageLog"));

        verticalLayout_2->addWidget(imageLog);


        retranslateUi(StereoCalibrationForm);
        QObject::connect(capture, SIGNAL(clicked()), StereoCalibrationForm, SLOT(capture()));
        QObject::connect(loadCalibFile, SIGNAL(clicked()), StereoCalibrationForm, SLOT(loadCalibrationFile()));
        QObject::connect(saveCalibFile, SIGNAL(clicked()), StereoCalibrationForm, SLOT(saveCalibrationFile()));
        QObject::connect(startCalib, SIGNAL(clicked()), StereoCalibrationForm, SLOT(startCalibration()));
        QObject::connect(calibrateCam, SIGNAL(clicked()), StereoCalibrationForm, SLOT(calibrateCameras()));
        QObject::connect(rectifyImage, SIGNAL(clicked()), StereoCalibrationForm, SLOT(undistortImages()));

        QMetaObject::connectSlotsByName(StereoCalibrationForm);
    } // setupUi

    void retranslateUi(QDialog *StereoCalibrationForm)
    {
        StereoCalibrationForm->setWindowTitle(QApplication::translate("StereoCalibrationForm", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StereoCalibrationForm", "Number of images", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("StereoCalibrationForm", "Pattern width", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("StereoCalibrationForm", "Pattern height", 0, QApplication::UnicodeUTF8));
        startCalib->setText(QApplication::translate("StereoCalibrationForm", "Start calibration", 0, QApplication::UnicodeUTF8));
        capture->setText(QApplication::translate("StereoCalibrationForm", "Capture ", 0, QApplication::UnicodeUTF8));
        calibrateCam->setText(QApplication::translate("StereoCalibrationForm", "Calibrate cameras", 0, QApplication::UnicodeUTF8));
        rectifyImage->setText(QApplication::translate("StereoCalibrationForm", "Rectify images", 0, QApplication::UnicodeUTF8));
        calibLabel->setText(QApplication::translate("StereoCalibrationForm", "Calibration file", 0, QApplication::UnicodeUTF8));
        loadCalibFile->setText(QApplication::translate("StereoCalibrationForm", "Load", 0, QApplication::UnicodeUTF8));
        saveCalibFile->setText(QApplication::translate("StereoCalibrationForm", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StereoCalibrationForm: public Ui_StereoCalibrationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEREOCALIBRATIONFORM_H
