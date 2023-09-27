#include "registrationwindow.h"
#include "ui_registrationwindow.h"

static bool agreement = false;

RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationWindow)
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

void RegistrationWindow::on_Agree_button_clicked()
{
    if(!agreement)
        ui->Agree_button->setIcon(QIcon(":/gal.png"));
    else
        ui->Agree_button->setIcon(QIcon(":/without_gal.png"));

    agreement = !agreement;
}


void RegistrationWindow::on_Close_button_clicked()
{
    close();
}

