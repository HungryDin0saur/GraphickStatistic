#include "graphicck.h"
#include "ui_graphicck.h"

Graphicck::Graphicck(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Graphicck)
{
    ui->setupUi(this);
}

Graphicck::~Graphicck()
{
    delete ui;
}
