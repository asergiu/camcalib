#include "rtdispartitymap.h"

RTDispartityMap::RTDispartityMap()
{

    for(int i = 0; i <2; i++){
        mImg_images[i] = 0;
        mCap_captures[i] = 0;
    }

    stereoCalibration = 0;
    mMat_disparity = 0;
    m_BMState = 0;

    bool camera_ready = initialize();
    if(!camera_ready){
        fprintf(stderr, "ERROR: Could not start camera capture!");
        exit(1);
    }

    cvNamedWindow("left image");
    cvNamedWindow("left image");
    cvNamedWindow("disparity");

}

RTDispartityMap::~RTDispartityMap(){

    for(int i = 0; i <2; i++){
        cvReleaseImage(&mImg_images[i]);
        cvReleaseCapture(&mCap_captures[i]);
    }

    cvReleaseMat(&mMat_disparity);

    cvDestroyWindow("left image");
    cvDestroyWindow("right image");
    cvDestroyWindow("disparity");

    delete stereoCalibration;

}


bool RTDispartityMap::initialize(){

    mCap_captures[0] = cvCaptureFromCAM(0);
    mCap_captures[1] = cvCaptureFromCAM(1);

    if( mCap_captures[0] && mCap_captures[1]){

        //TODO image size
        for(int i = 0; i < 2; i++){
            cvSetCaptureProperty(mCap_captures[i], CV_CAP_PROP_FRAME_WIDTH, 320);
            cvSetCaptureProperty(mCap_captures[i], CV_CAP_PROP_FRAME_HEIGHT, 240);
        }

        return true;
    }

    return false;

}

void RTDispartityMap::updateTime(){

    bool ok = true;

    if(!stereoCalibration){
        fprintf(stderr, "ERROR: Calibration is null!");
        ok = false;
    }

    if(!m_BMState){
        fprintf(stderr, "ERROR: Block matching algoritm state is null!");
        ok = false;
    }




    for(int  i = 0; i < 2; i++)
        mImg_images[i] = cvQueryFrame(mCap_captures[i]);

    cvShowImage("left image",mImg_images[0]);
    cvShowImage("right image", mImg_images[1]);

    if(ok){

        stereoCalibration->rectifyImages(mImg_images[0], mImg_images[1], m_BMState);
        mMat_disparity = stereoCalibration->imageDisparityNormalized;

        cvShowImage("disparity", mMat_disparity);
    }


}

void RTDispartityMap::startTimer(QWidget widget){

    QObject::connect(&timer, SIGNAL(timeout()), widget, SLOT(update_time()));

    timer.start(100);
}



void RTDispartityMap::setStereocalibration(StereoCalibration* stereoCalibration){

    this->stereoCalibration  = stereoCalibration;

}

void RTDispartityMap::setBMState(CvStereoBMState* bmState){

    this->m_BMState = bmState;

}


