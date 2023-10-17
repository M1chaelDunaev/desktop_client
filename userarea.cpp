#include "userarea.h"
#include "ui_userarea.h"

UserArea::UserArea(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::UserArea)
{
    ui->setupUi(this);
    Layout = ui->horizontalLayout_2;
}

UserArea::~UserArea()
{
    delete ui;
}
