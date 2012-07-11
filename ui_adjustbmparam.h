/********************************************************************************
** Form generated from reading UI file 'adjustbmparam.ui'
**
** Created: Wed Jul 11 16:19:13 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADJUSTBMPARAM_H
#define UI_ADJUSTBMPARAM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AdjustBMParam
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QSlider *preFilterSz;
    QLineEdit *pSz;
    QLabel *label_2;
    QSlider *preFilterCap;
    QLineEdit *pCap;
    QLabel *label_3;
    QSlider *SADWndSz;
    QLineEdit *sadSz;
    QLabel *label_4;
    QSlider *textureth;
    QLineEdit *textTh;
    QLabel *label_5;
    QSlider *minDisp;
    QLineEdit *minDisp_2;
    QLabel *label_6;
    QSlider *numDisp;
    QLineEdit *numDisp_2;
    QLabel *label_7;
    QSlider *uniq;
    QLineEdit *uniqRatio;
    QLabel *label_8;
    QSlider *speckleWndSz;
    QLineEdit *spkSz;
    QLabel *label_9;
    QSlider *specklerange;
    QLineEdit *spkRag;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *tryBtn;

    void setupUi(QDialog *AdjustBMParam)
    {
        if (AdjustBMParam->objectName().isEmpty())
            AdjustBMParam->setObjectName(QString::fromUtf8("AdjustBMParam"));
        AdjustBMParam->resize(495, 324);
        verticalLayout = new QVBoxLayout(AdjustBMParam);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(AdjustBMParam);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        preFilterSz = new QSlider(AdjustBMParam);
        preFilterSz->setObjectName(QString::fromUtf8("preFilterSz"));
        preFilterSz->setMinimum(5);
        preFilterSz->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(preFilterSz, 0, 1, 1, 1);

        pSz = new QLineEdit(AdjustBMParam);
        pSz->setObjectName(QString::fromUtf8("pSz"));

        gridLayout->addWidget(pSz, 0, 2, 1, 1);

        label_2 = new QLabel(AdjustBMParam);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        preFilterCap = new QSlider(AdjustBMParam);
        preFilterCap->setObjectName(QString::fromUtf8("preFilterCap"));
        preFilterCap->setMaximum(31);
        preFilterCap->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(preFilterCap, 1, 1, 1, 1);

        pCap = new QLineEdit(AdjustBMParam);
        pCap->setObjectName(QString::fromUtf8("pCap"));

        gridLayout->addWidget(pCap, 1, 2, 1, 1);

        label_3 = new QLabel(AdjustBMParam);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        SADWndSz = new QSlider(AdjustBMParam);
        SADWndSz->setObjectName(QString::fromUtf8("SADWndSz"));
        SADWndSz->setMinimum(5);
        SADWndSz->setMaximum(255);
        SADWndSz->setSingleStep(2);
        SADWndSz->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(SADWndSz, 2, 1, 1, 1);

        sadSz = new QLineEdit(AdjustBMParam);
        sadSz->setObjectName(QString::fromUtf8("sadSz"));

        gridLayout->addWidget(sadSz, 2, 2, 1, 1);

        label_4 = new QLabel(AdjustBMParam);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        textureth = new QSlider(AdjustBMParam);
        textureth->setObjectName(QString::fromUtf8("textureth"));
        textureth->setMaximum(200);
        textureth->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(textureth, 3, 1, 1, 1);

        textTh = new QLineEdit(AdjustBMParam);
        textTh->setObjectName(QString::fromUtf8("textTh"));

        gridLayout->addWidget(textTh, 3, 2, 1, 1);

        label_5 = new QLabel(AdjustBMParam);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        minDisp = new QSlider(AdjustBMParam);
        minDisp->setObjectName(QString::fromUtf8("minDisp"));
        minDisp->setMinimum(-30);
        minDisp->setMaximum(130);
        minDisp->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(minDisp, 4, 1, 1, 1);

        minDisp_2 = new QLineEdit(AdjustBMParam);
        minDisp_2->setObjectName(QString::fromUtf8("minDisp_2"));

        gridLayout->addWidget(minDisp_2, 4, 2, 1, 1);

        label_6 = new QLabel(AdjustBMParam);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        numDisp = new QSlider(AdjustBMParam);
        numDisp->setObjectName(QString::fromUtf8("numDisp"));
        numDisp->setMinimum(1);
        numDisp->setMaximum(20);
        numDisp->setSingleStep(16);
        numDisp->setPageStep(16);
        numDisp->setOrientation(Qt::Horizontal);
        numDisp->setTickPosition(QSlider::NoTicks);
        numDisp->setTickInterval(0);

        gridLayout->addWidget(numDisp, 5, 1, 1, 1);

        numDisp_2 = new QLineEdit(AdjustBMParam);
        numDisp_2->setObjectName(QString::fromUtf8("numDisp_2"));

        gridLayout->addWidget(numDisp_2, 5, 2, 1, 1);

        label_7 = new QLabel(AdjustBMParam);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        uniq = new QSlider(AdjustBMParam);
        uniq->setObjectName(QString::fromUtf8("uniq"));
        uniq->setMaximum(200);
        uniq->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(uniq, 6, 1, 1, 1);

        uniqRatio = new QLineEdit(AdjustBMParam);
        uniqRatio->setObjectName(QString::fromUtf8("uniqRatio"));

        gridLayout->addWidget(uniqRatio, 6, 2, 1, 1);

        label_8 = new QLabel(AdjustBMParam);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        speckleWndSz = new QSlider(AdjustBMParam);
        speckleWndSz->setObjectName(QString::fromUtf8("speckleWndSz"));
        speckleWndSz->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(speckleWndSz, 7, 1, 1, 1);

        spkSz = new QLineEdit(AdjustBMParam);
        spkSz->setObjectName(QString::fromUtf8("spkSz"));

        gridLayout->addWidget(spkSz, 7, 2, 1, 1);

        label_9 = new QLabel(AdjustBMParam);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 8, 0, 1, 1);

        specklerange = new QSlider(AdjustBMParam);
        specklerange->setObjectName(QString::fromUtf8("specklerange"));
        specklerange->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(specklerange, 8, 1, 1, 1);

        spkRag = new QLineEdit(AdjustBMParam);
        spkRag->setObjectName(QString::fromUtf8("spkRag"));

        gridLayout->addWidget(spkRag, 8, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(378, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        tryBtn = new QPushButton(AdjustBMParam);
        tryBtn->setObjectName(QString::fromUtf8("tryBtn"));

        horizontalLayout->addWidget(tryBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AdjustBMParam);
        QObject::connect(tryBtn, SIGNAL(clicked()), AdjustBMParam, SLOT(tryParam()));
        QObject::connect(preFilterSz, SIGNAL(sliderMoved(int)), AdjustBMParam, SLOT(updateFilterSize()));
        QObject::connect(preFilterCap, SIGNAL(sliderMoved(int)), AdjustBMParam, SLOT(updateFilterCap()));
        QObject::connect(SADWndSz, SIGNAL(sliderMoved(int)), AdjustBMParam, SLOT(updateSADWinSz()));
        QObject::connect(textureth, SIGNAL(sliderMoved(int)), AdjustBMParam, SLOT(updateTexture()));
        QObject::connect(minDisp, SIGNAL(sliderMoved(int)), AdjustBMParam, SLOT(updateMinDisp()));
        QObject::connect(numDisp, SIGNAL(sliderMoved(int)), AdjustBMParam, SLOT(updateMaxDisp()));
        QObject::connect(uniq, SIGNAL(sliderMoved(int)), AdjustBMParam, SLOT(updtaeUniq()));
        QObject::connect(speckleWndSz, SIGNAL(sliderMoved(int)), AdjustBMParam, SLOT(updateSpeckSz()));
        QObject::connect(specklerange, SIGNAL(sliderMoved(int)), AdjustBMParam, SLOT(updateSpeckRange()));

        QMetaObject::connectSlotsByName(AdjustBMParam);
    } // setupUi

    void retranslateUi(QDialog *AdjustBMParam)
    {
        AdjustBMParam->setWindowTitle(QApplication::translate("AdjustBMParam", "BM Parameters", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AdjustBMParam", "Pre filter size", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AdjustBMParam", "Pre filter cap", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AdjustBMParam", "SAD wndow size", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AdjustBMParam", "Texture threshold", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AdjustBMParam", "Min. disparity", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AdjustBMParam", "Num.disparities", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AdjustBMParam", "Uniquness ratio", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("AdjustBMParam", "Speckle win size", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("AdjustBMParam", "Speckle range", 0, QApplication::UnicodeUTF8));
        tryBtn->setText(QApplication::translate("AdjustBMParam", "Try", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AdjustBMParam: public Ui_AdjustBMParam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADJUSTBMPARAM_H
