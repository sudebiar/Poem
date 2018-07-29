#ifndef FRMUPDATE_H
#define FRMUPDATE_H

#include <QDialog>

namespace Ui {
class frmUpdate;
}

class frmUpdate : public QDialog
{
    Q_OBJECT

public:
    explicit frmUpdate(QString  &cell1,QString & cell2,QString  &cell3,int &index,QWidget *parent = 0);
    ~frmUpdate();

private slots:
    void on_btnUpdate_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::frmUpdate *ui;

public :
    int ind;
};

#endif // FRMUPDATE_H
