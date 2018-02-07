#ifndef DAPUIWIDGETCHAINBALLANCE_H
#define DAPUIWIDGETCHAINBALLANCE_H

#include "src/widgets/DapUiWidgetAbstract.h"

class DapUiWidgetChainBallance : public DapUiWidgetAbstract
{
    Q_OBJECT
public:
    DapUiWidgetChainBallance(QWidget * a_w);
private:
    void InitLabel(QWidget a_w, QString a_lbname);
};

#endif // DAPUIWIDGETCHAINBALLANCE_H
