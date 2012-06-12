#ifndef PATTERNINFOPAGE_H
#define PATTERNINFOPAGE_H

#include <QWizardPage>

namespace Ui {
class PatternInfoPage;
}

class PatternInfoPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit PatternInfoPage(QWidget *parent = 0);
    ~PatternInfoPage();
    
private:
    Ui::PatternInfoPage *ui;
};

#endif // PATTERNINFOPAGE_H
