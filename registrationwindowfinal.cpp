#include "registrationwindowfinal.h"
#include "ui_registrationwindowfinal.h"
#include "useraccount.h"
#include "functions.h"
#include <QDebug>

RegistrationWindowFinal::RegistrationWindowFinal(MainApplication* _app) :
    QWidget(nullptr), ui(new Ui::RegistrationWindowFinal), mainApp(_app)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    ui->Close_button->setIcon(QIcon(":/Close_cross.png"));

}

RegistrationWindowFinal::~RegistrationWindowFinal()
{
    delete ui;
}

void RegistrationWindowFinal::restoreEnterWidgets()
{
    ui->FirstName_lineEdit->setStyleSheet(mainApp->lineEdit_StyleSheet());
    ui->SecondName_lineEdit->setStyleSheet(mainApp->lineEdit_StyleSheet());
    ui->PhoneNumber_lineEdit->setStyleSheet(mainApp->lineEdit_StyleSheet());
    ui->dateEdit->setStyleSheet(mainApp->lineEdit_StyleSheet() + "border: 0px;");
    ui->SecretQuestion_comboBox->setStyleSheet(mainApp->lineEdit_StyleSheet() + "border: 0px;");
    ui->Answer_lineEdit->setStyleSheet(mainApp->lineEdit_StyleSheet());
}

void RegistrationWindowFinal::restoreWindow()
{
    restoreEnterWidgets();
    ui->FirstName_lineEdit->clear();
    ui->SecondName_lineEdit->clear();
    ui->PhoneNumber_lineEdit->clear();
    ui->dateEdit->setDate(QDate(2000, 01, 01));
    ui->SecretQuestion_comboBox->setCurrentIndex(0);
    ui->Answer_lineEdit->clear();
}

void RegistrationWindowFinal::on_GoBack_button_clicked()
{
    hide();
    restoreEnterWidgets();
    mainApp->regWindow->show();
}

void RegistrationWindowFinal::setPhoneCode()
{
    QString country = mainApp->buffer->country;

    if(country == "USA" || country == "Canada")
        ui->PhoneCode_label->setText("+1 ");
    if(country == "Russia")
        ui->PhoneCode_label->setText("+7 ");
    if(country == "UK")
        ui->PhoneCode_label->setText("+44 ");
    if(country == "France")
        ui->PhoneCode_label->setText("+33 ");
    if(country == "Germany")
        ui->PhoneCode_label->setText("+49 ");
    if(country == "Japan")
        ui->PhoneCode_label->setText("+81 ");
    if(country == "China")
        ui->PhoneCode_label->setText("+86 ");
}

void RegistrationWindowFinal::on_CompleteRegistration_button_clicked()
{
    restoreEnterWidgets();

    QString firstName = ui->FirstName_lineEdit->text();
    QString secondName = ui->SecondName_lineEdit->text();
    QString phoneNumber = ui->PhoneNumber_lineEdit->text();
    QString birthDate = ui->dateEdit->text();
    QString question = ui->SecretQuestion_comboBox->currentText();
    QString answer = ui->Answer_lineEdit->text();

    if(firstName.isEmpty())
    {
        ui->Error_window_label->setText("Field 'First Name' is not filled.");
        ui->FirstName_lineEdit->setStyleSheet(mainApp->lineEditError_StyleSheet());
        return;
    }

    if(secondName.isEmpty())
    {
        ui->Error_window_label->setText("Field 'Second Name' is not filled.");
        ui->SecondName_lineEdit->setStyleSheet(mainApp->lineEditError_StyleSheet());
        return;
    }

    if(phoneNumber.isEmpty())
    {
        ui->Error_window_label->setText("Field 'Second Name' is not filled.");
        ui->PhoneNumber_lineEdit->setStyleSheet(mainApp->lineEditError_StyleSheet());
        return;
    }

    if(birthDate.isEmpty())
    {
        ui->Error_window_label->setText("Field 'Date of Birth' is not filled.");
        ui->dateEdit->setStyleSheet(mainApp->lineEditError_StyleSheet());
        return;
    }

    if(answer.isEmpty())
    {
        ui->Error_window_label->setText("Field 'Answer' is not filled.");
        ui->Answer_lineEdit->setStyleSheet(mainApp->lineEditError_StyleSheet());
        return;
    }

    if(question == "None")
    {
        ui->Error_window_label->setText("You have not chosen the secret question.");
        ui->SecretQuestion_comboBox->setStyleSheet(mainApp->lineEditError_StyleSheet());
        return;
    }

    if(!checkCorrect_name(firstName))
    {
        ui->Error_window_label->setText("Incorect First Name.\nThis field can contain only letters.");
        ui->FirstName_lineEdit->setStyleSheet(mainApp->lineEditError_StyleSheet());
        return;
    }

    if(!checkCorrect_name(secondName))
    {
        ui->Error_window_label->setText("Incorect Second Name.\nThis field can contain only letters.");
        ui->SecondName_lineEdit->setStyleSheet(mainApp->lineEditError_StyleSheet());
        return;
    }

    if(!checkCorrect_phoneNumber(phoneNumber))
    {
        ui->Error_window_label->setText("Incorect phone number.\nThis field can contain digits, spaces and symbols '-'");
        ui->PhoneNumber_lineEdit->setStyleSheet(mainApp->lineEditError_StyleSheet());
        return;
    }

    if(!checkCorrect_date(birthDate))
    {
        ui->Error_window_label->setText("Incorrect date of Birth.\nYou must be older than 13.");
        ui->dateEdit->setStyleSheet(mainApp->lineEditError_StyleSheet());
        return;
    }

    QString standardNumber = (ui->PhoneCode_label->text() + getStandardNumber(phoneNumber));
    SecretQuestionTypes sqType = getQuestionType(question);

    mainApp->buffer->fisrtName = firstName;
    mainApp->buffer->secondName = secondName;
    mainApp->buffer->phoneNumber = standardNumber;
    mainApp->buffer->birthDate = birthDate;
    mainApp->buffer->sq_type = sqType;
    mainApp->buffer->sq_answer = answer;
    mainApp->buffer->balance = 0.0;

    mainApp->addAccount();

    mainApp->regWindow->restoreWindow();
    restoreWindow();
    hide();
    mainApp->logWindow->show();
}
