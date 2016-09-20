#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

#define PATH "D:/Study/Achievements/Achieve_PC/Achieve_PC/achievements.db3"

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
    QSqlDatabase    db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(PATH);
    db.open();

    QSqlQuery query;
    query.exec("SELECT ID, AName FROM Achievement");

    //Выводим значения из запроса
    while (query.next())
    {
    QString ID = query.value(0).toString();
    QString AName = query.value(1).toString();
    ui->textEdit->insertPlainText(ID+" "+AName+" "+"\n");
    }
}
