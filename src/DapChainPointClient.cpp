#include "DapChainPointClient.h"

DapChainPointClient::DapChainPointClient(QObject *a_p) : QObject(a_p)
{
    sockCtl = new SapUiSocket();

    connect(sockCtl,&SapUiSocket::readyRead,this, &DapChainPointClient::readReady);
    /*
    connect(sockCtl,static_cast<void(SapUiSocket::*)(SapUiSocketError)> (&SapUiSocket::error) ,
            this, &SapServiceClient::onCtlSocketError );
    connect(sockCtl,&SapUiSocket::connected, this, &SapServiceClient::ctlConnected);

    connect(sockCtl,&SapUiSocket::disconnected, this, &SapServiceClient::ctlDisconnected);
    */
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
            emit sigNewTransaction(infos[2]);
        } else if (infos[1] == "balanceChanged") {
            emit sigBalanceChanged(infos[2], infos[3], infos[4], infos[5]);
                                  //summ      simple     gold      other
        }
    }else{
        qWarning() << "[ServiceCtl] Empty reply from backend service";
    }
}
