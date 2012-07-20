#include "tabbedmenudialog.h"
#include "ui_tabbedmenudialog.h"

TabbedMenuDialog::TabbedMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TabbedMenuDialog)
{
    ui->setupUi(this);
    m_fileUtils = new FileUtils();
}

TabbedMenuDialog::~TabbedMenuDialog()
{
    delete ui;
}

void TabbedMenuDialog::loadCalibParams()
{
    QString path = m_fileUtils->loadFile(FileUtils::xmlExtension);
    this->ui->PathField->setText(path);

    QFile file(path);
         if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return;

         while (!file.atEnd()) {
             QByteArray line = file.readLine();
             this->ui->textBrowser->append(line);
         }
}
