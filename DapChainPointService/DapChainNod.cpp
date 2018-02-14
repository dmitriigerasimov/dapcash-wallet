#include "DapChainNod.h"
#include <qlocalserver.h>
#include <qlocalsocket.h>

DapChainNod::DapChainNod(QString nodeName)
{
    m_nodeName  = nodeName;
    m_locServer = new QLocalServer(this);

    if (!m_locServer->listen(m_nodeName))
    {

        m_locServer->close();
        return;
    }
    qDebug()<<m_locServer->serverName();
    m_cache = new DapChainNodeCache();
    connect(m_locServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));
}

void DapChainNod::slotNewConnection(){
    //QLocalSocket* clientSocket = m_locServer->nextPendingConnection();
    m_clientSocket = m_locServer->nextPendingConnection();
    connect(m_clientSocket, SIGNAL(disconnected()), m_clientSocket, SLOT(deleteLater()));
    connect(m_clientSocket, SIGNAL(readyRead()), this, SLOT(readClient()));
    //sendToClient(m_clientSocket, "newLog", "10", "20", "30", "40");
}

void DapChainNod::readClient(){ //так же читаем что нам пришло от ноды как от клиента?
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

void DapChainNod::procCmd(const QString &a_cmd){
    QStringList infos = a_cmd.split(' ');
    if (infos[0]=="add"){
        //будем добавлять
    }
    else if (infos[0]=="find"){
        //будем искать
    }
    else if (infos[0]=="del"){
        //Здесь будем удалять
    }
}
