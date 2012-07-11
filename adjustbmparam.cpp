#include "adjustbmparam.h"
#include "ui_adjustbmparam.h"
#include"stdio.h"


AdjustBMParam::AdjustBMParam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdjustBMParam)
{
    ui->setupUi(this);


    stereoCalibration = new StereoCalibration();

    int board_width = 9;
    int board_height = 6;

    IplImage* sampleImage = cvLoadImage("C:/stereo/left1.jpg",1);
//    IplImage* sampleImage = cvLoadImage("C:/imag/left1.jpg",1);
    // IplImage* sampleImage = cvLoadImage("C:/stereo2/left01.ppm",1);
    stereoCalibration->initialize(board_width, board_height, cvGetSize(sampleImage));
    cvReleaseImage(&sampleImage);

    char* path = new char[100];
 //   sprintf(path, "%s", "C:/imag/" );
     sprintf(path, "%s", "C:/stereo/" );
    //  sprintf(path, "%s", "C:/stereo1/" );

    //  sprintf(path, "%s", "C:/stereoimg/" );

    for(int i = 1; i <= 10; i++){

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
        //        if(i<10)
        //            sprintf(aux, "0%d.ppm", i);
        //        else
        //            sprintf(aux, "%d.ppm", i);

        strcat(left_image_name, aux);
        strcat(right_image_name,aux);

        leftImage = cvLoadImage(left_image_name, 1);
        rightImage = cvLoadImage(right_image_name,1);
        int ok;

        ok = stereoCalibration->addImages(leftImage, rightImage);

        if(ok==2){

            stereoCalibration->getInfoFromImages();

            printf("%d  added\n",i);
        }

        cvReleaseImage(&leftImage);
        cvReleaseImage(&rightImage);
    }

    StereoCameraParameters *param;

    printf("calibrare stereo ...");
    param = stereoCalibration->calibrateCameras();

    stereoCalibration->initRectifyBouguet(param);


    //    leftImage = cvLoadImage("C:/stereo2/left16.ppm", 0);
    //    rightImage = cvLoadImage("C:/stereo2/right16.ppm", 0);

    leftImage = cvLoadImage("C:/stereo/left7.jpg", 0);
    rightImage = cvLoadImage("C:/stereo/right7.jpg", 0);


}

AdjustBMParam::~AdjustBMParam()
{
    delete ui;
}

void AdjustBMParam::updateFilterSize(){

    int preFilterSz = this->ui->preFilterSz->value();
    if(preFilterSz%2==0)
        preFilterSz++;

    this->ui->pSz->setText(QString("%1").arg(preFilterSz));



}

void AdjustBMParam::updateFilterCap(){

    int preFilterCap = this->ui->preFilterCap->value();
    this->ui->pCap->setText(QString("%1").arg(preFilterCap));


}

void AdjustBMParam::updateSADWinSz(){

    int sadWndSz = this->ui->SADWndSz->value();

    if(sadWndSz%2==0)
        sadWndSz++;

    this->ui->sadSz->setText(QString("%1").arg(sadWndSz));


}

void AdjustBMParam::updateTexture(){

    int texture = this->ui->textureth->value();
    this->ui->textTh->setText(QString("%1").arg(texture));



}

void AdjustBMParam::updateSpeckSz(){
    int spkWndSz = this->ui->speckleWndSz->value();
    this->ui->spkSz->setText(QString("%1").arg(spkWndSz));



}

void AdjustBMParam::updateSpeckRange(){
    int spkRange = this->ui->specklerange->value();
    this->ui->spkRag->setText(QString("%1").arg(spkRange));


}

void AdjustBMParam::updtaeUniq(){

    int uniquness = this->ui->uniq->value();
    this->ui->uniqRatio->setText(QString("%1").arg(uniquness));



}

void  AdjustBMParam::updateMinDisp(){

    int minDisp = this->ui->minDisp->value();
    this->ui->minDisp_2->setText(QString("%1").arg(minDisp));


}

void AdjustBMParam::updateMaxDisp(){

    int numDisp = 16* this->ui->numDisp->value();
    this->ui->numDisp_2->setText(QString("%1").arg(numDisp));


}

void AdjustBMParam::tryParam(){

    int preFilterSz = this->ui->preFilterSz->value();
    int preFilterCap = this->ui->preFilterCap->value();
    int sadWndSz = this->ui->SADWndSz->value();
    int minDisp = this->ui->minDisp->value();
    int numDisp = 16*(this->ui->numDisp->value());
    int texture = this->ui->textureth->value();
    int uniquness = this->ui->uniq->value();
    int spkWndSz = this->ui->speckleWndSz->value();
    int spkRange = this->ui->specklerange->value();

    if(sadWndSz%2==0)
        sadWndSz++;
    if(sadWndSz<5)
        sadWndSz = 5;

    if(preFilterSz%2==0)
        preFilterSz++;
    if(preFilterSz<5)
        preFilterSz = 5;



    CvStereoBMState *BMState = cvCreateStereoBMState();
    assert(BMState != 0);
    BMState->preFilterSize=preFilterSz;
    BMState->preFilterCap=preFilterCap;
    BMState->SADWindowSize=sadWndSz;
    BMState->minDisparity= minDisp;
    BMState->numberOfDisparities=numDisp;
    BMState->textureThreshold=texture;		//reduce noise
    BMState->uniquenessRatio=uniquness;
    BMState->speckleWindowSize = spkWndSz;
    BMState->speckleRange = spkRange;

    stereoCalibration->rectifyImages(leftImage, rightImage, BMState);

    cvReleaseStereoBMState(&BMState);


}


