#ifndef DAPUIWIDGETABSTRACT_H
#define DAPUIWIDGETABSTRACT_H

#include <QWidget>
#include <QDebug>

class DapUiWidgetAbstract : public QWidget
{
    Q_OBJECT
public:
    DapUiWidgetAbstract(QWidget * a_w = 0);
};

#endif // DAPUIWIDGETABSTRACT_H
