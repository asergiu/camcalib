#include "cameraparameters.h"

CameraParameters::CameraParameters()
{
}

CameraParameters::CameraParameters(CvMat* cameraMatrix, CvMat* distortionCoef, double reprojectionError){

    this->m_mat_camera_matrix = cvCloneMat(cameraMatrix);
    this->m_mat_distortion_coeff = cvCloneMat(distortionCoef);
    this->m_d_reprojection_error = reprojectionError;

}

CvMat* CameraParameters::getCameraMatrix(){

    return this->m_mat_camera_matrix;
}

CvMat* CameraParameters::getDistortionCoef(){

    return this->m_mat_distortion_coeff;

}

double CameraParameters::getReprojectionError(){

    return this->m_d_reprojection_error;

}

void CameraParameters::setCameraMatrix(CvMat* camera_matrix){
    this->m_mat_camera_matrix =  cvCloneMat(camera_matrix);
}

void CameraParameters::setDistortionVector(CvMat* distortion_vector){
    this->m_mat_distortion_coeff = cvCloneMat(distortion_vector);
}

void CameraParameters::saveParameters(const char* filename){

    CvFileStorage* fstorage = cvOpenFileStorage(filename, NULL, CV_STORAGE_WRITE);

    cvWrite(fstorage, "cameraMatrix", m_mat_camera_matrix);
    cvWrite(fstorage, "distortionCoeff", m_mat_distortion_coeff);
    cvWriteReal(fstorage, "reprojectionError", this->m_d_reprojection_error);

    cvReleaseFileStorage(&fstorage);

}

int CameraParameters::loadParameters(const char* filename){

    CvFileStorage* readParameters = 0;
    readParameters =  cvOpenFileStorage(filename, NULL,  CV_STORAGE_READ);

    if(!readParameters)
        return -1;

    this->m_mat_camera_matrix = cvCloneMat( (CvMat*) cvReadByName(readParameters, 0, "distorsion1"));
    this->m_mat_distortion_coeff = cvCloneMat((CvMat*) cvReadByName(readParameters, 0, "distortion"));

    cvReleaseFileStorage(&readParameters);

}
