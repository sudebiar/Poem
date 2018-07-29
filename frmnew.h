#ifndef FRMNEW_H
#define FRMNEW_H

#include <QDialog>



namespace Ui {
class FrmNew;
}

class FrmNew : public QDialog
{
    Q_OBJECT

public:

    explicit FrmNew(QWidget *parent = 0);
    ~FrmNew();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FrmNew *ui;


};

#endif // FRMNEW_H
