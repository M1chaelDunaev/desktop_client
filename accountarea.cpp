#include "accountarea.h"
#include "ui_accountarea.h"

AccountArea::AccountArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountArea)
{
    ui->setupUi(this);
    mainLayout = ui->Main;
}

AccountArea::~AccountArea()
{
    delete ui;
}
