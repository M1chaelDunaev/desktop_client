#ifndef EDITPROFILE_H
#define EDITPROFILE_H

#include <QWidget>
#include <QImage>
#include "mainwindow.h"

class MainWindow;

namespace Ui {
class EditProfile;
}

class EditProfile : public QWidget
{
    Q_OBJECT
    Ui::EditProfile *ui;

    MainWindow* mainWindow;
    QImage* imageBuffer;

    void setLineEdits();
    bool isCorrectProfileName(const QString& _profileName);
    bool isCorrectName(const QString& _name);

    void restoreLineEdits();
    void restoreLabels();
    void restoreWindow();

    QString lineEdit_StyleSheet();
    QString lineEditError_StyleSheet();
    QString labelError_StyleSheet();
    QString labelSuccess_StyleSheet();

public:
    explicit EditProfile(MainWindow* _mainWindow);
    ~EditProfile();
private slots:
    void on_UploadAvatar_pushButton_clicked();
    void on_Save_pushButton_clicked();

    // QWidget interface
protected:
    virtual void hideEvent(QHideEvent *event) override {restoreWindow();};
};

#endif // EDITPROFILE_H
