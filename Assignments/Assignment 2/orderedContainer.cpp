#include <iostream>
#include "orderedContainer.h"

using namespace std;

template<class T>
OrderedContainer<T>::OrderedContainer(LinearStructure<T>* c){
    dataStructure = c;
}

template<class T>
OrderedContainer<T>::OrderedContainer(const OrderedContainer<T>& other){

    if(other.dataStructure != NULL){
        this->dataStructure = other.dataStructure->clone();
    }else{
        this->dataStructure = NULL;
    }
}

template<class T>
OrderedContainer<T>& OrderedContainer<T>::operator=(const OrderedContainer<T>& other){
    delete dataStructure;

    if(other.dataStructure != NULL){
        this->dataStructure = other.dataStructure->clone();
    }else{
        this->dataStructure = NULL;
    }

    return *this;
}

template<class T>
OrderedContainer<T>::~OrderedContainer(){
    delete dataStructure;
}

template<class T>
bool OrderedContainer<T>::isEmpty(){
    if(dataStructure == NULL){
        return true;
    }

    return false;
}

template<class T>
LinearStructure<T>* OrderedContainer<T>::getImplementation(){
    return dataStructure;
}
