#include <iostream>
#include <cstdlib>

#include "storage.h"
#include "cLL.h"
#include "dLL.h"

using namespace std;

template<class T>
storage<T>::storage(int rS){
    cList = NULL;
    dList = NULL;

    randomSeed = rS;
    srand(randonSeed);
}

template<class T>
storage<T>::~storage(){
    
    delete cList;
    delete dList;
}

template<class T>
void storage<T>::storeData(T data){
    if(data % 2 == 0){
        citem<T>* newItem = new citem<T>(data);
        cList->push(newItem);
    }else{
        ditem<T>* newItem = new ditem<T>(data);
        dList->push(newItem);
    }
}

template<class T>
void storage<T>::printCList(){
    cList->printList();
}

template<class T>
void storage<T>::printDList(){
    dList->printList();
}