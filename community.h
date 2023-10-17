#ifndef COMMUNITY_H
#define COMMUNITY_H

#include <QWidget>

namespace Ui {
class Community;
}

class Community : public QWidget
{
    Q_OBJECT

public:
    explicit Community(QWidget *parent = nullptr);
    ~Community();

private:
    Ui::Community *ui;
};

#endif // COMMUNITY_H
