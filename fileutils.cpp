#include "fileutils.h"

const QString FileUtils::imageExtension = tr("Image files (*.png *.tif *.jpg *.bmp);;All files (*.*)");
const QString FileUtils::xmlExtension = tr("Xml files (*.xml);;All files (*.*)");

FileUtils::FileUtils()
{

}

QString FileUtils::loadFile(QString extension){

    QFileDialog fileDialog;

    fileDialog.setFileMode(QFileDialog::ExistingFiles);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);

    QString fileName = QFileDialog::getOpenFileName(this,tr("Open file"),QDir::currentPath(),extension );

    return fileName;
}

QStringList FileUtils::loadFiles(QString extension){

    QStringList selectedFiles;

    QFileDialog fileDialog;

    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setFileMode(QFileDialog::ExistingFiles);

    selectedFiles =  QFileDialog::getOpenFileNames(this, tr("Open files"), QDir::currentPath(), extension);

    return selectedFiles;

}

QString FileUtils::openDirectory(){
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    return dir;
}

QString FileUtils::saveFile(){

    QFileDialog fileDialog;

    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);

    QString fileName = QFileDialog::getSaveFileName(this);

   return fileName;
}


