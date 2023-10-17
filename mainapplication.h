#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <QSqlDatabase>

#include "loginwindow.h"
#include "registrationwindow.h"
#include "registrationwindowfinal.h"
#include "mainwindow.h"
#include "useraccount.h"


enum class SearchResult
{
    EMAIL_NOT_FOUND,
    EMAIL_FOUND_WRONG_PASSWORD,
    EMAIL_FOUND_RIGHT_PASSWORD
};

class MainApplication
{
    //windows of app
    friend class LoginWindow;
    friend class RegistrationWindow;
    friend class RegistrationWindowFinal;
    friend class MainWindow;

    //private members:
    QSqlDatabase* dataBase;
    LoginWindow* logWindow;
    RegistrationWindow* regWindow;
    RegistrationWindowFinal* finregWindow;
    MainWindow* mainWindow;

    UserAccount* buffer;

    //private methods:
    void init();
    bool getInitStatus();

    void setRemembrance(int _id);
    int getRemembrance();

    void incrementCountOfUsers();
    int getCountOfUsers();

    void addAccount();

    QString getHash(const QString& _pass);

    QString lineEdit_StyleSheet();
    QString lineEditError_StyleSheet();

public:
    MainApplication();
    ~MainApplication();

    void exec();

    SearchResult findAccount(int& result_id, QString _email, QString _password);
    void addAccount(const UserAccount& _account);

    void showMainWindow();

    void showLoginWindow();
    void hideLoginWindow();
    void showRegistrationWindow();
    void hideRegistrationWindow();
    void showFinalRegistrationWindow();
    void hideFinalRegistrationWindow();
};

#endif // MAINAPPLICATION_H
