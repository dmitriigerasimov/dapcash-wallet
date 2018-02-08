#include "MainWindow.h"
#include "DapChainPointClient.h"
#include "screens/DapUiScreenDashboard.h"

MainWindow::MainWindow(QWidget *parent)
    : DapUiMainWindow(parent)
{
    qDebug() << "[M] MainWindow::MainWindow";
    connect(&DapChainPointClient::me(), &DapChainPointClient::sigSetDapUiScreenDashboard,[=]{
        newScreen(m_currentScreen = new DapUiScreenDashboard(this, sw()));
    });
    newScreen(m_currentScreen = new DapUiScreenDashboard(this, sw()));
}

MainWindow::~MainWindow()
{
}
