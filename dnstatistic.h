#ifndef DNSTATISTIC_H
#define DNSTATISTIC_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <gr.h>
#include <qcustomplot.h>
#include <cstdlib>
#include <iostream>
#include <string>

namespace Ui {
class DNStatistic;
}

class DNStatistic : public QMainWindow
{
    Q_OBJECT

public:
    explicit DNStatistic(QWidget *parent = nullptr);
    ~DNStatistic();

private slots:
    void on_pFile1(QString file1, int i);

    void on_selFileButton_clicked();

    void on_pushSG_2_clicked();

public:

    double toDob(std::string str);

    double B(int x);

    Ui::DNStatistic *ui;

    QStringList::iterator itr1;

    QString str;

    QVector<QString> virName;   //Имя вирусняка

    double **massCor;   //Мат.статистика для графиков

    double *sizeS;

    int kol_vo;

};

#endif // DNSTATISTIC_H
