#ifndef DAPUISCREENDASHBOARD_H
#define DAPUISCREENDASHBOARD_H

#include "libdap-qt-ui/DapUiScreen.h"

class DapUiScreenDashboard : DapUiScreen
{
    Q_OBJECT
public:
    void initUi(QWidget * a_w, ScreenVariant a_variant);
    DapUiScreenDashboard(QObject *parent, QStackedWidget * a_sw);
};


#endif // DAPUISCREENDASHBOARD_H

