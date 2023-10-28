#include "storeitem.h"
#include "ui_storeitem.h"

StoreItem::StoreItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StoreItem)
{
    ui->setupUi(this);
}

StoreItem::~StoreItem()
{
    delete ui;
}
