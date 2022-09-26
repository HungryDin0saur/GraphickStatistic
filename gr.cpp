#include "gr.h"
#include "ui_gr.h"
#include <dnstatistic.h>

Gr::Gr(int i, double *sizeS, double **stdns, QVector<QString> virName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gr)
{
    ui->setupUi(this);

        wGraphic = new QCustomPlot();
        ui->gridLayout->addWidget(wGraphic,1,0,1,1);

        QVector<double>  ticks, y1(sizeS[i]);

        for(int j = 0;j<sizeS[i]; j++)
        {
            y1[j] = stdns[i][j];
        }


        for(int j = 1; j <= sizeS[i]; j++)
        {
            ticks << (j + 5);
        }

        //QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        //textTicker->addTicks(ticks);

        wGraphic->addGraph(wGraphic->xAxis, wGraphic->yAxis);

        wGraphic->graph(0)->setData(ticks, y1);

        wGraphic->xAxis->setLabel(virName[i]);
        wGraphic->yAxis->setLabel("y");

        //wGraphic->xAxis->setTicker(textTicker);

        wGraphic->xAxis->setRange(0, sizeS[i] * 2);
        wGraphic->yAxis->setRange(0, 1);

        ui->sizeInfo->setText(QString::number(sizeS[i]));

        wGraphic->replot();
}

Gr::~Gr()
{
    delete ui;
}

void Gr::on_buttonSave_clicked()
{

    QString path("C:/Users/HIkers/Desktop/graph1.jpg");

        QFile file1(path);

        if (!file1.open(QIODevice::WriteOnly))
        {
            qDebug() << file1.errorString();
        } else {
            wGraphic->saveJpg(path, 1500, 2000, 2, 100);
            qDebug() <<"save complete";
        }
}

void  Gr::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0) currentScale += 0.01;
    else currentScale -= 0.01;
}

