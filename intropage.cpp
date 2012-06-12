#include "intropage.h"
#include "ui_intropage.h"

IntroPage::IntroPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::IntroPage)
{

    setTitle(tr("Introduction"));
   // setPixmap(QWizard::WatermarkPixmap, QPixmap(":/images/watermark1.png"));

    label = new QLabel(tr("This wizard will compute the internal cam. parametes "
                          "and distortion coefficients for a camera. You "
                          " simply need to specify the location of the chessboard images "
                          " and set a few options to calibrate your camera. "));
    label->setWordWrap(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    setLayout(layout);
    ui->setupUi(this);
}

IntroPage::~IntroPage()
{
    delete ui;
}
