#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdio.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()), this, SLOT(update_time()));


    this->ui->pushButtonCalibrate->setEnabled(true);

    //    leftCapture = cvCreateCameraCapture(0);
    //    rightCapture = cvCreateCameraCapture(1);

    camera_ready = stereoCamera.initialize();
    printf("%d", camera_ready);

    stereoCamera.capture();

    IplImage* left_image;
    IplImage* right_image;

    left_image = stereoCamera.getFrameColor(0);
    right_image = stereoCamera.getFrameColor(1);

    cvShowImage("left",left_image);
    cvShowImage("right",right_image);



    sampleTimeout = ui->spinBoxInterval->value()*1000;
    ui->lcdNumber->display(sampleTimeout/1000);
    image_index = 0;

    timer.start(50);


}

MainWindow::~MainWindow()
{
    delete ui;

    //timer.killTimer();

}


void MainWindow::update_time(){

    if(camera_ready == true ){

        stereoCamera.capture();

        IplImage* left_image;
        IplImage* right_image;

        left_image = stereoCamera.getFrameColor(0);
        right_image = stereoCamera.getFrameColor(1);

        cvShowImage("left",left_image);
        cvShowImage("right",right_image);

        if(sampleTimeout < 0){
            //            image_index++;
            //            sampleTimeout = ui->spinBoxInterval->value()*1000;

            //            char* left_image_name = new char[100];
            //            char* right_image_name = new char[100];

            //            sprintf(left_image_name, "left%d.jpg", image_index);
            //            sprintf(right_image_name, "right%d.jpg", image_index);

            //            cvSaveImage(left_image_name, left_image);
            //            cvSaveImage(right_image_name, right_image);

            //            delete left_image_name;
            //            delete right_image_name;


        }else{
            ui->lcdNumber->display(sampleTimeout/1000);
            sampleTimeout -= timer.interval();

        }
    }
}

void MainWindow::startCapture(){

    sampleTimeout = ui->spinBoxInterval->value()*1000;
    ui->pushButtonCalibrate->setEnabled(false);

}

void MainWindow::captureFrame(){

    IplImage* left_image;
    IplImage* right_image;

    left_image = stereoCamera.getFrameColor(0);
    right_image = stereoCamera.getFrameColor(1);


    image_index++;
    sampleTimeout = ui->spinBoxInterval->value()*1000;

    char* left_image_name = new char[100];
    char* right_image_name = new char[100];

    char* left_image_name1 = new char[100];
    char* right_image_name1 = new char[100];


    char* left_image_name2 = new char[100];
    char* right_image_name2 = new char[100];


    sprintf(left_image_name, "left%d.tif", image_index);
    sprintf(right_image_name, "right%d.tif", image_index);

    sprintf(left_image_name1, "left%d.bmp", image_index);
    sprintf(right_image_name1, "right%d.bmp", image_index);

    sprintf(left_image_name2, "left%d.ppm", image_index);
    sprintf(right_image_name2, "right%d.ppm", image_index);


    cvSaveImage(left_image_name, left_image);
    cvSaveImage(right_image_name, right_image);

    cvSaveImage(left_image_name1, left_image);
    cvSaveImage(right_image_name1, right_image);


    cvSaveImage(left_image_name2, left_image);
    cvSaveImage(right_image_name2, right_image);

    delete left_image_name;
    delete right_image_name;

    delete left_image_name1;
    delete right_image_name1;

    delete left_image_name2;
    delete right_image_name2;



}





