#include "dnstatistic.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DNStatistic w;
    w.show();

    return a.exec();
}
