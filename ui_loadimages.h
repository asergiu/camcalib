/********************************************************************************
** Form generated from reading UI file 'loadimages.ui'
**
** Created: Tue Jun 12 13:33:11 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADIMAGES_H
#define UI_LOADIMAGES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>
#include <QtGui/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_LoadImages
{
public:
    QFormLayout *formLayout_2;
    QPushButton *load;
    QListWidget *imageList;
    QFormLayout *formLayout;
    QToolButton *addImage;
    QToolButton *removeImage;

    void setupUi(QWizardPage *LoadImages)
    {
        if (LoadImages->objectName().isEmpty())
            LoadImages->setObjectName(QString::fromUtf8("LoadImages"));
        LoadImages->resize(400, 300);
        formLayout_2 = new QFormLayout(LoadImages);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        load = new QPushButton(LoadImages);
        load->setObjectName(QString::fromUtf8("load"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, load);

        imageList = new QListWidget(LoadImages);
        imageList->setObjectName(QString::fromUtf8("imageList"));
        imageList->setMaximumSize(QSize(200, 200));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, imageList);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        addImage = new QToolButton(LoadImages);
        addImage->setObjectName(QString::fromUtf8("addImage"));

        formLayout->setWidget(0, QFormLayout::LabelRole, addImage);

        removeImage = new QToolButton(LoadImages);
        removeImage->setObjectName(QString::fromUtf8("removeImage"));

        formLayout->setWidget(0, QFormLayout::FieldRole, removeImage);


        formLayout_2->setLayout(1, QFormLayout::FieldRole, formLayout);


        retranslateUi(LoadImages);

        QMetaObject::connectSlotsByName(LoadImages);
    } // setupUi

    void retranslateUi(QWizardPage *LoadImages)
    {
        LoadImages->setWindowTitle(QApplication::translate("LoadImages", "WizardPage", 0, QApplication::UnicodeUTF8));
        load->setText(QApplication::translate("LoadImages", "Load images", 0, QApplication::UnicodeUTF8));
        addImage->setText(QApplication::translate("LoadImages", "+", 0, QApplication::UnicodeUTF8));
        removeImage->setText(QApplication::translate("LoadImages", " - ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoadImages: public Ui_LoadImages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADIMAGES_H
