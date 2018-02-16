#ifndef DAPCHAINCACHEITEM_H
#define DAPCHAINCACHEITEM_H
#include <QMap>
#include <QHash>
#include <QVariant>

class DapChainCacheItem
{
   //static int t = 3; //кол-во потомков

public:
    DapChainCacheItem(DapChainCacheItem* prt = nullptr);
    DapChainCacheItem* getParent();
    bool isLeaf();
    QVariant find(QString key);
    void add(QString key, QVariant item);
    void del(QString key);
    //int key;
private:
    DapChainCacheItem* m_parent;
    DapChainCacheItem* m_childListTop[3];//волшебное кол-во потомков
    QHash<QString, QVariant> hashTbl;
    bool leaf;
};

#endif // DAPCHAINCACHEITEM_H
