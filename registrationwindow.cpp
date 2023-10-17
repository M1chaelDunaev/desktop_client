#include "registrationwindow.h"
#include "ui_registrationwindow.h"
#include "functions.h"

static bool agreement = false;

RegistrationWindow::RegistrationWindow(MainApplication* _app) :
    QWidget(nullptr), ui(new Ui::RegistrationWindow), mainApp(_app)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

    ui->Close_button->setIcon(QIcon(":/Close_cross.png"));
    ui->Agree_button->setIcon(QIcon(":/without_gal.png"));

}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

void RegistrationWindow::restoreEnterWidgets()
{
    ui->Email_lineEdit->setStyleSheet(mainApp->lineEdit_StyleSheet());
    ui->Password_lineEdit->setStyleSheet(mainApp->lineEdit_StyleSheet());
    ui->Countries_comboBox->setStyleSheet(mainApp->lineEdit_StyleSheet() + "border: 0px;");
}

void RegistrationWindow::restoreWindow()
{
    restoreEnterWidgets();
    ui->Email_lineEdit->clear();
    ui->Password_lineEdit->clear();
    ui->Countries_comboBox->setCurrentIndex(0);
    agreement = true;
    on_Agree_button_clicked();
}

void RegistrationWindow::on_Agree_button_clicked()
{
    if(!agreement)
        ui->Agree_button->setIcon(QIcon(":/gal.png"));
    else
        ui->Agree_button->setIcon(QIcon(":/without_gal.png"));

    agreement = !agreement;
}

void RegistrationWindow::on_Registration_button_clicked()
{
    restoreEnterWidgets();

    QString email = ui->Email_lineEdit->text();
    QString password = ui->Password_lineEdit->text();

    if(email.isEmpty())
    {
        ui->Error_window_label->setText("Field 'Email' is not filled.");
        ui->Email_lineEdit->setStyleSheet(mainApp->lineEditError_StyleSheet());
        return;
    }

    if(password.isEmpty())
    {
        ui->Error_window_label->setText("Field 'Password' is not filled.");
        ui->Password_lineEdit->setStyleSheet(mainApp->lineEditError_StyleSheet());
        return;
    }

    if(ui->Countries_comboBox->currentText() == "None")
    {
        ui->Error_window_label->setText("You have not chosen your country.");
        ui->Countries_comboBox->setStyleSheet(mainApp->lineEditError_StyleSheet());
        return;
    }

    if(!agreement)
    {
        ui->Error_window_label->setText("You have not confirmed your agreement.");
        return;
    }

    if(!checkCorrect_email(email))
    {
         ui->Error_window_label->setText("Incorrect email.");
         ui->Email_lineEdit->setStyleSheet(mainApp->lineEditError_StyleSheet());
         return;
    }

    if(!checkCorrect_password(password))
    {
        ui->Error_window_label->setText("Incorrect password.\nIt must be longer than 8 and contains letters and digits.");
        ui->Password_lineEdit->setStyleSheet(mainApp->lineEditError_StyleSheet());
        return;
    }

    int none = 0;
    SearchResult res = mainApp->findAccount(none, email, "");
    if(res == SearchResult::EMAIL_FOUND_WRONG_PASSWORD)
    {
        ui->Error_window_label->setText("User with the same email already exists.");
        ui->Email_lineEdit->setStyleSheet(mainApp->lineEditError_StyleSheet());
        return;
    }

    QString country = ui->Countries_comboBox->currentText();

    mainApp->buffer->email = email;
    mainApp->buffer->password = password;
    mainApp->buffer->country = country;

    hide();
    restoreEnterWidgets();
    mainApp->finregWindow->show();
}


void RegistrationWindow::on_GoBack_button_clicked()
{
    restoreEnterWidgets();
    hide();
    mainApp->logWindow->show();
}

