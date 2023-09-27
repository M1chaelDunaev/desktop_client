#include "mainwindow.h"
#include "loginwindow.h"
#include"registrationwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;
    RegistrationWindow rw;
    w.show();
    return a.exec();
}
