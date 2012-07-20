#ifndef RTDISPARTITYMAP_H
#define RTDISPARTITYMAP_H

#include<QTimer>

#include "stereocalibration.h"
#include "opencv_headers.h"
#include "stdio.h"

class RTDispartityMap
{
public:
    RTDispartityMap();
    ~RTDispartityMap();

    bool initialize();
    void updateTime();

    void startTimer(QWidget widget);

    void setStereocalibration(StereoCalibration* stereoCalibration);
    void setBMState(CvStereoBMState* bmState);


private:

    CvSize mS_imageSize;

    IplImage* mImg_images[2];
    CvCapture* mCap_captures[2];
    StereoCalibration* stereoCalibration;
    CvMat* mMat_disparity;
    CvStereoBMState* m_BMState;
    QTimer timer;


};

#endif // RTDISPARTITYMAP_H
