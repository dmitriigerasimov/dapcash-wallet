#include <QPushButton>
#include <QLayout>

#include "src/DapChainPointClient.h"
#include "DapUiWidgetChainOperations.h"

DapUiWidgeChainOperations::DapUiWidgeChainOperations(QWidget * a_w) : DapUiWidgetAbstract(a_w)
{
    qDebug() << "[M] DapUiWidgeChainOperations::DapUiWidgeChainOperations";
    QPushButton * l_moneySend    = new QPushButton (this);
    QPushButton * l_moneyRequest = new QPushButton (this);

    layout()->addWidget(l_moneyRequest);
    layout()->addWidget(l_moneySend);

    connect(l_moneySend, &QPushButton::clicked, [=]{
        DapChainPointClient::me().sendMsg("clicked DapUiWidgeChainOperations moneySend");
    });

    connect(l_moneyRequest, &QPushButton::clicked, [=]{
        DapChainPointClient::me().sendMsg("clicked DapUiWidgeChainOperations moneyRequest");
    });
}
