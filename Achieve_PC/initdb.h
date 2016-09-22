#ifndef INITDB_H
#define INITDB_H

#include <QSqlError>
#include <QSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>

#define PATH "D:\\Study\\Achievements\\Achieve_PC\\Achieve_PC\\ACHIEVEMENTS.FDB"

QSqlError initDb(){
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
        return db.lastError();
    return QSqlError();
}

void showError(const QSqlError &err)
{
    qDebug() << err.text();
}



#endif
