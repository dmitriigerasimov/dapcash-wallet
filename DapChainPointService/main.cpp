#include <QCoreApplication>
#include "DapChainPoint.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DapChainPoint* p = new DapChainPoint();

    return a.exec();
}
