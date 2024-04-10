#include <iostream>
#include "dLL.h"
#include "ditem.h"

using namespace std;

template<class T>
dLL<T>::dLL(){
    head = NULL;
    tail = NULL;
    size = 0;
}

template<class T>
dLL<T>::~dLL(){
    ditem<T>* temp;

    while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
}

template<class T>
ditem<T>* dLL<T>::getHead(){
    return head;
}

template<class T>
ditem<T>* dLL<T>::getTail(){
    return tail;
}

template<class T>
int dLL<T>::getSize(){
    return size;
}


template<class T>
void dLL<T>::push(ditem<T>* newItem){
    ditem<T>* temp = head;
    ditem<T>* curr = head;
    ditem<T>* temp2 = head;

    ditem<T>* tail_temp = tail;
    
    ditem<T>* tail_curr = tail;

    if(temp == NULL || newItem->getData() < minNode()){
        if(temp == NULL){
            head = newItem;
            head->next = NULL;
            head->prev = NULL;
            size++;
        }else{
            

            curr = newItem;
            curr->prev = NULL;
            curr->next = temp2;
            temp2->prev = curr;
            tail = temp2;
            head = curr;

            //cout << "curr: " << curr->getData() << endl;

            newItem->prev = NULL;
            size++;

        }
    }else{
            tail_curr = newItem;
            tail_curr->next = NULL;
            tail_temp->next = tail_curr;
            tail_curr->prev = tail_temp;
            tail = tail_curr;
            size++;
        }

}

template<class T>
ditem<T>* dLL<T>::pop(){
    ditem<T>* temp = head;

    if(head == NULL){
        return NULL;
    }else{
        temp = temp->next;
        temp->prev = NULL;
        head = temp;
        size--;

        return head;
    }
}

template<class T>
void dLL<T>::printList(){
    ditem<T>* temp = head;
    cout << "dLL: ";
    while(temp != NULL){
        cout <<temp->getData() << " ";
        temp = temp->next;
    }
    cout << endl;
}

template<class T>
T dLL<T>::minNode(){
    //create a minNode and initialize it to the head->data
    //traverse the list

    ditem<T>* temp = head;
    T minNode = head->getData();   

    while(temp != NULL){
        if(temp->getData() <= minNode){
            minNode = temp->getData();
        }

        temp = temp->next;
    } 

    return minNode;

}

template<class T>
ditem<T>* dLL<T>::getItem(int i){
    ditem<T>* temp = head;

    if(i < 0 || i >= size){
        return NULL;
    }

    int currIndex = 0;

    while(currIndex < i && temp != NULL){
        temp = temp->next;
        currIndex++;
    }


    return temp;
}