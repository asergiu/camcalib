#include "loadimagespage.h"
#include "ui_loadimagespage.h"
#include <QFileDialog>
#include <QListWidgetItem>

LoadImagesPage::LoadImagesPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::LoadImagesPage)
{
    setTitle(tr("Load images"));
     setSubTitle(tr("Load the images containing the calibration pattern."));

    ui->setupUi(this);

    setLayout(ui->formLayout);
}

LoadImagesPage::~LoadImagesPage()
{
    delete ui;
}

void LoadImagesPage::loadImages(){

    QString fileName;


    QFileDialog dialog(this);

    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        fileNames = dialog.selectedFiles();

    foreach (fileName, fileNames)
    {
        QListWidgetItem *item = new QListWidgetItem(ui->images);
        QFileInfo fi(fileName);

        QString name = fi.fileName();
        item->setText(name);

        //TODO add icon on images
    }


    ui->images->update();

    if (fileNames.size() > 0 && ui->removeImage->isHidden())
        ui->removeImage->show();
}


void LoadImagesPage::removeImage(){

    //TODO select multiple items from the qlistWidget
    qDeleteAll(ui->images->selectedItems());

}

void LoadImagesPage::addImage(){
    //TODO add new image from the same directory
}
