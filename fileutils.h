#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <QFileDialog>


class FileUtils: public QWidget
{

    //TODO de definit extensii pentru deschiderea fisierelor de tip xml, de tip imagine etc
public:
    FileUtils();
    void saveFile();
    QString loadFile(QString extension);

};

#endif // FILEUTILS_H
