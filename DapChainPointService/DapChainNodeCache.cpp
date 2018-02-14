#include "DapChainNodeCache.h"

DapChainNodeCache::DapChainNodeCache()
{

}

void DapChainNodeCache::add(QByteArray key, QByteArray value){
    cach[key] = value;
}

void DapChainNodeCache::del(QByteArray key){
    cach.remove(key);
}

QByteArray DapChainNodeCache::find(QByteArray key){
    return cach[key];
}
