#include <QLabel>
#include "DapUiWidgetChainBallance.h"
#include "ui_DapUiWidgetChainBalance.h"
/*#include "ui_dapuiwidgetchaintransctions.h"*/
#include "src/DapChainPointClient.h"

DapUiWidgetChainBallance::DapUiWidgetChainBallance(QWidget * a_w) : DapUiWidgetAbstract(a_w)
{
    qDebug() << "[M] DapUiWidgetChainBallance::DapUiWidgetChainBallance";
    Ui::DapUiWidgetChainBalance ui;
    ui.setupUi(this);
    /*QLabel* l_balance = ui.summ;
    Q_ASSERT(l_balance);*/

    QLabel* l_balance = ui.a_balance;
    Q_ASSERT(l_balance);
    connect(&DapChainPointClient::me(), &DapChainPointClient::sigBalanceChanged,
            [=](QString a_balance, QString a_simpl, QString a_gold,
            QString a_another){
            Q_UNUSED(a_simpl);
            Q_UNUSED(a_gold);
            Q_UNUSED(a_another);
            l_balance->setText(a_balance);

    });

    QLabel* l_simpl = ui.a_simpl;
    Q_ASSERT(l_simpl);
    connect(&DapChainPointClient::me(), &DapChainPointClient::sigBalanceChanged,
            [=](QString a_balance, QString a_simpl, QString a_gold,
            QString a_another){
            Q_UNUSED(a_balance);
            Q_UNUSED(a_gold);
            Q_UNUSED(a_another);
            l_simpl->setText(a_simpl);

    });

    QLabel* l_gold = ui.a_gold;
    Q_ASSERT(l_gold);
    connect(&DapChainPointClient::me(), &DapChainPointClient::sigBalanceChanged,
            [=](QString a_balance, QString a_simpl, QString a_gold,
            QString a_another){
            Q_UNUSED(a_balance);
            Q_UNUSED(a_simpl);
            Q_UNUSED(a_another);
            l_gold->setText(a_gold);

    });

    QLabel* l_another = ui.a_another;
    Q_ASSERT(l_another);
    connect(&DapChainPointClient::me(), &DapChainPointClient::sigBalanceChanged,
            [=](QString a_balance, QString a_simpl, QString a_gold,
            QString a_another){
            Q_UNUSED(a_balance);
            Q_UNUSED(a_simpl);
            Q_UNUSED(a_gold);
            l_gold->setText(a_another);

    });

    /*InitLabel(ui, QString("a_balance"));
    InitLabel(ui, "a_gold");
    InitLabel(ui, "a_simple");
    InitLabel(ui, "a_another");*/
    /*for (int i=0; i<3; i++){
        QLabel* l_tok+i
    }*/


    /*QLabel *l_balance = new QLabel(this);
    l_balance->setText("0fjshdf sdf sdl;afj sadkf jsadkj slaj");
    connect(&DapChainPointClient::me(), &DapChainPointClient::sigBalanceChanged, [=](QString a_txt){
        l_balance->setText(a_txt);
    });
    l_balance->show();*/
}

void DapUiWidgetChainBallance::InitLabel(QWidget a_w, QString a_lbname){
    QLabel* l_lb = a_w.findChild<QLabel* >(a_lbname);
    Q_ASSERT(l_lb);

    connect(&DapChainPointClient::me(), &DapChainPointClient::sigBalanceChanged, [=](QString a_lbname){
        l_lb->setText(a_lbname);
    } );
}
