#include <iostream>
#include "bin.h"

using namespace std;

template<class T>
bin<T>::bin(T t){
    item = new T(t);

    cout << "Bin is created: " << t << endl;
}

template<class T>
bin<T>::~bin(){

    cout << "Item is deleted!" << endl;
    delete item;
}

template<class T>
T bin<T>::getData() const{
    return *item;
}