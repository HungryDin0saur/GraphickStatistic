#ifndef GRAPHICCK_H
#define GRAPHICCK_H

#include <QWidget>

namespace Ui {
class Graphicck;
}

class Graphicck : public QWidget
{
    Q_OBJECT

public:
    explicit Graphicck(QWidget *parent = 0);
    ~Graphicck();

private:
    Ui::Graphicck *ui;
};

#endif // GRAPHICCK_H
