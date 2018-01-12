#ifndef DAPCHAINPOINTCLIENT_H
#define DAPCHAINPOINTCLIENT_H

#include <QObject>

#include <QLocalSocket>
typedef QLocalSocket SapUiSocket;
typedef QLocalSocket::LocalSocketError SapUiSocketError;

class DapChainPointClient : public QObject
{
    Q_OBJECT
    SapUiSocket * sockCtl;
    QString readStrBuffer;
    void procCmd(const QString & a_cmd);
    DapChainPointClient(QObject *a_p = 0);
public:
    static DapChainPointClient& me(){
        static DapChainPointClient _me; return _me;
    }

    void sendMsg (QString a_msg){
        Q_UNUSED(a_msg);
    }
public slots:
    void readReady();
signals:
    void sigSetDapUiScreenDashboard();
    void sigNewTransaction(QString a_transaction);
    void sigBalanceChanged(QString a_txt);
};

#endif // DAPCHAINPOINTCLIENT_H
