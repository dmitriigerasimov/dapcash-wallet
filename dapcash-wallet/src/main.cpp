#include <QApplication>
#include <QFile>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile appStyleF;
    appStyleF.setFileName(QString(":/main_desktop.css"));
    appStyleF.open(QFile::ReadOnly); // Load style
    QString appStyleS = appStyleF.readAll();
    a.setStyleSheet(appStyleS);

    MainWindow w;
    w.show();

    return a.exec();
}
