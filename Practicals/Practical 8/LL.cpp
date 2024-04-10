#include <iostream>
#include <cstdlib>

#include "LL.h"
#include "item.h"

using namespace std;

template<class T>
LL<T>::LL(int rS){
    size = 0;
    head = NULL;
    randomSeed = rS;
    srand(randomSeed);
}

template<class T>
LL<T>::~LL() {
    item<T>* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;  // Deleting the current node
    }
}


template<class T>
item<T>* LL<T>::getHead() const{
    return head;
}

template<class T>
void LL<T>::addItem(item<T>* newItem){
    if (head == NULL || newItem->getData() <= minNode()) {
        // If the list is empty or the new item is smaller than or equal to the smallest value,
        // add it at the end of the list
        if (head == NULL) {
            head = newItem;
            head->next = NULL;
        } else {
            item<T>* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newItem;
            newItem->next = NULL;
        }
    } else {
        // If the new item is greater than the smallest value, add it in front of the current head
        newItem->next = head;
        head = newItem;
    }

    size++;
}



template<class T>
void LL<T>::printList(){
    item<T>* temp = head; // Use a temporary variable

    while(temp != NULL){
        cout << temp->getData() << endl;
        temp = temp->next;
    }
}


template<class T>
T LL<T>::minNode(){
    T min = head->getData();
    item<T>* temp = head;

    while(temp != NULL){
        if(temp->getData() <= min){
            min = temp->getData();
        }

        temp = temp->next;
    }

    return min;
}

template<class T>
T LL<T>::maxNode(){
    T max = head->getData();
    item<T>* temp = head;

    while(temp != NULL){
        if(temp->getData() >= max){
            max = temp->getData();
        }

        temp = temp->next;
    }

    return max;
}

template<class T>
item<T>* LL<T>::getItem(int index) const{
    if(index < 0 || index >= size){
        return NULL;
    }

    item<T>* curr = head;
    int currIndex = 0;

    while(currIndex < index && curr != NULL){
        curr = curr->next;
        currIndex++;
    }

    return curr;
}


template<class T>
void LL<T>::randonShuffleList(){
    int random = rand() % size;


    //1. Set random node as head
    //2. Add nodes after random node(larger nodes)
    //3. Add nodes before random node (smaller nodes)

    // Traverse the linked list until you reach the node at the given random index.
    // Update the next pointer of the node before the random index to nullptr to disconnect it from the rest of the list.
    // Update the next pointer of the last node in the current list to point to the head of the original list, effectively making it circular.
    // Update the head of the list to the node at the random index.
    // Update the next pointer of the node at the random index to nullptr to mark the end of the modified list.

    item<T> *temp = head;
    item<T>* curr = head;
    item<T>* prev = head;

    item<T>* last = head;
    

    temp = getItem(random);

    while(curr->getData() != temp->getData()){
        prev = curr;
        curr = curr->next;
        

    } 

    prev->next = NULL;

    curr = temp;

    while(curr->next != NULL){
        curr = curr->next;
        
    }

    curr->next = last;
    
    head = temp;
}

template<class T>
void LL<T>::randonShuffleList(int i){
    //1. Set random node as head
    //2. Add nodes after random node(larger nodes)
    //3. Add nodes before random node (smaller nodes)

    // Traverse the linked list until you reach the node at the given random index.
    // Update the next pointer of the node before the random index to nullptr to disconnect it from the rest of the list.
    // Update the next pointer of the last node in the current list to point to the head of the original list, effectively making it circular.
    // Update the head of the list to the node at the random index.
    // Update the next pointer of the node at the random index to nullptr to mark the end of the modified list.

    item<T> *temp = head;
    item<T>* curr = head;
    item<T>* prev = head;

    item<T>* last = head;
    

    temp = getItem(i);

    while(curr->getData() != temp->getData()){
        prev = curr;
        curr = curr->next;
        

    } 

    prev->next = NULL;

    curr = temp;

    while(curr->next != NULL){
        curr = curr->next;
        
    }

    curr->next = last;
    
    head = temp;
}

template<class T>
item<T>* LL<T>::pop(){
    item<T>* temp;

    if(head == NULL){
        return NULL;
    }else{
        temp = head->next;
        head = temp;
        size--;
        return head;
    }
}

template<class T>
int LL<T>::getSize() const{
    return size;
}

template<class T>
void LL<T>::reverseList(){
    item<T>* curr = head;
    item<T>* prev = NULL;
    item<T>* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}