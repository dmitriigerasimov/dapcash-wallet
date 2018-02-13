#ifndef DAPCHAINNODECACHE_H
#define DAPCHAINNODECACHE_H
#include <QMap>

class DapChainNodeCache
{
public:
    QMap<QByteArray, QByteArray> cach; //ключ и значение, а значение это что?
    DapChainNodeCache();
    void add(QByteArray key);
    void del(QByteArray key);
    QByteArray find(QByteArray key);//должно будет возвращать значение по ключу
};

#endif // DAPCHAINNODECACHE_H
