#include "resultpage.h"
#include "ui_resultpage.h"
#include <QFileDialog>

ResultPage::ResultPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::ResultPage)
{
    setTitle(tr("Calibration results"));

    ui->setupUi(this);
    setLayout(ui->formLayout);
    setFinalPage(true);
}

ResultPage::~ResultPage()
{
    delete ui;
}

void ResultPage::saveResults(){

    QFileDialog fileDialog;

    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);

    QString fileName = QFileDialog::getSaveFileName(this);

    QFile f(fileName);
    f.open( QIODevice::WriteOnly );

    // TODO store data in f

    f.close();

}




