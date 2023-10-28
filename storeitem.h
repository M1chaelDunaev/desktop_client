#ifndef STOREITEM_H
#define STOREITEM_H

#include <QWidget>

namespace Ui {
class StoreItem;
}

class StoreItem : public QWidget
{
    Q_OBJECT

public:
    explicit StoreItem(QWidget *parent = nullptr);
    ~StoreItem();

private:
    Ui::StoreItem *ui;
};

#endif // STOREITEM_H
