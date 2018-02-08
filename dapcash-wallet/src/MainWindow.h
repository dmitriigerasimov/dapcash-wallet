#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "libdap-qt-ui/DapUiScreen.h"
#include "libdap-qt-ui/DapUiMainWindow.h"

class MainWindow : public DapUiMainWindow
{
    Q_OBJECT

    DapUiScreen * m_currentScreen;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
