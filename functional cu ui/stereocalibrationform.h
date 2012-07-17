#ifndef STEREOCALIBRATIONFORM_H
#define STEREOCALIBRATIONFORM_H

#include <QDialog>
#include"stereocamera.h"
#include "stereocalibration.h"
#include"stdio.h"

namespace Ui {
class StereoCalibrationForm;
}

class StereoCalibrationForm : public QDialog
{
    Q_OBJECT

public slots:
    virtual void startCalibration();
    virtual void capture();
    virtual void saveCalibrationFile();
    virtual void loadCalibrationFile();
    virtual void undistortImages();
    virtual void calibrateCameras();
    
public:
    explicit StereoCalibrationForm(QWidget *parent = 0);
    ~StereoCalibrationForm();


    
private:
    Ui::StereoCalibrationForm *ui;

    StereoCamera *stereoCamera;
    StereoCalibration *stereoCalibration;
    IplImage* left_image;
    IplImage* right_image;

    int imageIndex;
};

#endif // STEREOCALIBRATIONFORM_H
