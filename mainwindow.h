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

class Store;
class Library;
class Community;
class AccountArea;
class UserAccount;

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{

    Q_OBJECT

    MainApplication* mainApp;
    QWidget* currentBigMenu;
    QWidget* currentSmallMenu;
    QStackedLayout* centralLayout;

    Store* store;
    Library* library;
    Community* community;
    AccountArea* accArea;

    UserAccount* currentAccount;



public:
    explicit MainWindow(MainApplication* app);

    void setAccount(int _id);
    void updateAccount(const QString& _field, const QString& _value);

    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);
private slots:
    void on_Store_pushButton_clicked();
};

#endif // MAINWINDOW_H
