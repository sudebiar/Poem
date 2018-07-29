#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qsqlquery.h>
#include <qsqlquerymodel.h>
#include <QString>
#include <frmnew.h>
#include <frmupdate.h>
#include <qmessagebox.h>
#include <qsqltablemodel.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->menuBar->setLayoutDirection(Qt::RightToLeft);


    updTbl();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updTbl()
{

    connOpen();

    QSqlQueryModel * modal = new QSqlQueryModel();




    QSqlQuery * qry = new QSqlQuery(mydb);

    qry->prepare("select * from Poems");
    qry->exec();
    modal->setQuery(*qry);

    ui->tableView->setModel(modal);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->setColumnHidden(2,true);
    ui->tableView->setColumnHidden(3,true);

    ui->tableView->setLayoutDirection(Qt::RightToLeft);
    ui->tableView->setColumnWidth(1,330);
    ui->tableView->model()->setHeaderData(1,Qt::Horizontal,"عنوان شعر");
    ui->tableView->repaint();
    while (modal->canFetchMore())
         modal->fetchMore();
    ui->tableView->scrollToBottom();
}



void MainWindow::on_tableView_pressed(const QModelIndex &index)
{



        //connOpen();
       cellText = ui->tableView->model()->data(index).toString();



        QSqlQuery * qry2 = new QSqlQuery(mydb);

        qry2->prepare("select * from Poems where Title='"+cellText+"'");
        qry2->exec();


        while(qry2->next()){

        cellTitle = qry2->value(1).toString();
        cellPoem = qry2->value(2).toString();
        cellGroup = qry2->value(3).toString();
        Index = qry2->value(0).toInt();



        ui->textEdit->setText(qry2->value(2).toString());

     }

    //connClose();

}

void MainWindow::on_pushButton_2_clicked()
{

    connClose();
    FrmNew frmnew;
    frmnew.setModal(true);
    frmnew.exec();

}

void MainWindow::on_btnUpdate_clicked( )
{
   //connClose();
   frmUpdate frmupdate(cellTitle,cellPoem,cellGroup,Index);
   frmupdate.setModal(true);
   frmupdate.exec();
}


bool MainWindow::event(QEvent * e) // overloading event(QEvent*) method of QMainWindow
{
    switch(e->type())
    {
        // ...

        case QEvent::WindowActivate :
            updTbl();
            break ;

        case QEvent::WindowDeactivate :
            // lost focus
            break ;
        // ...
    } ;
    return QMainWindow::event(e) ;
}








void MainWindow::on_btnDelete_clicked()
{


    QSqlQuery * qry2 = new QSqlQuery(mydb);

    qry2->prepare("delete from Poems where Title='"+cellText+"'");

    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "حذف", "آیا برای حذف مطمئن هستید؟!?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
            qry2->exec();
            ui->textEdit->setText("");
            updTbl();

      } else {
        //qDebug() << "Yes was *not* clicked";
      }
    }



