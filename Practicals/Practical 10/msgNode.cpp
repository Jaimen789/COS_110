#include <iostream>
#include "msgNode.h"

using namespace std;

template<class T>
msgNode<T>::msgNode(T i, double s){
    message = i;
    size = s;
}

template<class T>
msgNode<T>::~msgNode(){
    cout << "Message Processed!" << endl;
}

template<class T>
T msgNode<T>::getMessage() const{
    return message;
}

template<class T>
double msgNode<T>::getSize() const{
    return size;
}