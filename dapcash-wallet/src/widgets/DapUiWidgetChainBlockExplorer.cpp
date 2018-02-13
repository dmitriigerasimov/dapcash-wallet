#include "DapUiWidgetChainBlockExplorer.h"
#include "ui_DapUiWidgetChainBlockExplorer.h"
#include <QLabel>
#include <QTreeView>
#include "../TreeModel.h"


DapUiWidgetChainBlockExplorer::DapUiWidgetChainBlockExplorer(QWidget * a_w) : DapUiWidgetAbstract(a_w)
{
    qDebug() << "[M] DapUiWidgetChainBlockExplorer::DapUiWidgetChainBlockExplorer";
    Ui::DapUiWidgetChainBlockExplorer ui;
    ui.setupUi(this);
    TreeModel model(QString(), this);


    QTreeView view(this);
    view.setModel(&model);
    view.setWindowTitle(tr("Last Block"));
   // view.setupViewport();

   // QLabel* l_
}


