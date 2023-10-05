#include <QFile>
#include <QTextStream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>
#include <QSqlRecord>

#include "mainapplication.h"

void MainApplication::addAdminAccount()
{
    QSqlQuery query(*dataBase);
    QString q = "";
    q += "INSERT INTO 'ListOfUsers'('FirstName', 'SecondName', 'Email', 'Password') ";
    q += "VALUES('Michael', 'Dunaev', 'md@mail.com', 'MiDu');";
    auto res = query.exec(q);
    if(res)
        qDebug("Success insert");
    else
        qDebug("Failed insert");

    auto error = query.lastError().text().toStdString();

    qDebug(error.c_str());
}

MainApplication::MainApplication()
{
    dataBase = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    logWindow = new LoginWindow(this);
    regWindow = new RegistrationWindow(this);
    finregWindow = new RegistrationWindowFinal(this);
    buffer = new UserAccount();

    if(!getInitStatus())
        init();
    else
         dataBase->setDatabaseName("users.db");

}

MainApplication::~MainApplication()
{
    delete dataBase;
    delete logWindow;
    delete regWindow;
    delete buffer;
}

void MainApplication::exec()
{
    int remembrance = getRemembrance();

    if(remembrance == -1)
        showLoginWindow();

    //....
}

void MainApplication::init()
{
    QFile file("remembrance.txt");
    file.open(QIODevice::ReadWrite);
    QTextStream stream(&file);

    stream << -1;
    file.close();

    file.setFileName("count_of_users.txt");
    file.open(QIODevice::ReadWrite);
    QTextStream stream2(&file);
    stream2 << 0;

    dataBase->setDatabaseName("./users.db");
    dataBase->open();

    QSqlQuery query(*dataBase);
    QString q = "";
    q += "CREATE TABLE 'ListOfUsers'("
        " 'ID' INT AUTO_INCREMENT PRIMARY_KEY, "
        " 'FirstName' VARCHAR(40), "
        " 'SecondName' VARCHAR(40), "
        " 'DateOfBirth' VARCHAR(10), "
        " 'Email' VARCHAR(50), "
        " 'Password' VARCHAR(50), "
        " 'PhoneNumber' VARCHAR(13), "
        " 'Country' VARCHAR(25), "
        " 'Balance' FLOAT, "
        " 'SecretQuestionType' INT(2), "
        " 'SecretQuestionAnswer' VARCHAR(50) "
        ");";
    query.exec(q);
    dataBase->close();
}

bool MainApplication::getInitStatus()
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

int MainApplication::getRemembrance()
{
    QFile file("remembrance.txt");
    QTextStream stream(&file);

    file.open(QIODevice::ReadOnly);
    int id;
    stream >> id;
    file.close();

    return id;
}

void MainApplication::incrementCountOfUsers()
{
    QFile file("count_of_users.txt");
    int prevCount = getCountOfUsers();
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream stream(&file);

    stream << ++prevCount;
}

int MainApplication::getCountOfUsers()
{
    QFile file("count_of_users.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);

    int count;
    stream >> count;
    return count;
}

void MainApplication::setRemembrance(int _id)
{

    QFile file("remembrance.txt");
    QTextStream stream(&file);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    stream << _id;
    file.close();
}

void MainApplication::addAccount()
{
    dataBase->open();
    QSqlQuery query(*dataBase);
    QString q = "";
    q += "INSERT INTO 'ListOfUsers' "
         "(ID, FirstName, SecondName, DateOfBirth, Email, Password,"
         " PhoneNumber, Country, Balance, SecretQuestionType, SecretQuestionAnswer)"
         " VALUES(";
    q += ("'" + QString::number(getCountOfUsers()) + "', ");
    q += ("'" + buffer->fisrtName + "', ");
    q += ("'" + buffer->secondName + "', ");
    q += ("'" + buffer->birthDate + "', ");
    q += ("'" + buffer->email + "', ");
    q += ("'" + buffer->password + "', ");
    q += ("'" + buffer->phoneNumber + "', ");
    q += ("'" + buffer->country + "', ");
    q += ("'0.0', ");
    q += ("'" + QString::number(static_cast<int>(buffer->sq_type)) + "', ");
    q += ("'" + buffer->sq_answer + "'); ");

    query.exec(q);
    dataBase->close();
    incrementCountOfUsers();
}

QString MainApplication::lineEdit_StyleSheet()
{
    QString styleSheet = "";
    styleSheet += "color: rgb(255, 255, 255);"
                  "background-color: rgb(74, 79, 90);"
                  "font: 11pt Segoe UI;";

    return styleSheet;
}

QString MainApplication::lineEditError_StyleSheet()
{
    QString styleSheet = lineEdit_StyleSheet();
    styleSheet += "border-color: rgb(255, 0, 0);"
                  "border-style: solid;"
                  "border-width: 1px;";

    return styleSheet;
}

SearchResult MainApplication::findAccount(int &result_id, QString _email, QString _password)
{
    dataBase->open();
    QSqlQuery query(*dataBase);
    QString q = "";    
    q += "SELECT ID, Password FROM ListOfUsers WHERE Email = ";
    q += ("'" + _email + "';");
    query.exec(q);
    dataBase->close();
    if(!query.first())
        return SearchResult::EMAIL_NOT_FOUND;

    if(query.value(1).toString() != _password)
        return SearchResult::EMAIL_FOUND_WRONG_PASSWORD;

    result_id = query.value(0).toInt();
    return SearchResult::EMAIL_FOUND_RIGHT_PASSWORD;
}

void MainApplication::showLoginWindow()
{
    logWindow->show();
}

void MainApplication::hideLoginWindow()
{
    logWindow->hide();
}

void MainApplication::showRegistrationWindow()
{
    regWindow->show();
}

void MainApplication::hideRegistrationWindow()
{
    regWindow->hide();
}

void MainApplication::showFinalRegistrationWindow()
{
    finregWindow->show();
}

void MainApplication::hideFinalRegistrationWindow()
{
    finregWindow->hide();
}
