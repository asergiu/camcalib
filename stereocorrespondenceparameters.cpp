#include "stereocorrespondenceparameters.h"

const char* CorrespondenceParameters::PRE_FILTER_CAP_TAG = "preFilterCap";
const char*  CorrespondenceParameters::PRE_FILTER_SIZE_TAG = "preFilterSz";
const char* CorrespondenceParameters::SAD_WND_SZ_TAG = "sadWndSz";
const char* CorrespondenceParameters::NUM_DISP_TAG = "numDisparities";
const char* CorrespondenceParameters::MIN_DISP_TAG = "minDisparities";
const char* CorrespondenceParameters::UNIQ_TAG ="uniqunessRatio";
const char* CorrespondenceParameters::TEXTURE_TAG = "textureThreshold";
const char* CorrespondenceParameters::SPKL_WND_SZ = "speckleWndSz";
const char* CorrespondenceParameters::SPKL_RANGE = "speckleRange";


CorrespondenceParameters::CorrespondenceParameters()
{
    m_BMState = 0;
}

void CorrespondenceParameters::setBMState(CvStereoBMState* BMState){

    this->m_BMState = BMState;

}

bool CorrespondenceParameters::saveBMState(const char *filename){

    CvFileStorage* fstorage = cvOpenFileStorage(filename, NULL, CV_STORAGE_WRITE);

    if(!fstorage)
        return false;

    if(!m_BMState)
        return false;

    cvWriteInt(fstorage, MIN_DISP_TAG, this->m_BMState->minDisparity);
    cvWriteInt(fstorage, NUM_DISP_TAG, this->m_BMState->numberOfDisparities);
    cvWriteInt(fstorage, UNIQ_TAG, this->m_BMState->uniquenessRatio);
    cvWriteInt(fstorage, TEXTURE_TAG, this->m_BMState->textureThreshold);
    cvWriteInt(fstorage, PRE_FILTER_CAP_TAG, this->m_BMState->preFilterCap);
    cvWriteInt(fstorage, PRE_FILTER_SIZE_TAG, this->m_BMState->preFilterSize);
    cvWriteInt(fstorage, SAD_WND_SZ_TAG, this->m_BMState->SADWindowSize);
    cvWriteInt(fstorage, SPKL_RANGE, this->m_BMState->speckleRange);
    cvWriteInt(fstorage, SPKL_WND_SZ, this->m_BMState->speckleWindowSize);

    cvReleaseFileStorage(&fstorage);

    return true;
}

bool CorrespondenceParameters::loadBMState(const char* filename){

    CvFileStorage* fstorage = 0;
    fstorage =  cvOpenFileStorage(filename, NULL,  CV_STORAGE_READ);

    if(!fstorage)
        return false;

    this->m_BMState = cvCreateStereoBMState();

    this->m_BMState->minDisparity = cvReadIntByName(fstorage, 0, MIN_DISP_TAG);
    this->m_BMState->numberOfDisparities = cvReadIntByName(fstorage, 0, NUM_DISP_TAG);
    this->m_BMState->uniquenessRatio = cvReadIntByName(fstorage, 0, UNIQ_TAG);
    this->m_BMState->textureThreshold = cvReadIntByName(fstorage,0,TEXTURE_TAG);
    this->m_BMState->preFilterCap = cvReadIntByName(fstorage, 0, PRE_FILTER_CAP_TAG);
    this->m_BMState->preFilterSize = cvReadIntByName(fstorage, 0,PRE_FILTER_SIZE_TAG);
    this->m_BMState->SADWindowSize = cvReadIntByName(fstorage, 0, SAD_WND_SZ_TAG);
    this->m_BMState->speckleRange = cvReadIntByName(fstorage, 0, SPKL_RANGE);
    this->m_BMState->speckleWindowSize = cvReadIntByName(fstorage, 0, SPKL_WND_SZ);

    cvReleaseFileStorage(&fstorage);

    return true;
}
