#include "accountarea.h"
#include "ui_accountarea.h"
#include <QPixmap>
#include <QFile>
#include <QImage>


AccountArea::AccountArea(MainWindow *_mainWindow) :
    QWidget(nullptr), ui(new Ui::AccountArea), mainWindow(_mainWindow)
{
    ui->setupUi(this);
    setUserName();
    setUserAvatar();

}

AccountArea::~AccountArea()
{
    delete ui;
}

void AccountArea::setUserName()
{
    if(mainWindow->currentAccount->userName.size() > 20)
    {
        QString login = "";
        for(int i = 0; i < 20; ++i)
        {
            login.push_back(mainWindow->currentAccount->userName[i]);
        }
        login += "...";

        ui->Login_label->setText(login);
    }
    else
    {
        ui->Login_label->setText(mainWindow->currentAccount->userName);
    }
}

void AccountArea::setUserAvatar()
{
    QString fileName = "";
    fileName += "Avatar_" + QString::number(mainWindow->currentAccount->id);
    fileName += ".png";

    QPixmap avatar(fileName);
    if(avatar.isNull())
    {
        return;
    }

    ui->Avatar_label->setPixmap(avatar);

}

void AccountArea::on_EditProfile_pushButton_clicked()
{
    mainWindow->centralLayout->setCurrentWidget(mainWindow->editProfile);
}

