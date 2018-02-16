#include "DapChainNodeCache.h"

DapChainNodeCache::DapChainNodeCache(DapChainCacheItem* root)
{
    m_root = root;
}

void DapChainNodeCache::inset_to_item(int key, DapChainCacheItem* item){
    item->key = key;
}

/*void DapChainNodeCache::add(QByteArray key, QByteArray value){
//    cach[key] = value;
}

void DapChainNodeCache::del(QByteArray key){
  //  cach.remove(key);
}

QByteArray DapChainNodeCache::find(QByteArray key){
    //return cach[key];
}*/
