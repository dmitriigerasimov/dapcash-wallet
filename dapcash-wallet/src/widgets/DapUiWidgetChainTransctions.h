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
private:
    void initTrans(QWidget* a_w, QString a_name, QString sum, QString who, bool in);
    void getTrans(QWidget* a_w, QString a_name, QString& sum, QString& who, bool in);
    int m_trNumber;
    bool from[10];
};

#endif // DAPUIWIDGETCHAINTRANSCTIONS_H
