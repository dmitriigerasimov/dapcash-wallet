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
    TreeModel model(QString("a b/n aa bb/n sss vv/n"), this);


    /*QTreeWidget view(this);
    view.setModel(&model);
    view.setWindowTitle(tr("Last Block"));*/
    QTreeView* view = findChild<QTreeView* >("treeView");

    Q_ASSERT(view);
    view->setModel(&model);
    view->setWindowTitle("LastBlock");
   // view.setupViewport();

   // QLabel* l_
}


