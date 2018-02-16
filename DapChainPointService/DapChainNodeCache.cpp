#include "DapChainNodeCache.h"

DapChainNodeCache::DapChainNodeCache()//DapChainCacheItem* root)
{
    //m_root = root;
}

hash DapChainNodeCache::find(int key){
    return hashTr.find(key).value();
}

void DapChainNodeCache::insert(int key, hash item){
    hashTr.insert(key, item);
}

void DapChainNodeCache::remove(int key){
    hashTr.remove(key);
}

/*void DapChainNodeCache::inset_to_item(int key, DapChainCacheItem* item){
    item->key = key;
}*/

/*void DapChainNodeCache::add(QByteArray key, QByteArray value){
//    cach[key] = value;
}

void DapChainNodeCache::del(QByteArray key){
  //  cach.remove(key);
}

QByteArray DapChainNodeCache::find(QByteArray key){
    //return cach[key];
}*/
