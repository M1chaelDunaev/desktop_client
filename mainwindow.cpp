#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userarea.h"
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QDebug>



MainWindow::MainWindow(MainApplication* app) :
    QWidget(nullptr), ui(new Ui::MainWindow), mainApp(app)
{
    ui->setupUi(this);
    currentBigMenu = ui->Store_pushButton;
    currentSmallMenu = nullptr;
    currentAccount = new UserAccount();

    store = new Store();
    library = new Library();
    community = new Community();
    accArea =  new AccountArea();

    centralLayout = new QStackedLayout(ui->Central_widget);
    centralLayout->addWidget(store);
    centralLayout->addWidget(library);
    centralLayout->addWidget(community);
    centralLayout->addWidget(accArea);

    ui->Central_widget->setLayout(centralLayout);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete store;
    delete library;
    delete community;
    delete accArea;
}

void MainWindow::setAccount(int _id)
{
    mainApp->dataBase->open();
    QSqlQuery query(*(mainApp->dataBase));

    QString q = "";
    q += "SELECT * FROM ListOfUsers Where id = "
         "'" + QString::number(_id) + "';";
    query.exec(q);

    query.first();
    currentAccount->id = query.value(0).toInt();
    currentAccount->fisrtName = query.value(1).toString();
    currentAccount->secondName = query.value(2).toString();
    currentAccount->birthDate = query.value(3).toString();
    currentAccount->email = query.value(4).toString();
    currentAccount->password = query.value(5).toString();
    currentAccount->phoneNumber = query.value(6).toString();






    mainApp->dataBase->close();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
     //ui->Central_widget->setLayout(ua->Layout);
}


void MainWindow::on_Store_pushButton_clicked()
{
    centralLayout->setCurrentWidget(store);
}

