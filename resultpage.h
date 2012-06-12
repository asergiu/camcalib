#ifndef RESULTPAGE_H
#define RESULTPAGE_H

#include <QWizardPage>

namespace Ui {
class ResultPage;
}

class ResultPage : public QWizardPage
{
    Q_OBJECT
    
public:

    explicit ResultPage(QWidget *parent = 0);
    ~ResultPage();
    
private:
    Ui::ResultPage *ui;

public slots:
 virtual void saveResults();


};

#endif // RESULTPAGE_H
