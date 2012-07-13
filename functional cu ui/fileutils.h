#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <QFileDialog>
#include <QStringList>

class FileUtils: public QWidget
{

public:
    static const QString xmlExtension;
    static const QString imageExtension;
public:
    FileUtils();

    void saveFile();
    QString loadFile(QString extension);
    QString openDirectory();
    QStringList loadFiles(QString extension);

};

#endif // FILEUTILS_H
