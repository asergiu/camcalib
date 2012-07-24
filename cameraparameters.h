#ifndef CAMERAPARAMETERS_H
#define CAMERAPARAMETERS_H

#include "opencv_headers.h"


class CameraParameters
{
public:

    static const char* CAMERA_MATRIX_TAG;
    static const char* DISTORTION_COEF_TAG;

    CameraParameters();
    CameraParameters(CvMat* cameraMatrix, CvMat* distortionCoef);
    ~CameraParameters();

    CvMat* getCameraMatrix();
    CvMat* getDistortionCoef();

    bool saveParameters(const char* filename);
    bool loadParameters(const char* filename);

    void setCameraMatrix(CvMat* cameraMatrix);
    void setDistortionVector(CvMat* distortionVector);



private:
    CvMat* m_mat_distortion_coeff;
    CvMat* m_mat_camera_matrix;

};

#endif // CAMERAPARAMETERS_H
