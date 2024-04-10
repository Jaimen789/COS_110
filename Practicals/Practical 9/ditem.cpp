#include <iostream>
#include "ditem.h"

using namespace std;

template<class T>
ditem<T>::ditem(T t){
    data = t;
}

template<class T>
ditem<T>::~ditem(){
    cout << data << " : is deleted!" << endl;
}

template<class T>
T ditem<T>::getData(){
    return data;
}