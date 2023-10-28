#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "registrationwindow.h"
#include "functions.h"
#include "QDebug"

static bool rememberMe_activated = false;

LoginWindow::LoginWindow(MainApplication *app) :
    QWidget(nullptr), ui(new Ui::LoginWindow), mainApp(app)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

    restoreLineEdits();

    ui->Close_button->setIcon(QIcon(":/Close_cross.png"));
    ui->Remember_me_button->setIcon(QIcon(":/without_gal.png"));
    ui->Qrcode_label->setPixmap(QPixmap(":/qr.png"));
}

LoginWindow::~LoginWindow()
{
    delete ui;
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
    restoreLineEdits();

    QString email, password;
    email = ui->Email_lineEdit->text();
    password = ui->Password_lineEdit->text();

    if(email.isEmpty())
    {
        ui->Error_window_label->setText("Field 'Email' is not filled.");
        ui->Email_lineEdit->setStyleSheet(mainApp->lineEditError_StyleSheet());
        ui->Password_lineEdit->clear();
        return;
    }

    if(password.isEmpty())
    {
        ui->Error_window_label->setText("Field 'Password' is not filled.");
        ui->Password_lineEdit->setStyleSheet(mainApp->lineEditError_StyleSheet() + "font: 12px;");
        return;
    }

    int id = -1;
    auto res = mainApp->findAccount(id, email, password);

    switch (res)
    {
    case SearchResult::EMAIL_NOT_FOUND:
        {
            ui->Error_window_label->setText("Account not found.");
            ui->Email_lineEdit->setStyleSheet(mainApp->lineEditError_StyleSheet());
            ui->Password_lineEdit->clear();
            return;
        }
    case SearchResult::EMAIL_FOUND_WRONG_PASSWORD:
        {
            ui->Error_window_label->setText("Wrong password.");
            ui->Password_lineEdit->setStyleSheet(mainApp->lineEditError_StyleSheet() + "font: 12px;");
            ui->Password_lineEdit->clear();
            return;
        }
    case SearchResult::EMAIL_FOUND_RIGHT_PASSWORD:
        {
            ui->Error_window_label->setText("Success!");
            ui->Password_lineEdit->clear();
            restoreLineEdits();

            if(rememberMe_activated)
                mainApp->setRemembrance(id);

            hide();
            mainApp->setMainWindow(id);
            return;
        }
    };
}

void LoginWindow::restoreLineEdits()
{
    ui->Email_lineEdit->setStyleSheet(mainApp->lineEdit_StyleSheet());
    ui->Password_lineEdit->setStyleSheet(mainApp->lineEdit_StyleSheet() + "font: 12px;");
}

void LoginWindow::on_Registration_button_clicked()
{
    mainApp->hideLoginWindow();
    mainApp->showRegistrationWindow();
}

