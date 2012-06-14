#include "fileutils.h"


FileUtils::FileUtils()
{
}

QString FileUtils::loadFile(QString extension){

    QFileDialog fileDialog;

    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);

    QString fileName = QFileDialog::getOpenFileName(this,tr("Open file"),QDir::currentPath(),extension );

    return fileName;
}

void FileUtils::saveFile(){

    QFileDialog fileDialog;

    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);

    QString fileName = QFileDialog::getSaveFileName(this);

    QFile f(fileName);
    f.open( QIODevice::WriteOnly );

    // TODO store data in f

    f.close();
}
