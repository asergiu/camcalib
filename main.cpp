#include <QtGui/QApplication>
#include "mainwindow.h"
#include "stereocalibrationform.h"
#include "adjustbmparam.h"
#include "testcalibrationdialog.h"
#include "tabbedmenudialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

//    TestCalibrationDialog testDialog;
//    testDialog.show();

//    TabbedMenuDialog tabbedMenuDialog;
//    tabbedMenuDialog.show();

    return a.exec();
}
