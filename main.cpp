#include <QtGui/QApplication>
#include "mainwindow.h"
#include "stereocalibrationform.h"
#include "adjustbmparam.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    StereoCalibrationForm stereoCalibForm;
//    stereoCalibForm.show();

    AdjustBMParam adjustParam;
    adjustParam.show();



    return a.exec();
}
