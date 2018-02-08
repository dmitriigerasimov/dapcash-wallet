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
    void connectToService();
    const QString& serviceName(){ return m_serviceName; }


    void sendMsg (QString a_msg);/*{
        Q_UNUSED(a_msg);
    }*/
private:
    QString m_serviceName;
public slots:
    void readReady();

    //void

private slots:
    void onCtlSocketError(SapUiSocketError socketError);
signals:
    void onConnected();
    void onDisconnected();
    void ctlError(QString);
    void sigSetDapUiScreenDashboard();
  //  void sigNewTransaction(QString a_transaction);
    void sigNewTransaction(QString a_transaction, QString a_who, QString a_where);
    void sigBalanceChanged(QString a_balance, QString a_simpl, QString a_gold,
                           QString a_another);
    void sigNewLogSent(QString a_log);


};

#endif // DAPCHAINPOINTCLIENT_H
