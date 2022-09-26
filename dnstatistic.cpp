#include "dnstatistic.h"
#include "ui_dnstatistic.h"

DNStatistic::DNStatistic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DNStatistic)
{
    ui->setupUi(this);
}

void DNStatistic::on_selFileButton_clicked()
{
    QStringList dir = QFileDialog::getOpenFileNames(this, "Выберите фаилы для анализа, max 50" , "");

    kol_vo = dir.size();

    if(kol_vo > 50)
    {
        QMessageBox::information(this, "Ошибка" , "Выбрано слишком много файлов");
        return;
    }

    massCor = new double*[kol_vo];
    sizeS = new double[kol_vo];

    dir.count();

    for(int i=0;i<kol_vo;i++)
    {
        DNStatistic::on_pFile1(dir.at(i), i);
    }

    return;
}

DNStatistic::~DNStatistic()
{
    delete ui;
}

double DNStatistic::toDob(std::string str)
{
    for(int i=0;str[i]!='\n';i++)
    {
        if(str[i] == '0')
        {
           if(str[i+1] == '.')
           {
               str = str.substr(i);
               break;
           }
        }
    }

    double n = atof(str.c_str());

    return n;
}

void DNStatistic::on_pFile1(QString file1, int i)
{
    QFile fd1(file1);

    QFileInfo fi(file1);

    if(!fd1.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this, "Ошибка" , "Ошибка считывания файла");
        return;
    }

    virName << fi.fileName();

    while(!fd1.atEnd())
    {
       fd1.readLine();
       sizeS[i]++;
    }

    massCor[i] = new double[(int)sizeS[i]];

    fd1.seek(0);

    std::string buf;

    for(int j=0;!fd1.atEnd();j++)
    {
       str = fd1.readLine();
       ui->domainViev1->append(str);
       buf = str.toLocal8Bit().constData();      
       massCor[i][j] = toDob(buf);
       //qDebug() << massCor[i][j];
    }

    str.clear();

    fd1.close();

    ui->pushSG_2->setEnabled(true);

    return;
}

void DNStatistic::on_pushSG_2_clicked()
{
    for(int i=0;i<kol_vo;i++)
    {
        Gr *grwidg = new Gr(i, sizeS, massCor, virName);
        grwidg->show();
    }
}
