#include <iostream>
#include "cLL.h"
#include "citem.h"

using namespace std;

template<class T>
cLL<T>::cLL(){
    head = NULL;
    size = 0;
}

template<class T>
cLL<T>::~cLL(){
    citem<T>* temp = head;
    
    while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
}

template<class T>
bool cLL<T>::isEmpty(){
    if(head == NULL){
        return true;
    }else{
        return false;
    }
}

template<class T>
int cLL<T>::getSize(){
    return this->size;
}

template<class T>
T cLL<T>::maxNode() {
    citem<T>* temp = head;
    T maxNode = head->getData();

    if (head != NULL) {
        do {
            if (maxNode <= temp->getData()) {
                maxNode = temp->getData();
            }

            temp = temp->next;
        } while (temp != head);
    }

    return maxNode;
}



template<class T>
void cLL<T>::push(citem<T>* newItem) {
    citem<T>* temp = head;
    citem<T>* curr = head;

    citem<T>* last = head;

    citem<T>* last_tail = head;

    if(temp == NULL || newItem->getData() > maxNode()){ 
        if(temp == NULL){
            head = newItem;
            head->next = head;
            size++;
        }else{
            newItem->next = curr;
            while(last->next != head){
                last = last->next;
            }

            last->next = newItem;
            head = newItem;
            size++;
        }
    }else{
        do {
            last_tail = last_tail->next;
        } while (last_tail->next != head);

        cout << "last tail: " << last_tail->getData() << endl;
        cout << "last tail next: " << last_tail->next->getData() << endl;

        last_tail->next = newItem;
        newItem->next = head;
    }  
}

template<class T>
citem<T>* cLL<T>::pop(){
    citem<T>* temp = head;
    citem<T>* last = head;

    if(head == NULL){
        return NULL;
    }else{
        temp = temp->next;

        while(last->next != head){
            last = last->next;
        }

        last->next = temp;
        head = temp;

        size--;
        return head;

    }
}

template<class T>
citem<T>* cLL<T>::removeAt(T x){
    citem<T>* traverser = head;

    if(head == NULL){
        return NULL;
    }

    //list contains a single element
    if(head->getData() == x && head->next == head){
        head = NULL;
        size--;
        return head;
    }

    //if head is to be deleted
    citem<T>* temp = head;
    citem<T>* last = head;

    if(head->getData() == x){
        while(last->next != head){
            last = last->next;
        }

        last->next = head->next;
        head = last->next;
        size--;
        
        return head;
    }

    while(last->next != head && last->next->getData() != x){
        last = last->next;
    }

    if(last->next->getData() == x){
        temp = last->next;
        last->next = temp->next;
    }else{
        cout << "Value not found!" << endl;
    }
     
}

template<class T>
void cLL<T>::printList()
{
    //This will print out the entire list from head onwards. The output consists
    //of a single comma delimited line, with a newline at the end. For example:
    //1,2,3,4,5
    
    if(!head) // empty list
    {
        return;
    }
    else if(head->next == head) // single node list
    {
        cout << head->getData() << endl;
    }
    else
    {
        citem<T> *curr = head;
        while(curr->next != head)
        {
            cout << curr->getData() << " ";
            curr = curr->next;
        }
        cout << curr->getData() << endl;
    }

}





