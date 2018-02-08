#include "DapUiWidgetChainNodeLogs.h"
#include "ui_DapUiChainNodeLogs.h"
#include "src/DapChainPointClient.h"


DapUiWidgetChainNodeLogs::DapUiWidgetChainNodeLogs(QWidget * a_w) : DapUiWidgetAbstract(a_w)
{
    qDebug() << "[M] DapUiWidgetChainNodeLogs::DapUiWidgetChainNodeLogs";
    Ui::DapUiChainNodeLogs ui;
    ui.setupUi(this);

    QTextEdit* l_logText = ui.Logs;
    Q_ASSERT(l_logText);
    l_logText->setReadOnly(true);
    connect(&DapChainPointClient::me(), &DapChainPointClient::sigNewLogSent, [=](QString a_log){
        l_logText->append(a_log);
    });
}
