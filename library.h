#ifndef LIBRARY_H
#define LIBRARY_H

#include <QWidget>
#include "mainwindow.h"
class MainWindow;
namespace Ui {
class Library;
}

class Library : public QWidget
{
    Q_OBJECT
    Ui::Library *ui;

    MainWindow* mainWindow;
    void setGameList();
public:
    explicit Library(MainWindow* _mainWindow);
    ~Library();
};

#endif // LIBRARY_H
