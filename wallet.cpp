#include "wallet.h"
#include "ui_wallet.h"

Wallet::Wallet(MainWindow* _mainWindow) :
    QWidget(nullptr), ui(new Ui::Wallet), mainWindow(_mainWindow)
{
    ui->setupUi(this);
    setBalance();
}

Wallet::~Wallet()
{
    delete ui;
}

void Wallet::setBalance()
{

    ui->BalanceDisplay_label->setText(QString::number(mainWindow->currentAccount->balance) + '$');
}
