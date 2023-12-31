#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <QSqlDatabase>

#include "loginwindow.h"
#include "registrationwindow.h"
#include "registrationwindowfinal.h"
#include "mainwindow.h"
#include "useraccount.h"
#include "support.h"


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
    friend class Support;

    //private members:
    QSqlDatabase* dataBase;
    LoginWindow* logWindow;
    RegistrationWindow* regWindow;
    RegistrationWindowFinal* finregWindow;
    MainWindow* mainWindow;
    Support* support;

    UserAccount* buffer;

    //private methods:
    void init();
    bool getInitStatus();

    void setRemembrance(int _id);
    int getRemembrance();

    void incrementCountOfUsers();
    int getCountOfUsers();

    void addAccount();
    void updateUserAccount(int _id, const QString& _field, const QString& _value);
    void updateUserBalance(int _id, double _balance);
    void updateUserLibrary(int _id, const QString& _lib);

    void setMainWindow(int _id);

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
