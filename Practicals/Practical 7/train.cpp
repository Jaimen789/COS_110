#include <iostream>
#include <typeinfo>

#include "train.h"
#include "bin.h"

using namespace std;

template<class T>
train<T>::train(int numBins){
    bins = numBins;

    storage = new bin<T>* [bins];

    for(int i = 0; i < bins; i++){
        storage[i] = nullptr;
    }
}

template<class T>
train<T>::~train(){
    for(int i = 0; i < bins; i++){
        if(storage[i] != nullptr){
            delete storage[i];
        }
    }

    delete [] storage;
}

template<class T>
int train<T>::addBin(bin<T>* item) {
    for (int i = 0; i < bins; i++) {
        if (storage[i] == nullptr) {
            storage[i] = item;
            //cout << "index: " << i << " ==" << " bins: " << storage[i]->getData() << endl;
            return i;
        }
    }
    
    // If the loop completes without finding an empty slot
    return -1;
}

template<class T>
int train<T>::addBin(int index, bin<T>* item){
    for(int i = 0; i < bins; i++){
        if(storage[index] == nullptr){
            storage[index] = item;
            //cout << "index: " << index << " ==" << " bins: " << storage[index]->getData() << endl;
            return i;
        }
    }

    return -1;
}

template<class T>
int train<T>::removeBin(int index){
    if(index < 0 || index >= bins || storage[index] == nullptr) return -1;

    delete storage[index];
    storage[index] = nullptr;


    return index;
}


template<class T>
int train<T>::removeBin(int index, bin<T>* item){
    for(int i = 0; i < bins; i++){
        if(typeid(storage[i]) == typeid(item)){
            delete storage[index];
            storage[index] = nullptr;

            return index;
        }
    }

    return -1;
}

template<class T>
void train<T>::printStorage(){
    for(int i = 0; i < bins; i++){
        if(storage[i] == nullptr){
            cout << "Bin " << i << ": NA" << endl;
        }else{
            cout << "Bin " << i << ": " << storage[i]->getData() << endl;
        }
    }
}
