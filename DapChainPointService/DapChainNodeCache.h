#ifndef DAPCHAINNODECACHE_H
#define DAPCHAINNODECACHE_H
#include <QMap>
#include <QVariant>
#include <QHash>

typedef QHash<QString, QVariant> hash;

class DapChainNodeCache
{
private:
    QMap<int, hash> hashTr;
   // DapChainCacheItem* m_root;//корень дерева
   /* void inset_to_item(int key, DapChainCacheItem* item);
    void sort(DapChainCacheItem* item);
    void restruct(DapChainCacheItem* item);
    void deleteitem(DapChainCacheItem* item);
    bool searchKey(int key, DapChainCacheItem* item);
    void remove(int key, DapChainCacheItem* item);
    void removeFromItem(int key, DapChainCacheItem* items);
    void removeLeaf(int key, DapChainCacheItem* item);
    void lconnect(DapChainCacheItem* item, DapChainCacheItem* otherItem);
    void rconnect(DapChainCacheItem* item, DapChainCacheItem* otherItem);
    void repair(DapChainCacheItem* item);*/
public:
    //ШТО?!QMap<QByteArray, QByteArray> cach; //ключ и значение, а значение это что?

    DapChainNodeCache();//DapChainCacheItem* root =nullptr);
    void insert(int key, hash item);
    void remove(int key);
    hash find(int key);
    /*void add(QByteArray key, QByteArray value);
    void del(QByteArray key);
    QByteArray find(QByteArray key);//должно будет возвращать значение по ключу*/
};

#endif // DAPCHAINNODECACHE_H
