#include "chessboardcornerspage.h"
#include "ui_chessboardcornerspage.h"

ChessboardCornersPage::ChessboardCornersPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::ChessboardCornersPage)
{
    setTitle(tr("Chessboard corners"));

//    QPixmap* pixmap = new QPixmap("c:\\button_cancel.png");
//    QIcon icon(*pixmap);
//    QSize iconSize(pixmap->width(), pixmap->height());
//    ui->pushButton->setIconSize(iconSize);
//    ui->pushButton->setIcon(icon);


     ui->setupUi(this);
    setLayout(ui->gridLayout);

//    QPushButton* button = new QPushButton();



}

ChessboardCornersPage::~ChessboardCornersPage()
{
    delete ui;
}
