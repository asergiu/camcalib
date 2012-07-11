#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "omp.h"
#include"stdio.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    stereoCamera = new StereoCamera(cvSize(100,200));
    stereoCamera->initialize();

    stereoCalibration = new StereoCalibration();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::capture(){

    stereoCamera->capture();

    IplImage* leftImage = stereoCamera->getFrame(0);
    IplImage* rightImage = stereoCamera->getFrame(1);

    cvNamedWindow("image1");
    cvNamedWindow("image2");

    cvShowImage("image1", leftImage);
    cvShowImage("image2", rightImage);

}

void MainWindow::scaptureForCalibration(){

    stereoCamera->capture();

    IplImage* leftImage = stereoCamera->getFrame(0);
    IplImage* rightImage = stereoCamera->getFrame(1);

    // stereoCalibration->initialize(9, 6, cvSize(leftImage->width, leftImage->height));

    for(int i = 0; i<5; i++){

        printf("iteratia %d", i);

        int ok = stereoCalibration->addImages(leftImage, rightImage);

        if(ok==2){
            stereoCalibration->getInfoFromImages();
        }

        leftImage = stereoCamera->getFrame(0);
        rightImage = stereoCamera->getFrame(1);
    }

    StereoCameraParameters *stereoCameraParameters = stereoCalibration->calibrateCameras();

}

void MainWindow::calibration(){

    int board_width = 9;
    int board_height = 6;

   //  IplImage* sampleImage = cvLoadImage("C:/stereo/left1.jpg",1);
   IplImage* sampleImage = cvLoadImage("C:/imag/left1.jpg",1);

    printf("%d %d", cvGetSize(sampleImage).width,cvGetSize(sampleImage).height);


    stereoCalibration->initialize(board_width, board_height, cvGetSize(sampleImage));

    cvReleaseImage(&sampleImage);

    char* path = new char[100];
//   sprintf(path, "%s", "C:/imag/" );
    sprintf(path, "%s", "C:/stereo/" );

    //  sprintf(path, "%s", "C:/stereoimg/" );

    //    omp_set_num_threads(2);

    //#pragma omp parallel for private(leftImage,rightImage,left_image_name, right_image_name)
    for(int i = 1; i <= 10; i++){

        //        printf("num threads %d \n ", omp_get_num_threads());
        //        printf("iteratia %d thread id %d ", i, omp_get_thread_num());

        char* left_image_name = new char[100];
        char* right_image_name = new char[100];
        char* aux = new char[10];

        IplImage* leftImage;
        IplImage* rightImage;


        strcpy(left_image_name, path);
        strcpy(right_image_name,path);

        strcat(left_image_name, "left");
        strcat(right_image_name,"right");

        sprintf(aux, "%d.jpg", i);

        strcat(left_image_name, aux);
        strcat(right_image_name,aux);

        leftImage = cvLoadImage(left_image_name, 1);
        rightImage = cvLoadImage(right_image_name,1);
        int ok;

        {

            ok = stereoCalibration->addImages(leftImage, rightImage);

            if(ok==2){

                stereoCalibration->getInfoFromImages();

                printf("%d  added\n",i);
            }

        }

        cvReleaseImage(&leftImage);
        cvReleaseImage(&rightImage);
    }

    StereoCameraParameters *param;

    printf("calibrare stereo ...");
    param = stereoCalibration->calibrateCameras();

    stereoCalibration->initRectifyBouguet(param);


        IplImage* leftImage = cvLoadImage("C:/stereo/left5.jpg", 0);
        IplImage* rightImage = cvLoadImage("C:/stereo/right5.jpg", 0);

//    IplImage* leftImage = cvLoadImage("C:/imag/left01.jpg", 0);
//    IplImage* rightImage = cvLoadImage("C:/imag/right01.jpg", 0);

    stereoCalibration->rectifyImages(leftImage, rightImage);

    CvMat* pair = cvCreateMat(leftImage->height, leftImage->width*2, CV_8UC3 );
    CvMat part;


    cvGetCols( pair, &part, 0, leftImage->width );
    cvCvtColor( stereoCalibration->leftImageRectified, &part, CV_GRAY2BGR );

    cvGetCols( pair, &part, leftImage->width,leftImage->width*2 );
    cvCvtColor( stereoCalibration->rightImageRectified, &part, CV_GRAY2BGR);

    for(int j = 0; j < leftImage->height; j += 25 )
        cvLine( pair, cvPoint(0,j),cvPoint(leftImage->width*2,j),CV_RGB(255,0,0));

    cvNamedWindow( "unrectified", 1 );
    cvShowImage( "unrectified", leftImage );

    cvNamedWindow( "rectifiedImg", 1 );
    cvShowImage( "rectifiedImg", stereoCalibration->leftImageRectified );

    cvNamedWindow( "rectified", 1 );
    cvShowImage( "rectified", pair );

    cvNamedWindow( "disaprity", 1 );
    cvShowImage( "disparity", stereoCalibration->imageDisparity);


    cvNamedWindow( "image3D", 1 );
    cvShowImage( "image3D", stereoCalibration->image3D);
    cvWaitKey(0);
    exit(0);

}

