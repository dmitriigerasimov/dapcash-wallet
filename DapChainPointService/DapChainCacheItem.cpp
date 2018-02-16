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
