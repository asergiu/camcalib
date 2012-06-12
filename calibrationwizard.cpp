#include "calibrationwizard.h"
#include "ui_calibrationwizard.h"
#include "loadimagespage.h"

CalibrationWizard::CalibrationWizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::CalibrationWizard)
{

    addPage(new IntroPage);
    addPage(new LoadImagesPage);
    addPage(new PatternInfoPage);
    addPage(new ChessboardCornersPage);
    addPage(new ResultPage);

    ui->setupUi(this);
}

CalibrationWizard::~CalibrationWizard()
{
    delete ui;
}
