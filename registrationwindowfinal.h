#ifndef REGISTRATIONWINDOWFINAL_H
#define REGISTRATIONWINDOWFINAL_H

#include <QWidget>
#include "mainapplication.h"

namespace Ui {
class RegistrationWindowFinal;
}

class RegistrationWindowFinal : public QWidget
{
    Q_OBJECT

      Ui::RegistrationWindowFinal *ui;
      MainApplication* mainApp;

public:
    explicit RegistrationWindowFinal(MainApplication* _app);
    ~RegistrationWindowFinal();

    void restoreEnterWidgets();
    void restoreWindow();

private slots:
    void on_Close_button_clicked(){ close(); };
    void on_GoBack_button_clicked();

    void setPhoneCode();
    void on_CompleteRegistration_button_clicked();

protected:
    void showEvent(QShowEvent *event) { setPhoneCode(); };
};

#endif // REGISTRATIONWINDOWFINAL_H
