#include "stereocamera.h"


StereoCamera::StereoCamera()
{
}

StereoCamera::StereoCamera(CvSize size)
{
    mSz_imageSize =  size;

}

StereoCamera::~StereoCamera(){

    for(int i = 0; i < 2; i++){
        cvReleaseImage(&mImg_images[i]);
        if(mCap_captures[i]) {
            cvReleaseCapture(&mCap_captures[i]);
        }
    }

}

void StereoCamera::capture(){

    mImg_images[0] = cvQueryFrame(mCap_captures[0]);
    mImg_images[1] = cvQueryFrame(mCap_captures[1]);

}


/* Routine that queries for the left image only.
 * This is used in case of the alternative capturing where one camera at a time functions.
 */
void StereoCamera::captureLeft() {
    mImg_images[0] = cvQueryFrame(mCap_captures[0]);
}


/* Routine that queries for the right image only.
 * This is used in case of the alternative capturing where one camera at a time functions.
 */
void StereoCamera::captureRight() {
    mImg_images[1] = cvQueryFrame(mCap_captures[1]);
}


/* Routine that activates only the left camera.
 * This is used in case of the alternative capturing where one camera at a time functions.
 */
void StereoCamera::activateLeftCamera(int left_index) {
    /* Release the previously used camera; in this case, the right one. */
    if(mCap_captures[1]) {
        cvReleaseCapture(&mCap_captures[1]);
    }

    /* Activate the left camera and set its properties. */
    mCap_captures[0] = cvCaptureFromCAM(left_index);
    cvSetCaptureProperty(mCap_captures[0], CV_CAP_PROP_FRAME_WIDTH, 320);
    cvSetCaptureProperty(mCap_captures[0], CV_CAP_PROP_FRAME_HEIGHT, 240);
}


/* Routine that activates only the right camera.
 * This is used in case of the alternative capturing where one camera at a time functions.
 */
void StereoCamera::activateRightCamera(int right_index) {
    /* Release the previously used camera; in this case, the left one. */
    if(mCap_captures[0]) {
        cvReleaseCapture(&mCap_captures[0]);
    }

    /* Activate the right camera and set its properties. */
    mCap_captures[1] = cvCaptureFromCAM(right_index);
    cvSetCaptureProperty(mCap_captures[1], CV_CAP_PROP_FRAME_WIDTH, 320);
    cvSetCaptureProperty(mCap_captures[1], CV_CAP_PROP_FRAME_HEIGHT, 240);
}


/* Routine that initializes both the left and the right cameras.
 * This is used in case of simultaneous captures of images.
 */
bool StereoCamera::initialize(int left_index, int right_index){

    mCap_captures[0] = cvCaptureFromCAM(left_index);
    mCap_captures[1] = cvCaptureFromCAM(right_index);

    if( mCap_captures[0] && mCap_captures[1]){

                for(int i = 0; i < 2; i++){
                    cvSetCaptureProperty(mCap_captures[i], CV_CAP_PROP_FRAME_WIDTH, 320);
                    cvSetCaptureProperty(mCap_captures[i], CV_CAP_PROP_FRAME_HEIGHT, 240);
                }

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

        gray_image = cvCreateImage(cvSize(mImg_images[cameraIndex]->width, mImg_images[cameraIndex]->height),IPL_DEPTH_8U, 1 );

        cvCvtColor(mImg_images[cameraIndex], gray_image,CV_BGR2GRAY);

        return gray_image;
    }

}

IplImage* StereoCamera::getFrameColor(int cameraIndex){

    if(!mImg_images[cameraIndex]) return NULL;
    return mImg_images[cameraIndex];

}


/*
 * Nullify the reference to the two cameras.
 */
void StereoCamera::nullifyMCaps() {
    mCap_captures[0] = mCap_captures[1] = NULL;
}
