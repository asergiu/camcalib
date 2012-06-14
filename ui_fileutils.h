/********************************************************************************
** Form generated from reading UI file 'fileutils.ui'
**
** Created: Thu Jun 14 15:52:21 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEUTILS_H
#define UI_FILEUTILS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileUtils
{
public:

    void setupUi(QWidget *FileUtils)
    {
        if (FileUtils->objectName().isEmpty())
            FileUtils->setObjectName(QString::fromUtf8("FileUtils"));
        FileUtils->resize(400, 300);

        retranslateUi(FileUtils);

        QMetaObject::connectSlotsByName(FileUtils);
    } // setupUi

    void retranslateUi(QWidget *FileUtils)
    {
        FileUtils->setWindowTitle(QApplication::translate("FileUtils", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FileUtils: public Ui_FileUtils {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEUTILS_H
