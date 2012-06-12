#ifndef CALIBRATIONWIZARD_H
#define CALIBRATIONWIZARD_H

#include <QWizard>
#include "intropage.h"
#include "loadimagespage.h"
#include "patterninfopage.h"
#include "resultpage.h"
#include "chessboardcornerspage.h"

namespace Ui {
class CalibrationWizard;
}

class CalibrationWizard : public QWizard
{
    Q_OBJECT
    
public:
    explicit CalibrationWizard(QWidget *parent = 0);
    ~CalibrationWizard();
    
private:
    Ui::CalibrationWizard *ui;
};

#endif // CALIBRATIONWIZARD_H
