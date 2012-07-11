#ifndef STEREOCAMERA_H
#define STEREOCAMERA_H

#include<opencv/cv.h>
#include<opencv/highgui.h>
using namespace cv;

class StereoCamera
{
public:
    StereoCamera();
    StereoCamera(CvSize imageSize);
    ~StereoCamera();


    bool initialize();
    void capture();
    IplImage* getFrame(int cameraIndex);
    IplImage* getFrameColor(int cameraIndex);


private:
    CvSize mS_imageSize;
    IplImage* mImg_images[2];
    CvCapture* mCap_captures[2];
};

#endif // STEREOCAMERA_H
