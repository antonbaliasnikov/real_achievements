#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QSqlError>

#include "initdb.h"

#define PATH "D:\\Study\\Achievements\\Achieve_PC\\Achieve_PC\\ACHIEVEMENTS.FDB"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Create QSql database object
    QSqlDatabase    db;
    // Specify database type
    db = QSqlDatabase::addDatabase("QIBASE");
    // Set the database path
    db.setDatabaseName(PATH);
    // Set USER name
    db.setUserName("SYSDBA");
    // Set password
    db.setPassword("masterkey");
    // Open the database
    if (!db.open())
        db.lastError();

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
