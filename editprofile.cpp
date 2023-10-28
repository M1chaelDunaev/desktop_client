#include "editprofile.h"
#include "ui_editprofile.h"
#include "functions.h"
#include <QFileDialog>
#include <QImage>

EditProfile::EditProfile(MainWindow* _mainWindow) :
    QWidget(), ui(new Ui::EditProfile), mainWindow(_mainWindow)
{
    ui->setupUi(this);
    imageBuffer = nullptr;
    restoreWindow();
}

EditProfile::~EditProfile()
{
    delete ui;
    delete  imageBuffer;
}

void EditProfile::setLineEdits()
{
    ui->ProfileName_lineEdit->setText(mainWindow->currentAccount->userName);

    QString name = "";
    name += mainWindow->currentAccount->fisrtName + " ";
    name += mainWindow->currentAccount->secondName;
    ui->RealName_lineEdit->setText(name);
}

bool EditProfile::isCorrectProfileName(const QString &_profileName)
{
   for(QChar elem : _profileName)
   {
       if(!elem.isLetterOrNumber() && elem != '_' && elem != '-' && elem != '@' && elem != '.')
           return false;
   }

   return true;
}

bool EditProfile::isCorrectName(const QString &_name)
{
    QString firstName = "";
    QString secondName = "";
    char countOfSpaces = 0;

    for (QChar elem : _name)
    {
        if(elem.isSpace())
        {
            ++countOfSpaces;
            continue;
        }

        if(countOfSpaces == 0)
            firstName.push_back(elem);
        if(countOfSpaces == 1)
            secondName.push_back(elem);
    }

    if(countOfSpaces != 1)
        return false;

    return (checkCorrect_name(firstName) && checkCorrect_name(secondName));
}

void EditProfile::restoreLineEdits()
{
    ui->ProfileName_lineEdit->setStyleSheet(lineEdit_StyleSheet());
    ui->RealName_lineEdit->setStyleSheet(lineEdit_StyleSheet());
}

void EditProfile::restoreLabels()
{
    ui->UploadStatus_label->setStyleSheet(labelError_StyleSheet());
    ui->UploadStatus_label->setText("Image is not uploaded.");
    ui->Error_label->setStyleSheet(labelError_StyleSheet());
    ui->Error_label->setText("");
}

void EditProfile::restoreWindow()
{
    delete imageBuffer;
    imageBuffer = new QImage();

    restoreLineEdits();
    setLineEdits();
    restoreLabels();
}

QString EditProfile::lineEdit_StyleSheet()
{
    QString styleSheet = "";
    styleSheet += "color: rgb(255, 255, 255);"
                  "background-color: rgb(39, 41, 47);"
                  "border: 0px;";


    return styleSheet;
}

QString EditProfile::lineEditError_StyleSheet()
{
    QString styleSheet = lineEdit_StyleSheet();
    styleSheet += "border-color: rgb(255, 0, 0);"
                  "border-style: solid;"
                  "border-width: 1px;";

    return styleSheet;
}

QString EditProfile::labelError_StyleSheet()
{
    QString styleSheet = "";
    styleSheet += "color: rgb(200,0,0);"
                  "background-color: rgba(0,0,0,0);";

    return styleSheet;
}

QString EditProfile::labelSuccess_StyleSheet()
{
    QString styleSheet = "";
    styleSheet += "color: rgb(0,200,0);"
                  "background-color: rgba(0,0,0,0);";

    return styleSheet;
}


void EditProfile::on_UploadAvatar_pushButton_clicked()
{
    QFileDialog fd;
    fd.setDirectory("/home");
    //fd.setNameFilter("(*.png *.jpg *.bmp)");

    auto fileName = fd.getOpenFileName();   
    if(fileName == "")
        return;

    restoreLabels();

    if(!imageBuffer->load(fileName))
    {
        ui->UploadStatus_label->setText("Can't upload this file.\nIt can only have suffixes .jpg .jpeg .png .bmp");
        return;
    }

    if(imageBuffer->size().height() != imageBuffer->size().width())
    {
        ui->UploadStatus_label->setText("Image resolution error.\nIt must have the same width and length.");
        return;
    }

    ui->UploadStatus_label->setStyleSheet(labelSuccess_StyleSheet());
    ui->Status_label->setText("Image was successfuly uploaded.\nClick 'Save' to set it as your profile avatar.");
}


void EditProfile::on_Save_pushButton_clicked()
{
    restoreLineEdits();
    ui->Error_label->setStyleSheet(labelError_StyleSheet());
    QString profileName = ui->ProfileName_lineEdit->text();
    QString name = ui->RealName_lineEdit->text();

    if(!isCorrectProfileName(profileName))
    {
        ui->Error_label->setText("Incorrect profile name");
        ui->ProfileName_lineEdit->setStyleSheet(lineEditError_StyleSheet());
        return;
    }

    if(!isCorrectName(name))
    {
        ui->Error_label->setText("Incorrect real name");
        ui->RealName_lineEdit->setStyleSheet(lineEditError_StyleSheet());
        return;
    }

    if(profileName != mainWindow->currentAccount->userName)
    {

        mainWindow->currentAccount->userName = ui->ProfileName_lineEdit->text();
        mainWindow->updateUserAccount("UserName", ui->ProfileName_lineEdit->text());
    }

    if(name != (mainWindow->currentAccount->fisrtName + mainWindow->currentAccount->secondName))
    {

        //mainWindow->currentAccount->name = name;
        mainWindow->updateUserAccount("Name", name);
    }

    if(!imageBuffer->isNull())
    {
        QString newFileName = "Avatar_";
        newFileName += QString::number(mainWindow->currentAccount->id);
        newFileName += ".png";

        imageBuffer->scaled(167,167).save(newFileName);
    }

    ui->Error_label->setStyleSheet(labelSuccess_StyleSheet());
    ui->Error_label->setText("Changes saved.");

    //mainWindow->restoreWindows()
}


