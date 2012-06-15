#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <QFileDialog>
#include <QStringList>

class FileUtils: public QWidget
{

    //TODO de definit extensii pentru deschiderea fisierelor de tip xml, de tip imagine etc
public:
    static const QString xmlExtension;
    static const QString imageExtension;
public:
    FileUtils();

    void saveFile();
    QString loadFile(QString extension);
    QStringList loadFiles(QString extension);

};

#endif // FILEUTILS_H
