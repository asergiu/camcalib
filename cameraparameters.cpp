#include "cameraparameters.h"

const char* CameraParameters::CAMERA_MATRIX_TAG = "cameraMatrix";
const char* CameraParameters::DISTORTION_COEF_TAG = "distortionCoeff";

CameraParameters::CameraParameters()
{
    this->m_mat_camera_matrix = 0;
    this->m_mat_distortion_coeff = 0;
}

CameraParameters::~CameraParameters(){

    cvReleaseMat(&m_mat_camera_matrix);
    cvReleaseMat(&m_mat_distortion_coeff);
}

CameraParameters::CameraParameters(CvMat* cameraMatrix, CvMat* distortionCoef){

    this->m_mat_camera_matrix = cvCloneMat(cameraMatrix);
    this->m_mat_distortion_coeff = cvCloneMat(distortionCoef);

}

CvMat* CameraParameters::getCameraMatrix(){

    return this->m_mat_camera_matrix;
}

CvMat* CameraParameters::getDistortionCoef(){

    return this->m_mat_distortion_coeff;

}

void CameraParameters::setCameraMatrix(CvMat* cameraMatrix){
    this->m_mat_camera_matrix =  cvCloneMat(cameraMatrix);
}

void CameraParameters::setDistortionVector(CvMat* distortionVector){
    this->m_mat_distortion_coeff = cvCloneMat(distortionVector);
}

bool CameraParameters::saveParameters(const char* filename){

    CvFileStorage* fstorage = 0;
    fstorage = cvOpenFileStorage(filename, NULL, CV_STORAGE_WRITE);

    if(!fstorage)
        return false;

    cvWrite(fstorage, CAMERA_MATRIX_TAG, m_mat_camera_matrix);
    cvWrite(fstorage, DISTORTION_COEF_TAG, m_mat_distortion_coeff);

    cvReleaseFileStorage(&fstorage);

    return true;

}

bool CameraParameters::loadParameters(const char* filename){

    CvFileStorage* fstorage = 0;
    fstorage =  cvOpenFileStorage(filename, NULL,  CV_STORAGE_READ);

    if(!fstorage)
        return false;

    this->m_mat_camera_matrix = cvCloneMat( (CvMat*) cvReadByName(fstorage, 0, CAMERA_MATRIX_TAG));
    this->m_mat_distortion_coeff = cvCloneMat((CvMat*) cvReadByName(fstorage, 0, DISTORTION_COEF_TAG));

    cvReleaseFileStorage(&fstorage);

    return true;

}
