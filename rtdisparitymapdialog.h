#ifndef RTDISPARITYMAPDIALOG_H
#define RTDISPARITYMAPDIALOG_H

#include <QDialog>
#include <QTimer>
#include "opencv_headers.h"
#include "stereocalibration.h"
#include "stdio.h"

namespace Ui {
class RTDisparityMapDialog;
}

class RTDisparityMapDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RTDisparityMapDialog(QWidget *parent = 0);
    ~RTDisparityMapDialog();

    bool initialize();

    void setStereocalibration(StereoCalibration* m_stereoCalibration);
    void setBMState(CvStereoBMState* bmState);
    void setImageSize(CvSize image_size);

public slots:
    virtual void startTimer();
    virtual void update_time();

private:
    Ui::RTDisparityMapDialog *ui;

    CvSize mSz_imageSize;
    IplImage* mImg_images[2];
    CvCapture* mCap_captures[2];
    StereoCalibration* m_stereoCalibration;
    CvMat* mMat_disparity;
    CvStereoBMState* m_BMState;
    QTimer timer;
};

#endif // RTDISPARITYMAPDIALOG_H
