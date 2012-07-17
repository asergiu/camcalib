#ifndef CALIBRATION_H
#define CALIBRATION_H

#include "cameraparameters.h"
#include "omp.h"

#include"opencv_headers.h"

class Calibration
{
public:

    Calibration();

    void initialize();

    int findCorners(IplImage* image);
    int findCorners(const char* filename);

    void getInfoForCalibration(CvPoint2D32f* corners);

    CameraParameters* calibrateCamera();

    IplImage* undistortImage(IplImage* image, CameraParameters* cameraParameters);

    bool validateCornersHorizontally(CvPoint2D32f* corners);
    bool validateCornersVertically(CvPoint2D32f* corners);
    bool validateCorners(CvPoint2D32f* corners);

private:
    CvMat* object_points;
    CvMat* image_points;
    CvMat* point_counts;

    int board_w;
    int board_h;
    int successes;
    int n_boards;

    CvSize imageSize;
};

#endif // CALIBRATION_H
