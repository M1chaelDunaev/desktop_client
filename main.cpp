#include "mainwindow.h"
#include "loginwindow.h"
#include"registrationwindow.h"
#include "functions.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    init();
    //if(!getInitStatus())
        //init();

    LoginWindow w;
    RegistrationWindow rw;
    w.show();
    return a.exec();
}
