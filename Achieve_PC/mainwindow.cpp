#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

#include "initdb.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // initialize the database
    QSqlError err = initDb();
    if (err.type() != QSqlError::NoError) {
        showError(err);
        return;
    }

    QSqlQuery query;
    query.exec("SELECT ID, RName FROM Rarity");

    //Выводим значения из запроса
    while (query.next())
    {
    QString ID = query.value(0).toString();
    QString RName = query.value(1).toString();
    ui->textEdit->insertPlainText(ID+" "+RName+" "+"\n");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
