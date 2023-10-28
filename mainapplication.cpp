#include <QFile>
#include <QTextStream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QCryptographicHash>

#include "mainapplication.h"

MainApplication::MainApplication()
{
    dataBase = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    logWindow = new LoginWindow(this);
    regWindow = new RegistrationWindow(this);
    finregWindow = new RegistrationWindowFinal(this);
    support = new Support();
    mainWindow = nullptr;

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
    delete mainWindow;
    delete buffer;
    delete support;
}

void MainApplication::exec()
{
    int remembrance = getRemembrance();

    if(remembrance == -1)
    {
        logWindow->show();
    }
    else
    {
        setMainWindow(remembrance);
    }
}

void MainApplication::setMainWindow(int _id)
{
    mainWindow = new MainWindow(this, _id);
    mainWindow->show();
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
    file.close();

    file.setFileName("users.db");
    file.open(QIODevice::ReadWrite);
    file.close();

    dataBase->setDatabaseName("users.db");
    dataBase->open();

    QSqlQuery query(*dataBase);
    QString q = "";
    q += "CREATE TABLE 'ListOfUsers'("
        " 'ID' INT PRIMARY_KEY, "
        " 'FirstName' VARCHAR(40), "
        " 'SecondName' VARCHAR(40), "
        " 'DateOfBirth' VARCHAR(10), "
        " 'Email' VARCHAR(50), "
        " 'Password' VARCHAR(64), "
        " 'UserName' VARCHAR(30), "
        " 'PhoneNumber' VARCHAR(13), "
        " 'Country' VARCHAR(25), "
        " 'Balance' FLOAT, "
        " 'SecretQuestionType' INT(2), "
        " 'SecretQuestionAnswer' VARCHAR(50) "
        ");";
    query.exec(q);

    q.clear();
    query.clear();

    q += "CREATE TABLE 'UserLibraries'("
         "'ID' INT PRIMARY_KEY, "
         "'Games' VARCHAR(9));";
    query.exec(q);

    dataBase->close();

    file.setFileName("init_status.txt");
    file.open(QIODevice::ReadWrite | QIODevice::Truncate);
    QTextStream stream3(&file);
    stream3 << 1;
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
    q += "INSERT INTO ListOfUsers"
         "(ID, FirstName, SecondName, DateOfBirth, Email, UserName,Password,"
         " PhoneNumber, Country, Balance, SecretQuestionType, SecretQuestionAnswer)"
         " VALUES(";
    q += ("'" + QString::number(getCountOfUsers()) + "', ");
    q += ("'" + buffer->fisrtName + "', ");
    q += ("'" + buffer->secondName + "', ");
    q += ("'" + buffer->birthDate + "', ");
    q += ("'" + buffer->email + "', ");
    q += ("'" + buffer->email + "', ");
    q += ("'" + getHash(buffer->password) + "', ");
    q += ("'" + buffer->phoneNumber + "', ");
    q += ("'" + buffer->country + "', ");
    q += ("'0.0', ");
    q += ("'" + QString::number(static_cast<int>(buffer->sq_type)) + "', ");
    q += ("'" + buffer->sq_answer + "'); ");

    query.exec(q);

    q.clear();
    query.clear();
    q += "INSERT INTO UserLibraries"
         "(ID, Games) VALUES("
         "'" + QString::number(getCountOfUsers()) + "', "
         "'000000000');";
    query.exec(q);

    dataBase->close();
    incrementCountOfUsers();
}

void MainApplication::showMainWindow()
{
    mainWindow->show();
}

QString MainApplication::getHash(const QString &_password)
{
    auto res = QCryptographicHash::hash(_password.toUtf8(), QCryptographicHash::Sha256);

    return {res.toHex()};
}

QString MainApplication::lineEdit_StyleSheet()
{
    QString styleSheet = "";
    styleSheet += "color: rgb(255, 255, 255);"
                  "background-color: rgb(74, 79, 90);";


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

    if(query.value(1).toString() != getHash(_password))
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
