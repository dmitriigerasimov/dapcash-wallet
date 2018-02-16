#include "DapChainCacheItem.h"

DapChainCacheItem::DapChainCacheItem(DapChainCacheItem* prt)
{
    m_parent = prt;
}

DapChainCacheItem* DapChainCacheItem::getParent(){
    return m_parent;
}

bool DapChainCacheItem::isLeaf(){
    return leaf;
}

void DapChainCacheItem::add(QString key, QVariant item){
    hashTbl[key]=item;

}

void DapChainCacheItem::del(QString key){
    hashTbl.remove(key);
}

QVariant DapChainCacheItem::find(QString key){
    if (hashTbl.find(key)!=hashTbl.end()){
        return hashTbl.find(key).value();
    }
    else {
        return false;
    }
}
