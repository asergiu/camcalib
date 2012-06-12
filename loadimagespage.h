#ifndef LOADIMAGESPAGE_H
#define LOADIMAGESPAGE_H

#include <QWizardPage>

namespace Ui {
class LoadImagesPage;
}

class LoadImagesPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit LoadImagesPage(QWidget *parent = 0);
    ~LoadImagesPage();

public slots:
    virtual void loadImages();
    virtual void removeImage();
    virtual void addImage();

private:
    Ui::LoadImagesPage *ui;
    QStringList fileNames;

};

#endif // LOADIMAGESPAGE_H
