#ifndef TESTCALIBRATIONDIALOG_H
#define TESTCALIBRATIONDIALOG_H

#include <QDialog>

#include "fileutils.h"
#include "stereocalibration.h"
#include "adjustbmparam.h"

namespace Ui {
class TestCalibrationDialog;
}

class TestCalibrationDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit TestCalibrationDialog(QWidget *parent = 0);
    ~TestCalibrationDialog();
    
private:
    Ui::TestCalibrationDialog *ui;
    QString imagePath;
    QString imageExtension;
    int numberOfImages;
    QString leftImage;
    QString rightImage;
    StereoCalibration stereoCalibration;




    private slots:
        void browseImagesPath();
    void loadRightImage();
    void loadLeftImage();
    void startCalib();
};

#endif // TESTCALIBRATIONDIALOG_H
