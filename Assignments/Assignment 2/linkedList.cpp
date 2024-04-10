#include <iostream>

#include "linkedList.h"
#include "node.h"

using namespace std;

template<class T>
LinkedList<T>::LinkedList(){
    this->head = NULL; 
}

template<class T>
LinkedList<T>::~LinkedList(){
    Node<T>* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
}

template<class T>
ostream& operator<<(ostream& output, LinkedList<T>& list){
    Node<T>* current = list.head;

    if (current == nullptr) {
        output << "[]";
    } else {
        output << "[";
        while (current != nullptr) {
            output << current->element;
            current = current->next;
            if (current != nullptr) {
                output << ", ";
            }
        }
        output << "]";
    }

    return output;
}


template<class T>
void LinkedList<T>::insert(int index, T element){
    //if head is null
    if(head == NULL){
        Node<T>* newNode = new Node<T>(element);
        head = newNode;

    }else if(index == size()){
        Node<T>* temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }

        Node<T>* newNode = new Node<T>(element);
        temp->next = newNode;
        //head = temp;

    }else if(index < size()){
        //find prev node

        if(index == 0){
            Node<T>* newNode = new Node<T>(element);
            Node<T>* temp = head;

            newNode->next = temp;
            head = newNode;
        }else{
            Node<T>* prev = head;
            Node<T>* curr = head;

            for(int i = 0; i < index - 1; i++){
                prev = prev->next;
            }

            for(int j = 0; j < index; j++){
                curr = curr->next;
            }

            Node<T>* newNode = new Node<T>(element);

            newNode->next = curr;
            prev->next = newNode;
        }
        

    }else{
        cout << "Invalid Index." << endl;
    }
}

template<class T>
T LinkedList<T>::remove(int index){
    Node<T>* temp = head;

    //remove from head
    if(index == 0){
        if(size() == 1){
            head = NULL;
            return head->element;
        }else{
            T ret = head->element;
            temp = temp->next;
            head = temp;

            return ret;
        }
    }else if(index == size() - 1){
        Node<T>* prev = head;
        Node<T>* curr = head;

        for(int i = 0; i < index - 1; i++){
            prev = prev->next;
        }
        
        for(int j = 0; j < index; j++){
            curr = curr->next;
        }

        T ret = curr->element;

        prev->next = NULL;

        return ret;

    }else if(index < size()){
        Node<T>* prev = head;
        Node<T>* curr = head;
        Node<T>* temp = NULL;

        for(int i = 0; i < index - 1; i++){
            prev = prev->next;
        }

        for(int j = 0; j < index; j++){
            curr = curr->next;
        }

        T ret = curr->element;

        temp = curr->next;
        prev->next = temp;
        curr->next = NULL;

        return ret;
    }else{
        cout << "Invalid Index." << endl;
    }
}


template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other){
    head = nullptr; // Initialize the new list

    // Iterate over the nodes of the other list and copy each node
    Node<T>* otherCurrent = other.head;
    Node<T>* lastNode = nullptr;

    while (otherCurrent != nullptr) {
        Node<T>* newNode = new Node<T>(otherCurrent->element);

        if (lastNode == nullptr) {
            // If the new list is empty, set the head
            head = newNode;
        } else {
            // Otherwise, link the new node to the previous one
            lastNode->next = newNode;
        }

        // Move to the next nodes in both lists
        lastNode = newNode;
        otherCurrent = otherCurrent->next;
    }
    
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other){
    head = nullptr; // Initialize the new list

    // Iterate over the nodes of the other list and copy each node
    Node<T>* otherCurrent = other.head;
    Node<T>* lastNode = nullptr;

    while (otherCurrent != nullptr) {
        Node<T>* newNode = new Node<T>(otherCurrent->element);

        if (lastNode == nullptr) {
            // If the new list is empty, set the head
            head = newNode;
        } else {
            // Otherwise, link the new node to the previous one
            lastNode->next = newNode;
        }

        // Move to the next nodes in both lists
        lastNode = newNode;
        otherCurrent = otherCurrent->next;
    }

    return *this;
}


template<class T>
LinkedList<T>* LinkedList<T>::clone(){
    LinkedList<T>* copy = new LinkedList(*this);

    return copy;
}

template<class T>
T LinkedList<T>::get(int index) const{
    if(index > size()){
        cout << "Index out of bound." << endl;
        return NULL;
    }

    Node<T>* temp = head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }

    return temp->element;
}

template<class T>
bool LinkedList<T>::isEmpty(){
    if(head == NULL){
        return true;
    }

    return false;
}

template<class T>
void LinkedList<T>::clear(){\
    head = NULL;
}

template<class T>
Node<T>* LinkedList<T>::getLeader(){
    return head;
}

template<class T>
ostream& LinkedList<T>::print(ostream& os){
    Node<T>* current = this->head;

    if (current == nullptr) {
        os << "[]";
    } else {
        os << "[";
        while (current != nullptr) {
            os << current->element;
            current = current->next;
            if (current != nullptr) {
                os << ", ";
            }
        }
        os << "]";
    }

    return os;
}

