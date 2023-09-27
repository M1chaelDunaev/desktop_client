#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_Close_button_clicked();


    void on_Remember_me_button_clicked();

    void on_Sign_in_button_clicked();

    void on_Registration_button_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
