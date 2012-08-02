#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ui->capture_frames_btn->setEnabled(true);

    camera_ready = false;
    capture_frames = false;
    camera_index = -1;
    sampleTimeout = ui->spinBoxInterval->value()*1000;
    ui->lcdNumber->display(sampleTimeout/1000);
    image_index = 0;

    linuxV4L2Command();
}


MainWindow::~MainWindow()
{
    delete ui;

    //timer.killTimer();

}


void MainWindow::initialize() {
    if(!camera_ready)
        camera_ready = stereoCamera.initialize(this->ui->left_camera_index_spinBox->value(),
                                               this->ui->right_camera_index_spinBox->value(),
                                               this->ui->resolution_width_spinBox->value(),
                                               this->ui->resolution_height_spinBox->value());
}


/*
 *Routine that is connected to the timer in case the cameras capture simultaneously.
 */
void MainWindow::update_time(){

    if(camera_ready == true ){
        stereoCamera.capture();

        IplImage* left_image;
        IplImage* right_image;

        left_image = stereoCamera.getFrameColor(0);
        right_image = stereoCamera.getFrameColor(1);

        cvShowImage("left",left_image);
        cvShowImage("right",right_image);

        if(sampleTimeout < 0) {
            sampleTimeout = ui->spinBoxInterval->value()*1000;
            if(capture_frames) {
                if(camera_index == BOTH_CAMS) {
                    /*Save the captures from both cameras (left and right).*/
                    image_index++;
                    char* left_image_name = new char[100];
                    char* right_image_name = new char[100];

                    sprintf(left_image_name, "left%d.tif", image_index);
                    sprintf(right_image_name, "right%d.tif", image_index);

                    cvSaveImage(left_image_name, left_image);
                    cvSaveImage(right_image_name, right_image);

                    sprintf(left_image_name, "left%d.png", image_index);
                    sprintf(right_image_name, "right%d.png", image_index);

                    cvSaveImage(left_image_name, left_image);
                    cvSaveImage(right_image_name, right_image);

                    delete left_image_name;
                    delete right_image_name;
                }
            }
        } else {
            ui->lcdNumber->display(sampleTimeout/1000);
            sampleTimeout -= timer.interval();
        }
    }

}


/*
 * Routine that is connected to the timer in case the cameras capture alternatively.
 */
void MainWindow::update_time_alternatively() {
    if(camera_ready == true ){
        IplImage* left_image, *right_image;

        if(camera_index == LEFT_CAM) {
            /*Show the left image.*/
            stereoCamera.captureLeft();
            left_image = stereoCamera.getFrameColor(0);
            cvShowImage("left",left_image);
        }  else if(camera_index == RIGHT_CAM) {
            /*Show the right image.*/
            stereoCamera.captureRight();
            right_image = stereoCamera.getFrameColor(1);
            cvShowImage("right",right_image);
        }
        if(sampleTimeout < 0) {
            sampleTimeout = ui->spinBoxInterval->value()*1000;
            if(capture_frames) {
                if(camera_index == LEFT_CAM) {
                    /*Save the capture from the camera in the left handside.*/
                    image_index++;
                    char* left_image_name = new char[100];
                    sprintf(left_image_name, "left%d.tif", image_index);
                    cvSaveImage(left_image_name, left_image);
                    sprintf(left_image_name, "left%d.png", image_index);
                    cvSaveImage(left_image_name, left_image);
                    delete left_image_name;

                    /* Move to the right camera and (re)activate it. */
                    camera_index = RIGHT_CAM;
                    stereoCamera.activateRightCamera(this->ui->right_camera_index_spinBox->value(),
                                                     this->ui->resolution_width_spinBox->value(),
                                                     this->ui->resolution_height_spinBox->value());
                    ui->label_4->setText("RIGHT");
                } else if(camera_index == RIGHT_CAM) {
                    /*Save the capture from the camera in the right handside.*/
                    char* right_image_name = new char[100];
                    sprintf(right_image_name, "right%d.tif", image_index);
                    cvSaveImage(right_image_name, right_image);
                    sprintf(right_image_name, "right%d.png", image_index);
                    cvSaveImage(right_image_name, right_image);
                    delete right_image_name;

                    /* Move to the left camera and (re)activate it. */
                    camera_index = LEFT_CAM;
                    stereoCamera.activateLeftCamera(this->ui->left_camera_index_spinBox->value(),
                                                    this->ui->resolution_width_spinBox->value(),
                                                    this->ui->resolution_height_spinBox->value());
                    ui->label_4->setText("LEFT");
                }
            }
        } else {
            ui->lcdNumber->display(sampleTimeout/1000);
            sampleTimeout -= timer.interval();
        }
    }
}


void MainWindow::startCapture(){
    connect(&timer, SIGNAL(timeout()), this, SLOT(update_time()));

    capture_frames = true;
    camera_index = BOTH_CAMS;
    initialize();
    stereoCamera.capture();
    timer.start(50);

    IplImage* left_image;
    IplImage* right_image;

    left_image = stereoCamera.getFrameColor(0);
    right_image = stereoCamera.getFrameColor(1);

    cvShowImage("left",left_image);
    cvShowImage("right",right_image);

    sampleTimeout = ui->spinBoxInterval->value()*1000;

    /* Disable widgets. */
    ui->capture_frames_btn->setEnabled(false);
    ui->capture_btn->setEnabled(false);
    ui->capture_alternatively_btn->setEnabled(false);
    ui->left_camera_index_spinBox->setEnabled(false);
    ui->right_camera_index_spinBox->setEnabled(false);
    ui->label->setEnabled(false);
    ui->label_3->setEnabled(false);
    ui->resolution_width_spinBox->setEnabled(false);
    ui->resolution_height_spinBox->setEnabled(false);
    ui->width_label->setEnabled(false);
    ui->height_label->setEnabled(false);
}


void MainWindow::captureFrame(){

    IplImage* left_image;
    IplImage* right_image;

    connect(&timer, SIGNAL(timeout()), this, SLOT(update_time()));

    capture_frames = false;
    initialize();
    stereoCamera.capture();
    timer.start(50);

    left_image = stereoCamera.getFrameColor(0);
    right_image = stereoCamera.getFrameColor(1);

    cvShowImage("left",left_image);
    cvShowImage("right",right_image);

    image_index++;

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

    /* Disable widgets. */
    ui->capture_frames_btn->setEnabled(false);
    ui->capture_alternatively_btn->setEnabled(false);
    ui->left_camera_index_spinBox->setEnabled(false);
    ui->right_camera_index_spinBox->setEnabled(false);
    ui->label->setEnabled(false);
    ui->label_3->setEnabled(false);
    ui->resolution_width_spinBox->setEnabled(false);
    ui->resolution_height_spinBox->setEnabled(false);
    ui->width_label->setEnabled(false);
    ui->height_label->setEnabled(false);

    delete left_image_name;
    delete right_image_name;

    delete left_image_name1;
    delete right_image_name1;

    delete left_image_name2;
    delete right_image_name2;
}


/*
 * Routine that captures the images alternatively
 * (first from the left camera and second from the right camera).
 */
void MainWindow::captureFramesAlternatively() {
    connect(&timer, SIGNAL(timeout()), this, SLOT(update_time_alternatively()));

    capture_frames = true;
    camera_index = LEFT_CAM;
    camera_ready = true;

    /* Prepare the two cameras. The left one is activated.
     * The label label_4 indicates what camera is currently capturing.
     */
    stereoCamera.nullifyMCaps();
    stereoCamera.activateLeftCamera(this->ui->left_camera_index_spinBox->value(),
                                    this->ui->resolution_width_spinBox->value(),
                                    this->ui->resolution_height_spinBox->value());
    ui->label_4->setEnabled(true);
    ui->label_4->setText("LEFT");

    timer.start(50);

    sampleTimeout = ui->spinBoxInterval->value()*1000;

    /* Disable widgets. */
    ui->capture_frames_btn->setEnabled(false);
    ui->capture_btn->setEnabled(false);
    ui->capture_alternatively_btn->setEnabled(false);
    ui->left_camera_index_spinBox->setEnabled(false);
    ui->right_camera_index_spinBox->setEnabled(false);
    ui->label->setEnabled(false);
    ui->label_3->setEnabled(false);
    ui->resolution_width_spinBox->setEnabled(false);
    ui->resolution_height_spinBox->setEnabled(false);
    ui->width_label->setEnabled(false);
    ui->height_label->setEnabled(false);
}


/*
 * This routine can be used for obtaining the available resolutions for a certain camera.
 * WARNING: this works just under Linux, provided that V4L2 is installed.
 */
/*void MainWindow::linuxV4L2Command() {
    FILE *fp;
    char resolution[1035];
    char cmd[100];
    sprintf(cmd, "v4l2-ctl --device=/dev/video1 --list-formats-ext | grep -oE '[[:digit:]]{1,4}x[[:digit:]]{1,4}'");
    system(cmd);

    // Open the command for reading.
    fp = popen(cmd, "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        return;
    }

    // Read the output a line at a time - output it.
    while (fgets(resolution, sizeof(resolution)-1, fp) != NULL) {
    }

    // Close
    pclose(fp);
}
*/
