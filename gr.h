#ifndef GR_H
#define GR_H

#include <QWidget>
#include <QDebug>
#include <dnstatistic.h>
#include <qcustomplot.h>
#include <QGraphicsWidget>

namespace Ui {
class Gr;
}

class Gr : public QWidget
{
    Q_OBJECT

public:
    explicit Gr(int i, double *sizeS,double **stdns, QVector<QString> virName, QWidget *parent = 0);
    ~Gr();
    float currentScale = 1;

private slots:
    void on_buttonSave_clicked();

private:
    Ui::Gr *ui;

        QCustomPlot *wGraphic;

protected:

      void wheelEvent(QWheelEvent *event);
};

#endif // GR_H
