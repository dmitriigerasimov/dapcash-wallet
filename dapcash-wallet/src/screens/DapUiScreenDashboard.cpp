#include "DapUiScreenDashboard.h"
#include "DapUiWidgetChainBallance.h"
#include "DapUiWidgetChainOperations.h"
#include "DapUiWidgetChainTransctions.h"
#include "DapUiWidgetChainNodeLogs.h"
#include "DapUiWidgetChainBlockExplorer.h"
#include "ui_DapUiScreenDashboard.h"

DapUiScreenDashboard::DapUiScreenDashboard(QObject *a_parent, QStackedWidget * a_sw) : DapUiScreen(a_parent, a_sw)
{
    qDebug() << "[M] DapUiScreenDashboard::DapUiScreenDashboard";
    create<Ui::DapUiScreenDashboard,Ui::DapUiScreenDashboard,Ui::DapUiScreenDashboard>();
}

void DapUiScreenDashboard::initUi(QWidget * a_w, ScreenVariant a_variant)
{
    qDebug() << "[M] DapUiScreenDashboard::initUi";
    Q_UNUSED(a_w);
    Q_UNUSED(a_variant);

    QLayout* l_upperLay = a_w->findChild<QLayout* >("horizontalLayout");
    Q_ASSERT(l_upperLay);

    DapUiWidgetAbstract* l_operatins = a_w->findChild<DapUiWidgetAbstract* >("Operatins");
    Q_ASSERT(l_operatins);
    l_operatins = new DapUiWidgeChainOperations(a_w);

    DapUiWidgetAbstract* l_ballance = a_w->findChild<DapUiWidgetAbstract* >("Ballance");
    Q_ASSERT(l_ballance);
    l_ballance = new DapUiWidgetChainBallance(a_w);

    DapUiWidgetAbstract* l_trasctions = a_w->findChild<DapUiWidgetAbstract* >("Trasctions");
    Q_ASSERT(l_trasctions);
    l_trasctions = new DapUiWidgetChainTransctions(a_w);

    DapUiWidgetAbstract* l_explorer = a_w->findChild<DapUiWidgetAbstract* >("BlockExplorer");
    Q_ASSERT(l_explorer);
    l_explorer = new DapUiWidgetChainBlockExplorer(a_w);

    l_upperLay->addWidget(l_operatins);
    l_upperLay->addWidget(l_ballance);
    l_upperLay->addWidget(l_trasctions);

    QLayout* l_downerLay = a_w->findChild<QLayout* >("horizontalLayout_2");
    Q_ASSERT(l_downerLay);

    DapUiWidgetAbstract* l_logs = a_w->findChild<DapUiWidgetAbstract* >("Logs");
    Q_ASSERT(l_logs);
    l_logs = new DapUiWidgetChainNodeLogs(a_w);

    l_downerLay->addWidget(l_logs);
    l_downerLay->addWidget(l_explorer);

    //Logs
}
