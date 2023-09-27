#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr);
    ~RegistrationWindow();

private slots:
    void on_Agree_button_clicked();

    void on_Close_button_clicked();

private:
    Ui::RegistrationWindow *ui;
    QWidget* selfPtr;
};

#endif // REGISTRATIONWINDOW_H