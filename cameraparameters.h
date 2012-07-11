#ifndef CAMERAPARAMETERS_H
#define CAMERAPARAMETERS_H

#include<opencv/cv.h>
#include<opencv/highgui.h>
using namespace cv;

class CameraParameters
{
public:

    CameraParameters();
    CameraParameters(CvMat* cameraMatrix, CvMat* distortionCoef, double reprojectionError);
    ~CameraParameters();

    CvMat* getCameraMatrix();
    CvMat* getDistortionCoef();
    double getReprojectionError();
    void saveParameters(const char* filename);
    int loadParameters(const char* filename);

    void setCameraMatrix(CvMat* camera_matrix);
    void setDistortionVector(CvMat* distortion_vector);



private:
    CvMat* m_mat_distortion_coeff;
    CvMat* m_mat_camera_matrix;
    double m_d_reprojection_error;
};

#endif // CAMERAPARAMETERS_H
