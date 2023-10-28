#ifndef ACCOUNTAREA_H
#define ACCOUNTAREA_H

#include <QWidget>
#include "mainwindow.h"

class MainWindow;

namespace Ui {
class AccountArea;
}

class AccountArea : public QWidget
{
    Q_OBJECT
    Ui::AccountArea *ui;

    MainWindow* mainWindow;
    void setUserName();
    void setUserAvatar();

public:
    explicit AccountArea(MainWindow *_mainWindow);
    ~AccountArea();


private slots:
    void on_EditProfile_pushButton_clicked();
};

#endif // ACCOUNTAREA_H
