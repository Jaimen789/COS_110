#include <iostream>
#include <string>
#include "heatNode.h"

using namespace std;


template<class  T>
heatNode<T>::heatNode(T i, int p){
    this->coolantLevel = i;
    this->power = p;
}

template<class  T>
heatNode<T>::~heatNode(){
    cout << "Heat Sink Removed." << endl;
}

template<class  T>
T heatNode<T>::getCoolantLevel() const{
    return coolantLevel;
}

template<class T>
int heatNode<T>::getPower() const{
    return power;
}