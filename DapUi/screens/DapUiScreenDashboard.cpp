#include "DapUiScreenDashboard.h"
#include "ui_DapUiScreenDashboard.h"

DapUiScreenDashboard::DapUiScreenDashboard() :DapUiScreen()
{
    qDebug() << "[M] << DapUiScreenDashboard";
    create<Ui::DapUiScreenDashboard,Ui::DapUiScreenDashboard,Ui::DapUiScreenDashboard>();
}

void DapUiScreenDashboard::initUi(QWidget * a_w, ScreenVariant a_variant)
{
    qDebug() << "[M] DapUiScreenDashboard::initUi";
    Q_UNUSED(a_w);
    Q_UNUSED(a_variant);

}
