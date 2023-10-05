#include "mainapplication.h"
#include "functions.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainApplication mainApp;
    mainApp.exec();
    int b;

    return a.exec();
}
