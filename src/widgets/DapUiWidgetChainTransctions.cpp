#include <QLayout>
#include "DapUiWidgetChainTransctions.h"
#include "src/DapChainPointClient.h"
#include "ui_DapUiWidgetChainTransctions.h"


DapUiWidgetChainTransctions::DapUiWidgetChainTransctions(QWidget * a_w) : DapUiWidgetAbstract(a_w)
{
    qDebug() << "[M] DapUiWidgetChainTransctions::DapUiWidgetChainTransctions";
    Ui::DapUiWidgetChainTransctions ui;
    ui.setupUi(this);
   // QWidget* uiWidget =ui.DapUiWidgetChainTransctions;
    m_trNumber = 1;
    for (int i=0; i<10; i++){
        from[i] = false;
    }

    connect(&DapChainPointClient::me(), &DapChainPointClient::sigNewTransaction, [=](QString a_trasaction,
            QString a_who, QString a_where){

            if (m_trNumber > 10){
                for (int i =1; i<=9; i++ ){
                     QString l_nextTr;// ="";
                     QString l_nextWho;// ="";
                     bool l_nextWhere;//= true;
                     getTrans(this, QString::number(i+1), l_nextTr, l_nextWho, l_nextWhere);
                     from[i-1] = from[i];
                     l_nextWhere =from[i];
                    /* qDebug()<<i;
                     qDebug()<<l_nextTr;
                     qDebug()<<l_nextWho;
                     qDebug()<<l_nextWhere;*/
                     initTrans(this, QString::number(i), l_nextTr, l_nextWho, l_nextWhere);
                }
                initTrans(this, QString::number(10), a_trasaction, a_who, a_where.toInt());
                from[9]=a_where.toInt();
               // m_trNumber+=1;
            }
            else{
                initTrans(this, QString::number(m_trNumber), a_trasaction, a_who, a_where.toInt());
                from[m_trNumber-1]=a_where.toInt();
                m_trNumber+=1;
            }
    });



    /*m_list = new QListWidget(this);

    // add transaction to list
    connect(&DapChainPointClient::me(), &DapChainPointClient::sigNewTransaction, [=](QString a_transaction) {
        QListWidgetItem * l_item = new QListWidgetItem(a_transaction);
        m_list->addItem(l_item);

        m_pointer += 1;
        if (m_pointer > 15) {
            m_pointer -= 1;
            m_list->deleteLater();
        }
    });*/
}

void DapUiWidgetChainTransctions::getTrans(QWidget* a_w, QString a_name, QString& sum, QString& who, bool in){
    Q_UNUSED(in);

    QLabel* l_summ = a_w->findChild<QLabel* >("summ_"+a_name);

    Q_ASSERT(l_summ);
    sum = l_summ->text();
    qDebug()<<sum;
   // l_summ->setText(sum);
    QLabel* l_who = a_w->findChild<QLabel* >("who_"+a_name);
    Q_ASSERT(l_who);
    who = l_who->text();
    qDebug()<<who;
    //l_who->setText(who);
    QLabel* l_icon = a_w->findChild<QLabel* >("icon_"+a_name);
    Q_ASSERT(l_icon);
  /*  if (l_icon->pixmap()->toImage()==QPixmap("").toImage()){ //если иконка вверх, то нам, иначе от нас
        in = true;
    }
    else{
        in = false;
    }*/

}

void DapUiWidgetChainTransctions::initTrans(QWidget* a_w, QString a_name, QString sum, QString who, bool in){
    //summ, who, icon
    QLabel* l_summ = a_w->findChild<QLabel* >("summ_"+a_name);
    qDebug()<<a_name;

    Q_ASSERT(l_summ);
    l_summ->setText(sum);
    QLabel* l_who = a_w->findChild<QLabel* >("who_"+a_name);
    Q_ASSERT(l_who);
    l_who->setText(who);
    QLabel* l_icon = a_w->findChild<QLabel* >("icon_"+a_name);
    Q_ASSERT(l_icon);
    QPixmap pmt ("");
    QPixmap pmf ("");
    if (in) //проверяем нам true, или от нас false
    {
        l_icon->setPixmap(pmt);
        /*pm = new QPixmap();
        //QPixmap pm("");//Здесь будет путь*/
    }
    else
    {
        l_icon->setPixmap(pmf);
        /*pm = new QPixmap();
        //QPixmap pm("");//Здесь будет путь*/
    };


}
