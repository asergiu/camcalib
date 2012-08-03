#include "rtdisparitymapdialog.h"
#include "ui_rtdisparitymapdialog.h"

RTDisparityMapDialog::RTDisparityMapDialog(QWidget *parent, int left_index, int right_index,
                                           int resolution_width, int resolution_height) :
    QDialog(parent),
    ui(new Ui::RTDisparityMapDialog)
{
    ui->setupUi(this);

    for(int i = 0; i <2; i++){
        mImg_images[i] = 0;
        mCap_captures[i] = 0;
    }

    m_stereoCalibration = 0;
    mMat_disparity = 0;
    m_BMState = 0;

    bool camera_ready = initialize(left_index, right_index, resolution_width, resolution_height);
    if(!camera_ready){
        fprintf(stderr, "ERROR: Could not start camera capture!");
        exit(1);
    }

    cvNamedWindow("left image");
    cvNamedWindow("left image");
    cvNamedWindow("disparity");

    QObject::connect(&timer, SIGNAL(timeout()),this, SLOT(update_time()));

    timer.start(this->ui->timer_interval->value());

}

RTDisparityMapDialog::~RTDisparityMapDialog()
{
    delete ui;

    for(int i = 0; i <2; i++){
        cvReleaseImage(&mImg_images[i]);
        cvReleaseCapture(&mCap_captures[i]);
    }

    cvReleaseMat(&mMat_disparity);

    cvDestroyWindow("left image");
    cvDestroyWindow("right image");
    cvDestroyWindow("disparity");

    delete m_stereoCalibration;
}




bool RTDisparityMapDialog::initialize(int left_index, int right_index, int resolution_width, int resolution_height){

    mCap_captures[0] = cvCaptureFromCAM(left_index);
    mCap_captures[1] = cvCaptureFromCAM(right_index);

    if( mCap_captures[0] && mCap_captures[1]){

        printf("%d %d", mSz_imageSize.width, mSz_imageSize.height);
        for(int i = 0; i < 2; i++){
            cvSetCaptureProperty(mCap_captures[i], CV_CAP_PROP_FRAME_WIDTH, resolution_width);
            cvSetCaptureProperty(mCap_captures[i], CV_CAP_PROP_FRAME_HEIGHT, resolution_height);
        }

        return true;
    }

    return false;

}

void RTDisparityMapDialog::update_time(){

    bool ok = true;

    if(!m_stereoCalibration){
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

        IplImage* gray_image_left, *gray_image_right;

        gray_image_left = cvCreateImage(cvSize(mImg_images[0]->width, mImg_images[0]->height),IPL_DEPTH_8U, 1 );

        cvCvtColor(mImg_images[0], gray_image_left,CV_BGR2GRAY);

        gray_image_right = cvCreateImage(cvSize(mImg_images[1]->width, mImg_images[1]->height),IPL_DEPTH_8U, 1 );

        cvCvtColor(mImg_images[1], gray_image_right,CV_BGR2GRAY);

        m_stereoCalibration->computeDisparity(gray_image_left, gray_image_right);
        mMat_disparity = m_stereoCalibration->imageDisparityNormalized;

        cvShowImage("disparity", mMat_disparity);
    }


}

void RTDisparityMapDialog::startTimer(){

    timer.stop();

    timer.start(this->ui->timer_interval->value());
}



void RTDisparityMapDialog::setStereocalibration(StereoCalibration* stereoCalibration){

    this->m_stereoCalibration  = stereoCalibration;

}

void RTDisparityMapDialog::setBMState(CvStereoBMState* bmState){

    this->m_BMState = bmState;

}

void RTDisparityMapDialog::setImageSize(CvSize image_size){
    this->mSz_imageSize = image_size;

}
