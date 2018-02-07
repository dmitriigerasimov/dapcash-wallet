#include <QLabel>
#include "DapUiWidgetChainBallance.h"
#include "src/DapChainPointClient.h"

DapUiWidgetChainBallance::DapUiWidgetChainBallance(QWidget * a_w) : DapUiWidgetAbstract(a_w)
{
    qDebug() << "[M] DapUiWidgetChainBallance::DapUiWidgetChainBallance";

    QLabel *l_balance = new QLabel(this);
    l_balance->setText("0fjshdf sdf sdl;afj sadkf jsadkj slaj");
    connect(&DapChainPointClient::me(), &DapChainPointClient::sigBalanceChanged, [=](QString a_txt){
        l_balance->setText(a_txt);
    });
    l_balance->show();
}
