#ifndef WALLET_H
#define WALLET_H

#include <QWidget>
#include "mainwindow.h"

class MainWindow;

namespace Ui {
class Wallet;
}

class Wallet : public QWidget
{
    Q_OBJECT

    Ui::Wallet *ui;
    MainWindow* mainWindow;

    void setBalance();

public:
    explicit Wallet(MainWindow* _mainWindow);
    ~Wallet();

};

#endif // WALLET_H
