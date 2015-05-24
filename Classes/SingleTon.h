
//
//  SingleTon.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/1.
//
//

#ifndef __KaziProject__SingleTon__
#define __KaziProject__SingleTon__


#include <stdio.h>
using namespace std;

template <class T>
class Singleton
{
public:
    
    static inline T* instance();
    
    void release();
protected:
    Singleton(void){}
    ~Singleton(void){}
    static T* _instance;
};

template <class T>
inline T* Singleton<T>::instance()
{
    if( !_instance){
        _instance = new T;
    }
    return _instance;
}

template <class T>
void Singleton<T>::release()
{
    if (!_instance)
        return;
    delete _instance;
    _instance = 0;
}
#endif /* defined(__KaziProject__SingleTon__) */
