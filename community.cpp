#include "community.h"
#include "ui_community.h"

Community::Community(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Community)
{
    ui->setupUi(this);
}

Community::~Community()
{
    delete ui;
}
