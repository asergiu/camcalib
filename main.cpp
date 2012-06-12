#include <QtGui/QApplication>
#include "mainwindow.h"
#include "undistort.h"
#include "calibrationwizard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalibrationWizard c;

     Undistort u;
     u.show();


    c.show();
    
    return a.exec();
}
