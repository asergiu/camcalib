#include "stereocalibrationform.h"
#include "ui_stereocalibrationform.h"



StereoCalibrationForm::StereoCalibrationForm(QWidget *parent, int left_index, int right_index) :
    QDialog(parent),
    ui(new Ui::StereoCalibrationForm)
{

    left_image = 0;
    right_image = 0;
    imageIndex = 0;

    stereoCamera = new StereoCamera();
    stereoCalibration = new StereoCalibration();

    stereoCamera->initialize(left_index, right_index);
    ui->setupUi(this);
}

StereoCalibrationForm::~StereoCalibrationForm()
{

    cvReleaseImage(&left_image);
    cvReleaseImage(&right_image);

    delete ui;
}

void StereoCalibrationForm::startCalibration(){

//    int board_width;
//    int board_height;
//    board_width = this->ui->width->value();
//    board_height = this->ui->width->value();

//    CvSize imageSize;

//    IplImage* sampleImage;
//    stereoCamera->capture();
//    sampleImage = stereoCamera->getFrame(0);
//    imageSize = cvGetSize(sampleImage);
//    cvReleaseImage(&sampleImage);

//    stereoCalibration->initialize(board_width, board_height, imageSize);


}

void StereoCalibrationForm::capture(){


    //    if(this->ui->nImages->value()>imageIndex){
    //        stereoCamera->capture();

    //        left_image = stereoCamera->getFrameColor(0);
    //        right_image = stereoCamera->getFrameColor(1);

    //        imageIndex++;

    //        QString imageNumber = QString("Loading frames %1").arg(imageIndex);
    //        this->ui->imageLog->appendPlainText(imageNumber);

    //        int corners_ok = stereoCalibration->addImages(left_image, right_image);

    //        if(corners_ok==2){
    //            this->ui->imageLog->appendPlainText("corners detected on both frames\n");
    //            stereoCalibration->getInfoFromImages();
    //        }
    //        else{
    //            this->ui->imageLog->appendPlainText("corners not detected on both frames\n");
    //        }

    //    }
    //    else{
    //        this->ui->capture->setEnabled(false);

    //    }

    stereoCamera->capture();

    left_image = stereoCamera->getFrameColor(0);
    right_image = stereoCamera->getFrameColor(1);

    cvShowImage("left",left_image);
    cvShowImage("right",right_image);

    char* image_name_left = new char[20];
    sprintf(image_name_left,"left%d.jpg",imageIndex);

    char* image_name_right = new char[20];
    sprintf(image_name_right,"right%d.jpg",imageIndex);

    cvSaveImage(image_name_left, left_image);
    cvSaveImage(image_name_right, right_image);

    delete image_name_left;
    delete image_name_right;
    imageIndex++;


}

void StereoCalibrationForm::saveCalibrationFile(){

}

void StereoCalibrationForm::loadCalibrationFile(){

}

void StereoCalibrationForm::undistortImages(){

}

void StereoCalibrationForm::calibrateCameras(){

    this->ui->imageLog->appendPlainText("Stereo calibration started ...");

    stereoCalibration->calibrateCameras();

    this->ui->imageLog->appendPlainText("Done\n");


}
