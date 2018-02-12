#include <QPushButton>
#include <QLayout>

#include "src/DapChainPointClient.h"
#include "DapUiWidgetChainOperations.h"
#include "ui_DapUiWidgetChainOperations.h"

DapUiWidgeChainOperations::DapUiWidgeChainOperations(QWidget * a_w) : DapUiWidgetAbstract(a_w)
{
    qDebug() << "[M] DapUiWidgeChainOperations::DapUiWidgeChainOperations";
    Ui::DapUiWidgetChainOperations ui;
    ui.setupUi(this);

    QPushButton* l_send = ui.Send;
    Q_ASSERT(l_send);
    QPushButton* l_request = ui.Request;
    Q_ASSERT(l_request);
    QPushButton* l_hold = ui.Hold;
    Q_ASSERT(l_hold);

    connect (l_send, &QPushButton::clicked, [=]{
        DapChainPointClient::me().sendMsg("clickedDapUiWidgeChainOperationsmoneySend");
    });

    connect (l_request, &QPushButton::clicked, [=]{
        DapChainPointClient::me().sendMsg("clickedDapUiWidgeChainOperationsmoneyRequest");
    });

    connect (l_hold, &QPushButton::clicked, [=]{
        DapChainPointClient::me().sendMsg("clickedDapUiWidgeChainOperationsmoneyHold");
    });

   /* QPushButton * l_moneySend    = new QPushButton (this);
    QPushButton * l_moneyRequest = new QPushButton (this);

    layout()->addWidget(l_moneyRequest);
    layout()->addWidget(l_moneySend);

    connect(l_send, &QPushButton::clicked, [=]{
        DapChainPointClient::me().sendMsg("clicked DapUiWidgeChainOperations moneySend");
    });

   / connect(l_moneyRequest, &QPushButton::clicked, [=]{
        DapChainPointClient::me().sendMsg("clicked DapUiWidgeChainOperations moneyRequest");
    });*/
}
