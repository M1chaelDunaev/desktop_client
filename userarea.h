#ifndef USERAREA_H
#define USERAREA_H

#include <QGroupBox>
#include "mainwindow.h"

namespace Ui {
class UserArea;
}

class UserArea : public QGroupBox
{
    Q_OBJECT
    friend class MainWindow;
public:
    explicit UserArea(QWidget *parent = nullptr);
    ~UserArea();

private:
    Ui::UserArea *ui;
    QLayout* Layout;
};

#endif // USERAREA_H
