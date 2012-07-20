#include "adjustbmparam.h"
#include "ui_adjustbmparam.h"
#include"stdio.h"


AdjustBMParam::AdjustBMParam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdjustBMParam)
{
    ui->setupUi(this);

    disparityMapColor = new ColouredDisparityMap();

    g2cd_data = (ColouredDisparityMap::g2cd_data_t *) malloc(sizeof(ColouredDisparityMap::g2cd_data_t));

    if (!disparityMapColor->g2cd_calculate_look_up_table (g2cd_data))
    {
        fprintf(stderr,"ERROR: Could not precalculate color lookup table\n");

    }

    dispartiyImageColor = NULL;



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

    stereoCalibration->computeDisparity(leftImage, rightImage, BMState);

    CvMat* pair = cvCreateMat(leftImage->height, leftImage->width*2, CV_8UC3 );
    CvMat part;


    cvGetCols( pair, &part, 0, leftImage->width );
    cvCvtColor( stereoCalibration->leftImageRectified, &part, CV_GRAY2BGR );

    cvGetCols( pair, &part, leftImage->width,leftImage->width*2 );
    cvCvtColor( stereoCalibration->rightImageRectified, &part, CV_GRAY2BGR);

    for(int j = 0; j < leftImage->height; j += 25 )
        cvLine( pair, cvPoint(0,j),cvPoint(leftImage->width*2,j),CV_RGB(255,0,0));

    cvReleaseImage(&dispartiyImageColor);
    dispartiyImageColor = cvCreateImage (cvGetSize(leftImage),IPL_DEPTH_8U, 3);
    if (dispartiyImageColor == NULL)
    {
        fprintf(stderr,"ERROR: Could not create pseudocolor image.\n");
        exit(2);
    }

    IplImage *img, img_header;
    img = cvGetImage(stereoCalibration->imageDisparityNormalized, &img_header);

    disparityMapColor->g2cd_gray_to_chromadepth(img, this->dispartiyImageColor, this->g2cd_data);

    cvShowImage("disparity coloured", dispartiyImageColor);

    cvNamedWindow( "rectified", 1 );
    cvShowImage( "rectified", pair );

    cvReleaseStereoBMState(&BMState);
    //cvReleaseImage(&img);


}

void AdjustBMParam::setStereoCalibration(StereoCalibration *stereoCalibration){

    this->stereoCalibration = stereoCalibration;
}

void AdjustBMParam::setLeftImage(IplImage* left_image){

    this->leftImage = left_image;

}

void AdjustBMParam::setRightImage(IplImage* right_image){

    this->rightImage = right_image;
}

bool AdjustBMParam::saveParameters(){

    FileUtils* fileUtils = new FileUtils();

    QString fileName = fileUtils->saveFile();

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


    CvFileStorage* fstorage = cvOpenFileStorage(fileName.toLocal8Bit().data(), NULL, CV_STORAGE_WRITE);
    if(fstorage == NULL){
        fprintf(stderr,"ERROR: File storage NULL!\n");
        return false;
    }

    cvWriteInt(fstorage, "preFilterSize", preFilterSz);
    cvWriteInt(fstorage, "preFilterCap", preFilterCap);
    cvWriteInt(fstorage, "sadWindowSize", sadWndSz);
    cvWriteInt(fstorage, "minDisp", minDisp);
    cvWriteInt(fstorage, "numDisp", numDisp);
    cvWriteInt(fstorage, "textureThreshold", texture);
    cvWriteInt(fstorage, "uniquness", uniquness);
    cvWriteInt(fstorage, "spkWindowSize", spkWndSz);
    cvWriteInt(fstorage,"spkRange", spkRange);

    cvReleaseFileStorage(&fstorage);

    delete fileUtils;

    return true;

}
