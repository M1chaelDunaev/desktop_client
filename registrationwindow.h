#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include "mainapplication.h"

namespace Ui {class RegistrationWindow;}

class MainApplication;

class RegistrationWindow : public QWidget
{
    Q_OBJECT

     Ui::RegistrationWindow *ui;
     MainApplication *mainApp;

public:
    explicit RegistrationWindow(MainApplication* _app);
    ~RegistrationWindow();

     void restoreEnterWidgets();
     void restoreWindow();

private slots:
    void on_Agree_button_clicked();

    void on_Close_button_clicked() { close(); };

    void on_Registration_button_clicked();
};

#endif // REGISTRATIONWINDOW_H
