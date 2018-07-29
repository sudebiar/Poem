#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/qsqldatabase.h>
#include <qtableview.h>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    QSqlDatabase mydb;
    QString cellText;
    int Index;
    QString cellTitle,cellPoem,cellGroup;

    void updTbl();
    void connClose()
    {

        //QString connection;
        //connection = mydb.connectionName();
        mydb.close();
        //mydb.removeDatabase(connection);
        mydb.removeDatabase(mydb.connectionName());
    }
    bool connOpen()
    {
        mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("Poem.db");
        if(mydb.open())
        {
            return true;
        }
        else if(!mydb.open())
        {
            return false;
        }

    }


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_tableView_pressed(const QModelIndex &index);

    void on_pushButton_2_clicked();



    void on_btnUpdate_clicked();

    void on_btnDelete_clicked();

private:
    Ui::MainWindow *ui;


protected:
      bool event(QEvent * e);

};

#endif // MAINWINDOW_H
