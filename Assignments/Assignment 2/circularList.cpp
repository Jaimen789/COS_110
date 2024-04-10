#include <iostream>

#include "circularList.h"
#include "node.h"

using namespace std;

template<class T>
CircularList<T>::CircularList(){
    this->tail = NULL;
}

template<class T>
CircularList<T>::~CircularList(){
    Node<T>* temp = NULL;

    while(temp != NULL){
        temp = tail;
        tail = tail->next;
        delete temp;
        
    }

}

template<class T>
void CircularList<T>::insert(int index, T element){
    if(tail == NULL){
        Node<T>* newNode = new Node<T>(element);
        tail = newNode;
        tail->next = tail;
    }else if(index == size()){
        Node<T>* tail_next_ptr = tail->next;
        Node<T>* temp = tail;

        Node<T>* newNode = new Node<T>(element);

        tail = newNode;
        temp->next = tail;
        tail->next = tail_next_ptr;

    }else if (index < size()){
        if(index == 0){
            Node<T>* temp = tail;
            Node<T>* newNode = new Node<T>(element);

            temp = newNode;
            temp->next = tail->next;
            tail->next = temp;
        }else{
            Node<T>* prev = tail;
            Node<T>* curr = tail;

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
T CircularList<T>::remove(int index){
    Node<T>* temp = tail;

    if(index == 0){
        if(size() == 1){
            tail = NULL;
            return 0;
        }else{
            temp = tail->next;
            T ret  = temp->element;
            
            tail->next = temp->next;

            return ret;
        }
    }else if(index == size() - 1){
        
        while(temp->next != tail){
            temp = temp->next;
        }

        T ret = tail->element;

        temp->next = tail->next;
        tail = temp;
        tail->next = temp->next;

        return ret;

    }else if(index < size()){
        Node<T>* prev = tail;
        Node<T>* curr = tail;

        int count = 0;
        while(prev->next != prev && count < index){
            count++;
            prev = prev->next;
        }

        while(curr->next != curr && count <= index + 1){
            count++;
            curr = curr->next;
        }

        T ret = curr->element;

        curr = curr->next;

        prev->next = curr;

        return ret;
        

    }else{
        cout << "Invalid Index." << endl;
    }
}

template<class T>
ostream& operator<<(ostream& output,CircularList<T>& list){
    if(list.tail == NULL){
        output << "[]" << endl;
    }else{

        Node<T>* temp = list.tail;

        output << "[";

        do{
            output << temp->element;
            temp = temp->next;

            if(temp != list.tail){
                output << ",";
            }

        }while(temp != list.tail);

        output << "]" << endl;
    }


    return output;
}

template<class T>
CircularList<T>::CircularList(const CircularList<T>& other){
    
    //instatiate this with other by making a deep copy

    tail = NULL;
    Node<T>* oldCurrent = other.tail;
    Node<T>* lastNode = NULL;

    do{
        Node<T>* newNode = new Node<T>(oldCurrent->element);
        if(lastNode == NULL){
            tail = newNode;
            tail->next = tail;
        }else{
            lastNode->next = newNode;
        }

        lastNode = newNode;
        lastNode->next = tail;
        oldCurrent = oldCurrent->next;
    }while(oldCurrent != other.tail); 
    
}

template<class T>
CircularList<T>& CircularList<T>::operator=(const CircularList<T>& other){
    tail = NULL;
    Node<T>* oldCurrent = other.tail;
    Node<T>* lastNode = NULL;

    do{
        Node<T>* newNode = new Node<T>(oldCurrent->element);
        if(lastNode == NULL){
            tail = newNode;
            tail->next = tail;
        }else{
            lastNode->next = newNode;
        }

        lastNode = newNode;
        lastNode->next = tail;
        oldCurrent = oldCurrent->next;
    }while(oldCurrent != other.tail);

    return *this;
}

template<class T>
CircularList<T>* CircularList<T>::clone(){
    CircularList<T>* copy = new CircularList(*this);

    return copy;
}

template<class T>
T CircularList<T>::get(int index) const {

    Node<T>* temp = tail;
    int count = 0;
    while(temp->next != temp && count <= index){
        count++;
        temp = temp->next;
    }

    return temp->element;
}

template<class T>
bool CircularList<T>::isEmpty(){
    if(tail == NULL){
        return true;
    }

    return false;
}

template<class T>
void CircularList<T>::clear(){
    tail = NULL;
}

template<class T>
Node<T>* CircularList<T>::getLeader(){
    return tail;
}

template<class T>
ostream& CircularList<T>::print(ostream& output){
    if(this->tail == NULL){
        output << "[]" << endl;
    }else{

        Node<T>* temp = this->tail;

        output << "[";

        do{
            output << temp->element;
            temp = temp->next;

            if(temp != this->tail){
                output << ",";
            }

        }while(temp != this->tail);

        output << "]" << endl;
    }


    return output;
}