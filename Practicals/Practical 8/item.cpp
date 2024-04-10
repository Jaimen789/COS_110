#include <iostream>
#include "item.h"

using namespace std;

template<class T>
item<T>::item(T t){
    data = t;
}

template<class T>
item<T>::~item(){
    cout << data << " Deleted." << endl;
}

template<class T>
T item<T>::getData(){
    return data;
}