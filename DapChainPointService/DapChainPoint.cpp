#include "DapChainPoint.h"
#include <qlocalserver.h>
#include <qlocalsocket.h>


DapChainPoint::DapChainPoint()
{
    m_locServer = new QLocalServer(this); //QLocalServer(this);

    ballance[0] = 10;//*pow(10, -9);
    ballance[1] =  5;//*pow(10, -9);
    ballance[2] =  3;//*pow(10, 9);
    qDebug()<<m_locServer->serverName();

    if (!m_locServer->listen("client7"))
    {

        m_locServer->close();
        return;
    }
     qDebug()<<m_locServer->serverName();

     //test

     //test

    connect(m_locServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));


}

void DapChainPoint::slotNewConnection(){
    //QLocalSocket* clientSocket = m_locServer->nextPendingConnection();
    m_clientSocket = m_locServer->nextPendingConnection();
    connect(m_clientSocket, SIGNAL(disconnected()), m_clientSocket, SLOT(deleteLater()));
    connect(m_clientSocket, SIGNAL(readyRead()), this, SLOT(readClient()));
    sendToClient(m_clientSocket, "newLog", "10", "20", "30", "40");
}

void DapChainPoint::sendToClient(QLocalSocket *pSocket, const QString& a_msg1, const QString& a_msg2,
                                 const QString& a_msg3, const QString& a_msg4, const QString& a_msg5){
    if (pSocket->isWritable())
    {
        pSocket->write( QString("%1 %2 %3 %4 %5 %6").arg(a_msg1).arg(a_msg2).arg(a_msg3).arg(a_msg4).arg(a_msg5).arg('\n').toLatin1());
        //pSocket->flush();
        qDebug()<<QString("%1 %2 %3 %4 %5 %6").arg(a_msg1).arg(a_msg2).arg(a_msg3).arg(a_msg4).arg(a_msg5).arg('\n').toLatin1();
    }

}
void DapChainPoint::readClient(){
    QLocalSocket* pSocket = (QLocalSocket*)sender();
    QString readStr = QString::fromLatin1( pSocket->readAll());
    qDebug()<<readStr;
    int nInd;
lb_read_str:

    if((nInd=readStr.indexOf('\n'))==-1 ){
        qDebug() << "[SapServiceClient] No CR symbol";
        readStrBuffer += readStr;
    }else{
        readStrBuffer += readStr.left(nInd);
        qDebug() << readStrBuffer;
        procCmd(readStrBuffer);
        readStr= readStr.mid(nInd+1);
        readStrBuffer.clear();
        if(readStr.length()>0){
            goto lb_read_str;
        }
    }
}

void DapChainPoint::procCmd(const QString &a_cmd){
    QStringList infos = a_cmd.split(' ');

    QString l_sum    = QString::number(ballance[0]+ballance[1]+ballance[2]);
    QString l_gold   = QString::number(ballance[0]);
    QString l_silver = QString::number(ballance[1]);
    QString l_other  = QString::number(ballance[2]);

    if(infos.length() > 0){
        if(infos[0]=="clickedDapUiWidgeChainOperationsmoneySend"){
            sendToClient(m_clientSocket, "balanceChanged", l_sum, l_gold, l_silver, l_other);
                                                           //summ //gold  //silver  //other
//clicked DapUiWidgeChainOperations moneySend");

        }
        else if (infos[0]=="clickedDapUiWidgeChainOperationsmoneyRequest"){
            //"clicked DapUiWidgeChainOperations moneyRequest"
            sendToClient(m_clientSocket, "balanceChanged", l_sum, l_gold, l_silver, l_other);
                                                           //summ  //gold  //silver     //other
        }
        else if (infos[0]=="clickedDapUiWidgeChainOperationsmoneyHold"){
            sendToClient(m_clientSocket, "balanceChanged", l_sum, l_gold, l_silver, l_other);
                                                           //summ   //gold  //silver     //other
            //"clicked DapUiWidgeChainOperations moneyHold"
        }
    }
    else {
        qWarning() << "[ServiceCtl] Empty reply from backend service";
    }
}
