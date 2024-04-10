#include <iostream>
#include <string>

#include "msgNode.h"
#include "msgQueue.h"

using namespace std;

template<class T>
msgQueue<T>::msgQueue(){
    head = NULL;
    tail = NULL;
}

template<class T>
msgQueue<T>::~msgQueue(){
    msgNode<T>* temp = head;

    while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
}

template<class T>
void msgQueue<T>::enqueue(msgNode<T>* t){
    msgNode<T>* temp = tail;

    if(head == NULL && tail == NULL){
        head = tail = t;
    }else{
        tail->next = t;
        tail = t;
    }
}

template<class T>
void msgQueue<T>::dequeue(){
    if(head == tail){
        head = NULL;
        tail = NULL;
    }else{
        head = head->next;
    }
}

template<class T>
void msgQueue<T>::print(){
    msgNode<T>* temp = head;

    if(head == NULL){
        cout << "Queue is empty." << endl;
    }

    while(temp!= NULL){
        cout << "Message: " << temp->getMessage() << " | " << "[Size: " << temp->getSize() << " KB]" << endl;
        temp = temp->next;
    }
}

template<class T>
msgNode<T>* msgQueue<T>::peek(){
    return head;
}

template<class T>
void msgQueue<T>::compileMessageData(){
    msgNode<T>* temp = head;

    int numMessages = 0;
    double totalSize = 0;

    while(temp != NULL){
        numMessages++;
        totalSize = totalSize + temp->getSize();
        temp = temp->next;
    }

    

    cout << "Total Number of Messages: " << numMessages << endl;
    
    
    string unit;
    double convertedSize = 0;

    if (totalSize < 1024) { // Less than 1 KB
        unit = "KB";
        convertedSize = static_cast<double>(totalSize);
    } else if (totalSize < 1024 * 1024) { // Less than 1 MB
        unit = "KB";
        convertedSize = totalSize / 1024;
    } else { // 1 MB or larger
        unit = "MB";
        convertedSize = totalSize / (1024 * 1024);
    }

    cout << "Size: " << convertedSize << " " << unit << endl;
}