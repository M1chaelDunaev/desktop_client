#ifndef SUPPORT_H
#define SUPPORT_H

#include <QWidget>

namespace Ui {
class Support;
}

class Support : public QWidget
{
    Q_OBJECT

public:
    explicit Support(QWidget *parent = nullptr);
    ~Support();

private:
    Ui::Support *ui;
};

#endif // SUPPORT_H
