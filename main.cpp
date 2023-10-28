#include "mainapplication.h"
#include "functions.h"
#include <QApplication>
#include "store.h"
#include "test.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainApplication mainApp;
    //mainApp.exec();
    Test test;
    test.show();

    return a.exec();
}
