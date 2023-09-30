#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "registrationwindow.h"
#include "functions.h"

static bool rememberMe_activated = false;

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

    ui->Close_button->setIcon(QIcon(":/Close_cross.png"));
    ui->Remember_me_button->setIcon(QIcon(":/without_gal.png"));
    ui->Qrcode_label->setPixmap(QPixmap(":/qr.png"));
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_Close_button_clicked()
{
    close();
}


void LoginWindow::on_Remember_me_button_clicked()
{
    if(!rememberMe_activated)
        ui->Remember_me_button->setIcon(QIcon(":/gal.png"));
    else
        ui->Remember_me_button->setIcon(QIcon(":/without_gal.png"));

    rememberMe_activated = !rememberMe_activated;
}


void LoginWindow::on_Sign_in_button_clicked()
{
    QString email, password;
    email = ui->Email_lineEdit->text();
    password = ui->Password_lineEdit->text();

    if(email.isEmpty() || password.isEmpty())
    {
        ui->Error_window_label->setText("No all fields are filled.");
        ui->Password_lineEdit->clear();
        return;
    }

    int id = getRemembrance();
}





void LoginWindow::on_Registration_button_clicked()
{
    RegistrationWindow* registration = new RegistrationWindow();
    registration->exec();

    delete registration;
}

