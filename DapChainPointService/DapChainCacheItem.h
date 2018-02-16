#ifndef DAPCHAINCACHEITEM_H
#define DAPCHAINCACHEITEM_H
#include <QMap>
#include <QHash>

class DapChainCacheItem
{
   //static int t = 3; //кол-во потомков

public:
    DapChainCacheItem(DapChainCacheItem* prt = nullptr);
    DapChainCacheItem* getParent();
    bool isLeaf();
    int key;
private:
    DapChainCacheItem* m_parent;
    DapChainCacheItem* m_childListTop[3];
    QHash<QByteArray, QByteArray> hashTbl;
    bool leaf;
};

#endif // DAPCHAINCACHEITEM_H
