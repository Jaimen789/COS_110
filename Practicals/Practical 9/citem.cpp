#include<iostream>
#include "citem.h"

using namespace std;

template<class T>
citem<T>::citem(T t){
    data = t;
}

template<class T>
citem<T>::~citem(){
    cout << data << " : is deleted!" << endl;
}

template<class T>
T citem<T>::getData(){
    return data;
}


