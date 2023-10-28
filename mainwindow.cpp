#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QDebug>



MainWindow::MainWindow(MainApplication* _app, int _id) :
    QWidget(nullptr), ui(new Ui::MainWindow), mainApp(_app)
{
    ui->setupUi(this);
    currentBigMenu = ui->Store_pushButton;
    currentSmallMenu = nullptr;
    currentBigMenu->setStyleSheet(bigMenuActive_styleSheet());

    currentAccount = new UserAccount();

    setAccount(_id);
    //Добавить аккаунт в конструкторы
    createWindows();
    makeCentralLayout();
    ui->Central_widget->setLayout(centralLayout);
}


MainWindow::~MainWindow()
{
    delete ui;
    deleteWindows();
    delete centralLayout;
}

void MainWindow::createWindows()
{
    store = new Store();
    library = new Library(this);
    community = new Community();
    accArea =  new AccountArea(this);
    editProfile = new EditProfile(this);
    wallet = new Wallet(this);
}

void MainWindow::deleteWindows()
{
    delete store;
    delete library;
    delete community;
    delete accArea;
    delete editProfile;
    delete wallet;
}

void MainWindow::makeCentralLayout()
{
    centralLayout = new QStackedLayout(ui->Central_widget);
    centralLayout->addWidget(store);
    centralLayout->addWidget(library);
    centralLayout->addWidget(community);
    centralLayout->addWidget(accArea);
    centralLayout->addWidget(editProfile);
    centralLayout->addWidget(wallet);
    centralLayout->addWidget(mainApp->support);
}

void MainWindow::setAccount(int _id)
{
    mainApp->dataBase->open();
    QSqlQuery query(*(mainApp->dataBase));

    QString q = "";
    q += "SELECT * FROM ListOfUsers WHERE id = "
         "'" + QString::number(_id) + "';";
    query.exec(q);

    query.first();
    currentAccount->id = query.value(0).toInt();
    currentAccount->fisrtName = query.value(1).toString();
    currentAccount->secondName = query.value(2).toString();
    currentAccount->birthDate = query.value(3).toString();
    currentAccount->email = query.value(4).toString();
    currentAccount->password = query.value(5).toString();
    currentAccount->userName = query.value(6).toString();
    currentAccount->phoneNumber = query.value(7).toString();
    currentAccount->country = query.value(8).toString();
    currentAccount->balance = query.value(9).toDouble();
    currentAccount->sq_type = static_cast<SecretQuestionTypes>(query.value(10).toInt());
    currentAccount->sq_answer = query.value(11).toString();

    setLibrary();
}

void MainWindow::setLibrary()
{
    QSqlQuery query(*(mainApp->dataBase));
    QString q = "";
    q += "SELECT * FROM UserLibraries WHERE ID = "
         "'" + QString::number(currentAccount->id) + "';";
    query.exec(q);

    query.first();

    QString res = query.value(1).toString();
    currentAccount->lib.setValues(res);

    mainApp->dataBase->close();
}

void MainWindow::setCurrentMenu(QPushButton* _newMenu, char _type)
{
    if(currentBigMenu)
    {
        currentBigMenu->setStyleSheet(bigMenuBase_styleSheet());
        currentBigMenu = nullptr;
    }
    else if(currentSmallMenu)
    {
        currentSmallMenu->setStyleSheet(smallMenuBase_styleSheet());
        currentSmallMenu = nullptr;
    }

    if(_type == 'B')
    {
        currentBigMenu = _newMenu;
        currentBigMenu->setStyleSheet(bigMenuActive_styleSheet());
    }
    else
    {
        currentSmallMenu = _newMenu;
        currentSmallMenu->setStyleSheet(smallMenuActive_styleSheet());
    }

}

void MainWindow::updateUserAccount(const QString &_field, const QString &_value)
{

}



QString MainWindow::bigMenuBase_styleSheet()
{
    QString styleSheet = "";
    styleSheet += "QPushButton{ color: rgb(255, 255, 255); font: 16pt Arial; "
                  "background-color: rgba(0, 0, 0, 0); border: 0px;} "
                  "QPushButton:hover{ text-decoration: underline; }";

    return styleSheet;
}

QString MainWindow::smallMenuBase_styleSheet()
{
    QString styleSheet = "";
    styleSheet += "QPushButton{ color: rgb(182, 182, 182); font: 9pt Arial; "
                  "background-color: rgba(0, 0, 0, 0); border: 0px;} "
                  "QPushButton:hover{ color: rgb(255, 255, 255); }";

    return styleSheet;
}

QString MainWindow::bigMenuActive_styleSheet()
{
    QString styleSheet = "";
    styleSheet += "color: rgb(55, 225, 255); font: 16pt Arial; border: 0px; "
                  "background-color: rgba(0, 0, 0, 0); text-decoration: underline;";

    return styleSheet;
}

QString MainWindow::smallMenuActive_styleSheet()
{
    QString styleSheet = "";
    styleSheet += "color: rgb(255, 255, 255); font: 9pt Arial; border: 0px; "
                  "background-color: rgba(0, 0, 0, 0); text-decoration: underline;";

    return styleSheet;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
     //ui->Central_widget->setLayout(ua->Layout);
}


void MainWindow::on_Store_pushButton_clicked()
{
    if(ui->Store_pushButton == currentBigMenu)
        return;

    setCurrentMenu(ui->Store_pushButton, 'B');
    centralLayout->setCurrentWidget(store);

}


void MainWindow::on_Library_pushButton_clicked()
{
    if(ui->Library_pushButton == currentBigMenu)
        return;

    setCurrentMenu(ui->Library_pushButton, 'B');
    centralLayout->setCurrentWidget(library);
}


void MainWindow::on_Community_pushButton_clicked()
{
    if(ui->Community_pushButton == currentBigMenu)
        return;

    setCurrentMenu(ui->Community_pushButton, 'B');
    centralLayout->setCurrentWidget(community);
}


void MainWindow::on_Account_pushButton_clicked()
{
    if(ui->Account_pushButton == currentBigMenu)
        return;

    setCurrentMenu(ui->Account_pushButton, 'B');
    centralLayout->setCurrentWidget(accArea);
}


void MainWindow::on_Settings_pushButton_clicked()
{
    if(ui->Settings_pushButton == currentSmallMenu)
        return;

    setCurrentMenu(ui->Settings_pushButton, 'S');
}


void MainWindow::on_Support_pushButton_clicked()
{
    if(ui->Support_pushButton == currentSmallMenu)
        return;

    setCurrentMenu(ui->Support_pushButton, 'S');
    centralLayout->setCurrentWidget(mainApp->support);
}


void MainWindow::on_Friends_pushButton_clicked()
{
    if(ui->Friends_pushButton == currentSmallMenu)
        return;

    setCurrentMenu(ui->Friends_pushButton, 'S');
    centralLayout->setCurrentWidget(community);
}


void MainWindow::on_Wallet_pushButton_clicked()
{
    if(ui->Wallet_pushButton == currentSmallMenu)
        return;

    setCurrentMenu(ui->Wallet_pushButton, 'S');
    centralLayout->setCurrentWidget(wallet);
}

