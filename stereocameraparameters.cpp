#include "stereocameraparameters.h"

StereoCameraParameters::StereoCameraParameters()
{
}


StereoCameraParameters::~StereoCameraParameters(){

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

bool StereoCameraParameters::saveParameters(const char* filename){

    CvFileStorage* fstorage = cvOpenFileStorage(filename, NULL, CV_STORAGE_WRITE);
    if(fstorage == NULL)
        return false;

    cvWrite(fstorage, "rotationMatrix", rotation_matrix);
    cvWrite(fstorage, "transaltionVector", transaltion_vector);
    cvWrite(fstorage, "essentialMatrix", essential_matrix);
    cvWrite(fstorage, "fundamentalMatrix", fundametal_matrix);

    cvReleaseFileStorage(&fstorage);

    return true;

}

bool StereoCameraParameters::loadParameters(char* fileName){

    return false;
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
