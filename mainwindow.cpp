#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMdiSubWindow>
#include <QDebug>

#include <iostream>
using namespace::std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    wnd = ui->mdiArea->subWindowList();

    ui->mdiArea->hide();


    connect(ui->actionCalibration, SIGNAL(triggered()), this, SLOT(calibrationAction()));
    connect(ui->actionUndistortion, SIGNAL(triggered()), this, SLOT(undistortionAction()));

    QList<QMdiSubWindow *>::iterator i;

    Qt::WindowFlags flags;
    flags = Qt::WindowSystemMenuHint | Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint;


    for (i=wnd.begin();i!= wnd.end();++i){
        (*i)->hide();
        (*i)->setWindowFlags(flags);
        (*i)->setAttribute(Qt::WA_DeleteOnClose,false);
    }

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveResults(){

    FileUtils *fileUtils = new FileUtils;

    fileUtils->saveFile();
}

void MainWindow::openFindCornersWnd(){

    QList<QMdiSubWindow *>::iterator i;

    for (i=wnd.begin();i!= wnd.end();++i)
        if(QString::compare((*i)->windowTitle(),tr("Find corners"))==0)
            (*i)->show();

}

void MainWindow::openUndistortionWnd(){

    QList<QMdiSubWindow *>::iterator i;

    for (i=wnd.begin();i!= wnd.end();++i)
        if(QString::compare((*i)->windowTitle(),tr("Undistortion"))==0)
            (*i)->show();


}

void MainWindow::browseParam(){

    FileUtils *fileUtils = new FileUtils;

    QString fileName = fileUtils->loadFile(FileUtils::xmlExtension);

    this->ui->camParamFile->setText(fileName);

}

void MainWindow::loadImage(){

    FileUtils *fileUtils = new FileUtils;

    QString fileName = fileUtils->loadFile(FileUtils::imageExtension);

    ui->undstImgFile->setText(fileName);

    delete fileUtils;

}

void MainWindow::undistort(){

}

void MainWindow::calibrate(){

}

void MainWindow::cornersOk(){

}

void MainWindow::cornersNotOk(){

}

void MainWindow::removeImage(){

    QList<QListWidgetItem* > selectedItems = ui->imageList->selectedItems();

    QStringList candidates;



    for (int i = 0; i < selectedItems.count(); i++) {
        QString item = selectedItems.at(i)->text();
        candidates = patternImages.filter(item);

        if(!candidates.empty())
            patternImages.removeOne(candidates.first());
    }
    qDeleteAll(selectedItems);

    this->updateSmallImage();


    ui->smallImg->update();
    //  ui->smallImg->repaint();
}

void MainWindow::loadPatternImages(){

    FileUtils *fileUtils = new FileUtils;

    patternImages = fileUtils->loadFiles(FileUtils::imageExtension);
    QString fileName;

    foreach (fileName, patternImages)
    {
        QListWidgetItem *item = new QListWidgetItem(ui->imageList);
        QFileInfo fi(fileName);

        QString name = fi.fileName();
        item->setText(name);

        //TODO add icon on images
    }


    ui->imageList->update();

    this->updateSmallImage();


    delete fileUtils;
}

void MainWindow::updateSmallImage(){

    if(!patternImages.empty()){

        smallImageScene.clear();

        QGraphicsPixmapItem* smallImage = new QGraphicsPixmapItem(QPixmap(patternImages.first()));
        smallImage->setPixmap(QPixmap(patternImages.first()).scaled(ui->smallImg->size()-QSize(10, 10)));

        smallImageScene.addItem(smallImage);

        ui->smallImg->setScene(&smallImageScene);

    }
    else{

        smallImageScene.clear();
    }
}

void MainWindow::calibrationAction(){

    QList<QMdiSubWindow *>::iterator i;

    ui->mdiArea->show();
    for (i=wnd.begin();i!= wnd.end();++i)
        if(QString::compare((*i)->windowTitle(),tr("Calibration"))==0){
            if(!(*i)->isVisible()){
                (*i)->show();
                (*i)->setLayout(ui->gridLayout);
            }
        }




}


void MainWindow::undistortionAction(){

    QList<QMdiSubWindow *>::iterator i;

    ui->mdiArea->show();
    for (i=wnd.begin();i!= wnd.end();++i)
        if(QString::compare((*i)->windowTitle(),tr("Undistortion"))==0)
            (*i)->show();

}
