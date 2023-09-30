#include "functions.h"
#include <QFile>
#include <QTextStream>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql>

QSqlDatabase db;


bool getInitStatus()
{
    QFile file("init_status.txt");
    file.open(QIODevice::ReadWrite);
    QTextStream stream(&file);

    int status;
    stream >> status;

    if(status == 1)
        return true;
    else
        return false;

}

void init()
{
    //init remembrance.txt
    QFile file("remembrance.txt");
    file.open(QIODevice::ReadWrite);
    QTextStream stream(&file);

    stream << -1;
    file.close();

    //create DataBase
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./users.db");
    //QSqlQuery

}

int getRemembrance()
{
    QFile file("remembrance.txt");
    //file.open(QIODevice::ReadWrite);
    QTextStream stream(&file);

    file.open(QIODevice::ReadOnly);
    int id;
    stream >> id;
    return id;
}

void setRemembrance(int _id)
{
    QFile file("remembrance.txt");
    QTextStream stream(&file);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    stream << _id;
}
