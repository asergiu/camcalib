#include "stereocamera.h"

StereoCamera::StereoCamera()
{

}

StereoCamera::StereoCamera(CvSize size)
{
    mS_imageSize =  size;

}

StereoCamera::~StereoCamera(){

    for(int i = 0; i < 2; i++){
        cvReleaseImage(&mImg_images[i]);
        cvReleaseCapture(&mCap_captures[i]);
    }

}

void StereoCamera::capture(){

    mImg_images[0] = cvQueryFrame(mCap_captures[0]);
    mImg_images[1] = cvQueryFrame(mCap_captures[1]);

}

bool StereoCamera::initialize(){

    mCap_captures[0] = cvCaptureFromCAM(CV_CAP_DSHOW + 0);
    mCap_captures[1] = cvCaptureFromCAM(CV_CAP_DSHOW + 1);

    if( mCap_captures[0] && mCap_captures[1]){

        //        for(int i = 0; i < 2; i++){
        //            cvSetCaptureProperty(mCap_captures[i], CV_CAP_PROP_FRAME_WIDTH, mS_imageSize.width);
        //            cvSetCaptureProperty(mCap_captures[i], CV_CAP_PROP_FRAME_HEIGHT, mS_imageSize.height);
        //        }

        return true;
    }

    return false;

}

IplImage* StereoCamera::getFrame(int cameraIndex){

    if(!mImg_images[cameraIndex]) return NULL;

    if(mImg_images[cameraIndex]->depth == 1){

        return mImg_images[cameraIndex];

    }else{

        IplImage* gray_image;

        //        gray_image = cvCreateImage(mS_imageSize, IPL_DEPTH_8U, 1);
        gray_image = cvCreateImage(cvSize(mImg_images[cameraIndex]->width, mImg_images[cameraIndex]->height),IPL_DEPTH_8U, 1 );

        cvCvtColor(mImg_images[cameraIndex], gray_image,CV_BGR2GRAY);

        return gray_image;
    }

}

IplImage* StereoCamera::getFrameColor(int cameraIndex){

    if(!mImg_images[cameraIndex]) return NULL;

    return mImg_images[cameraIndex];

}
