#ifndef ADJUSTBMPARAM_H
#define ADJUSTBMPARAM_H

#include <QDialog>
#include "stereocalibration.h"
#include "testcalibrationdialog.h"

namespace Ui {
class AdjustBMParam;
}

class AdjustBMParam : public QDialog
{
    Q_OBJECT
    
public:
    explicit AdjustBMParam(QWidget *parent = 0);
    void setStereoCalibration(StereoCalibration *stereoCalibration);
    void setLeftImage(IplImage* left_image);
    void setRightImage(IplImage* right_image);
    CvStereoBMState* getBMParams();

    ~AdjustBMParam();


public slots:
    virtual void tryParam();
    virtual void updateFilterSize();
    virtual void updateFilterCap();
    virtual void updateSADWinSz();
    virtual void updateTexture();
    virtual void updateSpeckSz();
    virtual void updateSpeckRange();
    virtual void updtaeUniq();
    virtual void  updateMinDisp();
    virtual void updateMaxDisp();
    
private:
    Ui::AdjustBMParam *ui;
    StereoCalibration *stereoCalibration;

    IplImage* rightImage,*leftImage;

};

#endif // ADJUSTBMPARAM_H
