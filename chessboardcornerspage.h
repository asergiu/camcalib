#ifndef CHESSBOARDCORNERSPAGE_H
#define CHESSBOARDCORNERSPAGE_H

#include <QWizardPage>

namespace Ui {
class ChessboardCornersPage;
}

class ChessboardCornersPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit ChessboardCornersPage(QWidget *parent = 0);
    ~ChessboardCornersPage();
    
private:
    Ui::ChessboardCornersPage *ui;
};

#endif // CHESSBOARDCORNERSPAGE_H
