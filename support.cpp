#include "support.h"
#include "ui_support.h"

Support::Support(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Support)
{
    ui->setupUi(this);
}

Support::~Support()
{
    delete ui;
}
