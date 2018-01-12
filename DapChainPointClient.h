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
public:
    DapChainPointClient(QObject *a_p = 0);
public slots:
    void readReady();
};

#endif // DAPCHAINPOINTCLIENT_H
