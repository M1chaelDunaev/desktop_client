#ifndef ACCOUNTAREA_H
#define ACCOUNTAREA_H

#include <QWidget>

namespace Ui {
class AccountArea;
}

class AccountArea : public QWidget
{
    Q_OBJECT

public:
    explicit AccountArea(QWidget *parent = nullptr);
    ~AccountArea();
    QLayout* mainLayout;

private:
    Ui::AccountArea *ui;
};

#endif // ACCOUNTAREA_H
