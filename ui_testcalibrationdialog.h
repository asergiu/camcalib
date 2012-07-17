/********************************************************************************
** Form generated from reading UI file 'testcalibrationdialog.ui'
**
** Created: Fri Jul 13 23:02:28 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTCALIBRATIONDIALOG_H
#define UI_TESTCALIBRATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TestCalibrationDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QSpinBox *no_imagesSpinBox;
    QLabel *label;
    QLineEdit *images_path;
    QPushButton *browse;
    QLabel *label_3;
    QLineEdit *image_extension;
    QLineEdit *left_image_name;
    QLineEdit *right_image_name;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *load_left;
    QPushButton *load_right;
    QLabel *label_7;
    QSpinBox *board_widthSpinBox;
    QLabel *label_8;
    QSpinBox *board_heightSpinBox;
    QFormLayout *formLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *startCalib;

    void setupUi(QDialog *TestCalibrationDialog)
    {
        if (TestCalibrationDialog->objectName().isEmpty())
            TestCalibrationDialog->setObjectName(QString::fromUtf8("TestCalibrationDialog"));
        TestCalibrationDialog->resize(423, 262);
        verticalLayout = new QVBoxLayout(TestCalibrationDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(TestCalibrationDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        no_imagesSpinBox = new QSpinBox(TestCalibrationDialog);
        no_imagesSpinBox->setObjectName(QString::fromUtf8("no_imagesSpinBox"));
        no_imagesSpinBox->setMinimumSize(QSize(133, 20));
        no_imagesSpinBox->setValue(10);

        gridLayout->addWidget(no_imagesSpinBox, 0, 2, 1, 1);

        label = new QLabel(TestCalibrationDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        images_path = new QLineEdit(TestCalibrationDialog);
        images_path->setObjectName(QString::fromUtf8("images_path"));

        gridLayout->addWidget(images_path, 1, 2, 1, 1);

        browse = new QPushButton(TestCalibrationDialog);
        browse->setObjectName(QString::fromUtf8("browse"));

        gridLayout->addWidget(browse, 1, 3, 1, 1);

        label_3 = new QLabel(TestCalibrationDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        image_extension = new QLineEdit(TestCalibrationDialog);
        image_extension->setObjectName(QString::fromUtf8("image_extension"));

        gridLayout->addWidget(image_extension, 2, 2, 1, 1);

        left_image_name = new QLineEdit(TestCalibrationDialog);
        left_image_name->setObjectName(QString::fromUtf8("left_image_name"));

        gridLayout->addWidget(left_image_name, 3, 2, 1, 1);

        right_image_name = new QLineEdit(TestCalibrationDialog);
        right_image_name->setObjectName(QString::fromUtf8("right_image_name"));

        gridLayout->addWidget(right_image_name, 4, 2, 1, 1);

        label_5 = new QLabel(TestCalibrationDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label_6 = new QLabel(TestCalibrationDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        load_left = new QPushButton(TestCalibrationDialog);
        load_left->setObjectName(QString::fromUtf8("load_left"));

        gridLayout->addWidget(load_left, 3, 3, 1, 1);

        load_right = new QPushButton(TestCalibrationDialog);
        load_right->setObjectName(QString::fromUtf8("load_right"));

        gridLayout->addWidget(load_right, 4, 3, 1, 1);

        label_7 = new QLabel(TestCalibrationDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        board_widthSpinBox = new QSpinBox(TestCalibrationDialog);
        board_widthSpinBox->setObjectName(QString::fromUtf8("board_widthSpinBox"));
        board_widthSpinBox->setValue(9);

        gridLayout->addWidget(board_widthSpinBox, 5, 2, 1, 1);

        label_8 = new QLabel(TestCalibrationDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        board_heightSpinBox = new QSpinBox(TestCalibrationDialog);
        board_heightSpinBox->setObjectName(QString::fromUtf8("board_heightSpinBox"));
        board_heightSpinBox->setValue(6);

        gridLayout->addWidget(board_heightSpinBox, 6, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        horizontalSpacer = new QSpacerItem(208, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(0, QFormLayout::LabelRole, horizontalSpacer);

        startCalib = new QPushButton(TestCalibrationDialog);
        startCalib->setObjectName(QString::fromUtf8("startCalib"));

        formLayout->setWidget(0, QFormLayout::FieldRole, startCalib);


        verticalLayout->addLayout(formLayout);


        retranslateUi(TestCalibrationDialog);
        QObject::connect(browse, SIGNAL(clicked()), TestCalibrationDialog, SLOT(browseImagesPath()));
        QObject::connect(load_left, SIGNAL(clicked()), TestCalibrationDialog, SLOT(loadLeftImage()));
        QObject::connect(load_right, SIGNAL(clicked()), TestCalibrationDialog, SLOT(loadRightImage()));
        QObject::connect(startCalib, SIGNAL(clicked()), TestCalibrationDialog, SLOT(startCalib()));

        QMetaObject::connectSlotsByName(TestCalibrationDialog);
    } // setupUi

    void retranslateUi(QDialog *TestCalibrationDialog)
    {
        TestCalibrationDialog->setWindowTitle(QApplication::translate("TestCalibrationDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TestCalibrationDialog", "Number of images", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TestCalibrationDialog", "Sample images path", 0, QApplication::UnicodeUTF8));
        browse->setText(QApplication::translate("TestCalibrationDialog", "Browse", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TestCalibrationDialog", "Image extension", 0, QApplication::UnicodeUTF8));
        image_extension->setText(QApplication::translate("TestCalibrationDialog", ".jpg", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("TestCalibrationDialog", "Left image", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("TestCalibrationDialog", "Right image", 0, QApplication::UnicodeUTF8));
        load_left->setText(QApplication::translate("TestCalibrationDialog", "Load", 0, QApplication::UnicodeUTF8));
        load_right->setText(QApplication::translate("TestCalibrationDialog", "Load", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("TestCalibrationDialog", "Board width", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("TestCalibrationDialog", "Board height", 0, QApplication::UnicodeUTF8));
        startCalib->setText(QApplication::translate("TestCalibrationDialog", "Start calibration", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TestCalibrationDialog: public Ui_TestCalibrationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTCALIBRATIONDIALOG_H
