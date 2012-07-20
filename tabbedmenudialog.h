#ifndef TABBEDMENUDIALOG_H
#define TABBEDMENUDIALOG_H

#include <QDialog>
#include <fileutils.h>

namespace Ui {
    class TabbedMenuDialog;
}

class TabbedMenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TabbedMenuDialog(QWidget *parent = 0);
    ~TabbedMenuDialog();

private:
    Ui::TabbedMenuDialog *ui;
    FileUtils *m_fileUtils;
private slots:
    void loadCalibParams();
};

#endif // TABBEDMENUDIALOG_H
