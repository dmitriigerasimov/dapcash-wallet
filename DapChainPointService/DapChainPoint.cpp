#include "DapChainPoint.h"
#include <qlocalserver.h>
#include <qlocalsocket.h>


DapChainPoint::DapChainPoint()
{
    m_locServer = new QLocalServer(this);


    if (!m_locServer->listen("client891"))
    {

        m_locServer->close();
        return;
    }
     qDebug()<<m_locServer->serverName();
    connect(m_locServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));

    //_serv= new MyServer
}

void DapChainPoint::slotNewConnection(){
    QLocalSocket* clientSocket = m_locServer->nextPendingConnection();
   // sendToClient(clientSocket, "newLog", "10", "20", "30", "40");
    connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(readClient()));

}

void DapChainPoint::sendToClient(QLocalSocket *pSocket, const QString& a_msg1, const QString& a_msg2,
                                 const QString& a_msg4, const QString& a_msg5, const QString& a_msg6){
    if (pSocket->isWritable())
    {
        pSocket->write(QString("%1 %2").arg(a_msg1).arg(a_msg2).append(arg('\n').toLatin1() );
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
       // procCmd(readStrBuffer);
        readStr= readStr.mid(nInd+1);
        readStrBuffer.clear();
        if(readStr.length()>0){
            goto lb_read_str;
        }
    }
}
