#ifndef DAPUIWIDGETCHAINTRANSCTIONS_H
#define DAPUIWIDGETCHAINTRANSCTIONS_H

#include <QListWidget>
#include "src/widgets/DapUiWidgetAbstract.h"

class DapUiWidgetChainTransctions  : public DapUiWidgetAbstract
{
    Q_OBJECT
    int m_pointer = 0;
    QListWidget *m_list;
public:
    DapUiWidgetChainTransctions(QWidget * a_w);
};

#endif // DAPUIWIDGETCHAINTRANSCTIONS_H
