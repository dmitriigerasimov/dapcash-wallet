#include "DapChainPointClient.h"

DapChainPointClient::DapChainPointClient(QObject *a_p) : QObject(a_p)
{
    sockCtl = new SapUiSocket();
    sockCtl->connectToServer("client891");

    connect(sockCtl,&SapUiSocket::readyRead,this, &DapChainPointClient::readReady);


    connect(sockCtl, &SapUiSocket::connected, this, &DapChainPointClient::onConnected);
    connect(sockCtl, &SapUiSocket::disconnected, this, &DapChainPointClient::onDisconnected);
    connect(sockCtl,static_cast<void(SapUiSocket::*)(SapUiSocketError)> (&SapUiSocket::error) ,
                this, &DapChainPointClient::onCtlSocketError );
    /*connect(sockCtl, &SapUiSocket::disconnected, this, SLOT(onDisconnected()));*/
    //connect(sockCtl, &SapUiSocket)

    /*connect(sockCtl,static_cast<void(SapUiSocket::*)(SapUiSocketError)> (&SapUiSocket::error) ,
            this, &SapServiceClient::onCtlSocketError );
    connect(sockCtl,&SapUiSocket::connected, this, &SapServiceClient::ctlConnected);

    connect(sockCtl,&SapUiSocket::disconnected, this, &SapServiceClient::ctlDisconnected);
    */
}

void DapChainPointClient::onCtlSocketError(SapUiSocketError socketError){
    Q_UNUSED(socketError);
    qDebug() << "[DapServiceClient] onCtlSocketError() sockCtl->errorString() == "<<sockCtl->errorString();
    emit ctlError(sockCtl->errorString());
    if (sockCtl->isOpen()){
        return;
    }else
        connectToService();
}

void DapChainPointClient::connectToService(){
    sockCtl->connectToServer("client2");
    //sockCtl->connectt
/*#ifdef DAP_UI_SOCKET_TCP
            QTimer::singleShot(500,[=]{sockCtl->connectToHost(QHostAddress("127.0.0.1"),22142);});
#else
            QTimer::singleShot(1000,[=]{
                qDebug() << "[connectToService]";
                sockCtl->connectToServer(DAP_BRAND);
            });
#endif*/
}

void DapChainPointClient::readReady()
{
    QString readStr = QString::fromLatin1( sockCtl->readAll());
    int nInd;
lb_read_str:

    if((nInd=readStr.indexOf('\n'))==-1 ){
        qDebug() << "[SapServiceClient] No CR symbol";
        readStrBuffer += readStr;
    }else{
        readStrBuffer += readStr.left(nInd);
        procCmd(readStrBuffer);
        readStr= readStr.mid(nInd+1);
        readStrBuffer.clear();
        if(readStr.length()>0){
            goto lb_read_str;
        }
    }
}

void DapChainPointClient::sendMsg(QString a_msg){
    qDebug()<<a_msg + "Recived";
    if(sockCtl->isWritable())
        sockCtl->write( QString("%1%2").arg(a_msg).arg('\n').toLatin1()  );
  /*  if (a_msg=="clicked DapUiWidgeChainOperations moneyRequest"){
        procCmd("a new_transaction 15 20 1");
        procCmd("a balanceChanged 15 10 5 0");
        procCmd("a newLog YouPressedRequest!");
    }*/
    //Q_UNUSED(a_msg);
}


void DapChainPointClient::procCmd(const QString & a_cmd)
{
    QStringList infos = a_cmd.split(' ');
    if(infos.length() > 0){
        if (infos[1] == "set") {
            if (infos[2] == "DapUiScreenDashboard") {
                emit sigSetDapUiScreenDashboard();
            }
        } else if (infos[1] == "new_transaction") {
            emit sigNewTransaction(infos[2], infos[3], infos[4]);
        } else if (infos[1] == "balanceChanged") {
            emit sigBalanceChanged(infos[2], infos[3], infos[4], infos[5]);
                                  //summ      simple     gold      other
        } else if (infos[1]== "newLog"){
            emit sigNewLogSent(infos[2]); //пока хз как, наверное такы
        }
    }else{
        qWarning() << "[ServiceCtl] Empty reply from backend service";
    }
}
