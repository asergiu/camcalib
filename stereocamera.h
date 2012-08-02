#ifndef STEREOCAMERA_H
#define STEREOCAMERA_H

#include "opencv_headers.h"

class StereoCamera
{
public:
    StereoCamera();
    StereoCamera(CvSize imageSize);
    ~StereoCamera();


    bool initialize(int left_index, int right_index);
    void capture();
    void captureLeft();
    void captureRight();
    void activateLeftCamera(int left_index);
    void activateRightCamera(int right_index);
    IplImage* getFrame(int cameraIndex);
    IplImage* getFrameColor(int cameraIndex);
    void nullifyMCaps();


private:
    CvSize mSz_imageSize;
    IplImage* mImg_images[2];
    CvCapture* mCap_captures[2];
};

#endif // STEREOCAMERA_H
