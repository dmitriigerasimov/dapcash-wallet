#ifndef DAPCHAINPOINT_H
#define DAPCHAINPOINT_H

#include <QLocalSocket>
#include <QMap>
typedef QLocalSocket SapUiSocket;
typedef QLocalSocket::LocalSocketError SapUiSocketError;

class QLocalSocket;
class QLocalServer;

class DapChainPoint : public QObject //: public QTcpServer
{
    Q_OBJECT
private:
    QLocalServer* m_locServer;
    QLocalSocket* m_clientSocket;
    QString readStrBuffer;
    QMap<unsigned short, unsigned long long> ballance; //хранить следует *10-9
    void sendToClient(QLocalSocket* pSocket, const QString& a_msg1, const QString& a_msg2,
                      const QString& a_msg4, const QString& a_msg5, const QString& a_msg6);
    void procCmd(const QString & a_cmd);

   // QT
public:
    DapChainPoint();
public slots:
    virtual void slotNewConnection();
    void readClient();
};

#endif // DAPCHAINPOINT_H
