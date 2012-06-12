#include "patterninfopage.h"
#include "ui_patterninfopage.h"
#include <QGraphicsPixmapItem>

PatternInfoPage::PatternInfoPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::PatternInfoPage)
{
    setTitle(tr("Pattern information"));
    setSubTitle(tr("Specify the width and the height of the chessboard - should be integers."));

    ui->setupUi(this);
    setLayout(ui->gridLayout);


}

PatternInfoPage::~PatternInfoPage()
{
    delete ui;
}
