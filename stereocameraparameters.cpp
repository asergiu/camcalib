#include "stereocameraparameters.h"

const char* StereoCameraParameters::FUNDAMENTAL_MAT_TAG = "fundamentalMatrix";
const char* StereoCameraParameters::ESSENTIAL_MAT_TAG = "essentialMatrix";
const char* StereoCameraParameters::TRANSALTION_VECT_TAG = "translationVector";
const char* StereoCameraParameters::ROTATION_MAT_TAG = "rotationMatrix";
const char* StereoCameraParameters::CAM1_PARM_TAG = "cam1Param";
const char* StereoCameraParameters::CAM2_PARAM_TAG = "cam2Param";

StereoCameraParameters::StereoCameraParameters()
{
    rotation_matrix = 0;
    fundametal_matrix = 0;
    essential_matrix = 0;
    transaltion_vector = 0;
    cameraParameters1 = 0;
    cameraParameters2 = 0;
}


StereoCameraParameters::~StereoCameraParameters(){

    cvReleaseMat(&rotation_matrix);
    cvReleaseMat(&fundametal_matrix);
    cvReleaseMat(&essential_matrix);
    cvReleaseMat(&transaltion_vector);

    delete cameraParameters1;
    delete cameraParameters2;

}


bool StereoCameraParameters::saveParameters(const char* filename){

    CvFileStorage* fstorage = cvOpenFileStorage(filename, NULL, CV_STORAGE_WRITE);
    if(fstorage == NULL)
        return false;

    cvWrite(fstorage, ROTATION_MAT_TAG, rotation_matrix);
    cvWrite(fstorage, TRANSALTION_VECT_TAG, transaltion_vector);
    cvWrite(fstorage, ESSENTIAL_MAT_TAG, essential_matrix);
    cvWrite(fstorage, FUNDAMENTAL_MAT_TAG, fundametal_matrix);

    cvReleaseFileStorage(&fstorage);

    return true;

}

bool StereoCameraParameters::loadParameters(const char* filename){

    CvFileStorage* fstorage = 0;
    fstorage =  cvOpenFileStorage(filename, NULL,  CV_STORAGE_READ);

    if(!fstorage)
        return false;

    this->essential_matrix = cvCloneMat( (CvMat*) cvReadByName(fstorage, 0, ESSENTIAL_MAT_TAG));
    this->fundametal_matrix = cvCloneMat((CvMat*) cvReadByName(fstorage, 0, FUNDAMENTAL_MAT_TAG));
    this->rotation_matrix = cvCloneMat((CvMat*) cvReadByName(fstorage, 0, ROTATION_MAT_TAG));
    this->transaltion_vector = cvCloneMat((CvMat*) cvReadByName(fstorage, 0, TRANSALTION_VECT_TAG));

    cvReleaseFileStorage(&fstorage);

    return true;
}

CameraParameters* StereoCameraParameters::getCamera1Parameters(){

    return this->cameraParameters1;

}

CameraParameters* StereoCameraParameters::getCamera2Parameters(){

    return this->cameraParameters2;
}

CvMat* StereoCameraParameters::getFundamentalMatrix(){

    return this->fundametal_matrix;
}

CvMat* StereoCameraParameters::getRotationMatrix(){

    return this->rotation_matrix;
}

CvMat* StereoCameraParameters::getTranslationVector(){

    return this->transaltion_vector;
}

void StereoCameraParameters::setFundamentalMat(CvMat* fundametal_mat){

    this->fundametal_matrix =  cvCloneMat(fundametal_mat);
}

void StereoCameraParameters::setEssentialMatrix(CvMat* essential_mat){

    this->essential_matrix = cvCloneMat(essential_mat);

}

void StereoCameraParameters::setRotationMat(CvMat* rotation_mat){

    this->rotation_matrix = cvCloneMat(rotation_mat);

}

void StereoCameraParameters::setTransaltionVect(CvMat* transaltion_vect){

    this->transaltion_vector = cvCloneMat(transaltion_vect);

}

void StereoCameraParameters::setCameraParamaters1(CameraParameters* cam1_param){
    this->cameraParameters1 = cam1_param;
}

void StereoCameraParameters::setCameraParamaters2(CameraParameters* cam2_param){
    this->cameraParameters2 = cam2_param;
}
