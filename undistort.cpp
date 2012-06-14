#include "undistort.h"
#include "ui_undistort.h"

Undistort::Undistort(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Undistort)
{
    ui->setupUi(this);
}

Undistort::~Undistort()
{
    delete ui;
}
