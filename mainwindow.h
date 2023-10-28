#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QStackedLayout>
#include "mainapplication.h"
#include "accountarea.h"
#include "store.h"
#include "community.h"
#include "library.h"
#include "editprofile.h"
#include "wallet.h"

class Store;
class Community;
class UserAccount;

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    friend class AccountArea;
    friend class EditProfile;
    friend class Library;
    friend class Wallet;

    Q_OBJECT

    MainApplication* mainApp;
    QWidget* currentBigMenu;
    QWidget* currentSmallMenu;
    QStackedLayout* centralLayout;

    Store* store;
    Library* library;
    Community* community;
    AccountArea* accArea;

    EditProfile* editProfile;
    Wallet* wallet;

    UserAccount* currentAccount;

    void createWindows();
    void deleteWindows();
    void makeCentralLayout();

    void setLibrary();
    void setCurrentMenu(QPushButton* _newMenu, char _type);

    void updateUserAccount(const QString& _field, const QString& _value);
    void updateUserBalance();
    void updateUserLibrary(); //Получает информацию из currentAccount

    QString bigMenuBase_styleSheet();
    QString smallMenuBase_styleSheet();
    QString bigMenuActive_styleSheet();
    QString smallMenuActive_styleSheet();

public:
    explicit MainWindow(MainApplication* _app, int _id);

    void setAccount(int _id);

    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);
private slots:
    void on_Store_pushButton_clicked();
    void on_Library_pushButton_clicked();
    void on_Community_pushButton_clicked();
    void on_Account_pushButton_clicked();
    void on_Settings_pushButton_clicked();
    void on_Support_pushButton_clicked();
    void on_Friends_pushButton_clicked();
    void on_Wallet_pushButton_clicked();
};

#endif // MAINWINDOW_H
