#include "mainapplication.h"
#include "functions.h"
#include <QApplication>
#include "store.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainApplication mainApp;
    //mainApp.exec();
    mainApp.showMainWindow();

    //Store ar;
    //ar.show();
    return a.exec();
}
