#include "frmnew.h"
#include "ui_frmnew.h"
#include <qsqlquery.h>
#include <qsqlquerymodel.h>
#include <QString>
#include <qmessagebox.h>
#include <mainwindow.h>


FrmNew::FrmNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmNew)
{
    ui->setupUi(this);


}

FrmNew::~FrmNew()
{

    delete ui;
}

void FrmNew::on_pushButton_clicked()
{
    QString Title,Group,Poem;

    Title = ui->lineEdit->text();
    Group = ui->lineEdit_2->text();
    Poem = ui->textEdit->toPlainText();



     MainWindow mainwindow;
     //mainwindow.connOpen();



     QSqlQuery * qry1 = new QSqlQuery(mainwindow.mydb);

     qry1->prepare("insert into Poems(Title,Poem,Grp) values ('"+Title+"','"+Poem+"','"+Group+"')");




     if(qry1->exec())
     {
         QMessageBox::information(this,tr("درج شعر جدید"),tr("شعر اضافه شد"));

         ui->lineEdit->setText("");
         ui->lineEdit_2->setText("");
         ui->textEdit->setText("");

         //mainwindow.connClose();



     }
     else
     {
         QMessageBox::critical(this,tr("درج شعر جدید"),"error");

     }

}

void FrmNew::on_pushButton_2_clicked()
{
    this->close();
}
