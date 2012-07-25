#ifndef TESTCALIBRATIONDIALOG_H
#define TESTCALIBRATIONDIALOG_H

#include <QDialog>

#include "fileutils.h"
#include "stereocalibration.h"
#include "adjustbmparam.h"
#include"stereocamera.h"
#include "rtdisparitymapdialog.h"

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
    StereoCamera* stereoCamera;
    IplImage* left_image;
    IplImage* right_image;
    CvMat* disparity;

private slots:
    void browseImagesPath();
    void loadRightImage();
    void loadLeftImage();
    void startCalib();
    void viewDisparityMap();
};

#endif // TESTCALIBRATIONDIALOG_H
