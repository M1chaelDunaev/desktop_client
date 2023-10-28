#include "library.h"
#include "ui_library.h"

Library::Library(MainWindow* _mainWindow) :
    QWidget(nullptr), mainWindow(_mainWindow), ui(new Ui::Library)
{
    ui->setupUi(this);
    setGameList();

}

Library::~Library()
{
    delete ui;
}

void Library::setGameList()
{
    if(mainWindow->currentAccount->lib.eldenRing)
        ui->ER_widget->show();
    else
        ui->ER_widget->hide();


    if(mainWindow->currentAccount->lib.godOfWar)
        ui->GOW_widget->show();
    else
         ui->GOW_widget->hide();


    if(mainWindow->currentAccount->lib.stray)
        ui->Str_widget->show();
    else
        ui->Str_widget->hide();


    if(mainWindow->currentAccount->lib.plagueTale)
        ui->PT_widget->show();
    else
        ui->PT_widget->hide();


    if(mainWindow->currentAccount->lib.horizon)
        ui->HFW_widget->show();
    else
        ui->HFW_widget->hide();


    if(mainWindow->currentAccount->lib.lastOfUs)
        ui->LOU_widget->show();
    else
        ui->LOU_widget->hide();


    if(mainWindow->currentAccount->lib.cuphead)
        ui->Cup_widget->show();
    else
        ui->Cup_widget->hide();


    if(mainWindow->currentAccount->lib.dyingLight)
        ui->DL_widget->show();
    else
        ui->DL_widget->hide();


    if(mainWindow->currentAccount->lib.warhammer)
        ui->War_widget->show();
    else
        ui->War_widget->hide();
}
