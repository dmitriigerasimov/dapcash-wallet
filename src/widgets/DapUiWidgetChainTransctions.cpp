#include <QLayout>
#include "DapUiWidgetChainTransctions.h"
#include "src/DapChainPointClient.h"
#include "ui_dapuiwidgetchaintransctions.h"


DapUiWidgetChainTransctions::DapUiWidgetChainTransctions(QWidget * a_w) : DapUiWidgetAbstract(a_w)
{
    qDebug() << "[M] DapUiWidgetChainTransctions::DapUiWidgetChainTransctions";
    /*Ui::dapuiwidgetchaintransctions thisui;
    thisui.setupUi(this);*/

    m_list = new QListWidget(this);

    // add transaction to list
    connect(&DapChainPointClient::me(), &DapChainPointClient::sigNewTransaction, [=](QString a_transaction) {
        QListWidgetItem * l_item = new QListWidgetItem(a_transaction);
        m_list->addItem(l_item);

        m_pointer += 1;
        if (m_pointer > 15) {
            m_pointer -= 1;
            m_list->deleteLater();
        }
    });
}

