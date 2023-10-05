#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "mainapplication.h"

class MainApplication;

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

     Ui::LoginWindow *ui;
     MainApplication* mainApp;

     void restoreLineEdits();
public:
     explicit LoginWindow(MainApplication* app);
    ~LoginWindow();

private slots:
    void on_Close_button_clicked() { close();};

    void on_Remember_me_button_clicked();

    void on_Sign_in_button_clicked();

    void on_Registration_button_clicked();

};

#endif // LOGINWINDOW_H
