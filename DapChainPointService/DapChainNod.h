#ifndef DAPCHAINNOD_H
#define DAPCHAINNOD_H

#include <QLocalSocket>
#include <QMap>
#include <DapChainNodeCache.h>
typedef QLocalSocket SapUiSocket;
typedef QLocalSocket::LocalSocketError SapUiSocketError;

class QLocalSocket;
class QLocalServer;

class DapChainNod //: public QObject
{
    //Q_OBJECT
private:
    QLocalServer* m_locServer;
    QLocalSocket* m_clientSocket; //надобно и другие способы связи описать, а вообще и этот поправить

    QString readStrBuffer;
    QString m_nodeName;
    DapChainNodeCache m_cache;

    void procCmd(const QString & a_cmd); //эта штука будет обрабатывать информацию ноды
public:
    DapChainNod(QString nodeName);
public slots:
    virtual void slotNewConnection();
    void readClient();
};

#endif // DAPCHAINNOD_H
