#include <iostream>
#include "queue.h"

using namespace std;

template<class T>
Queue<T>::Queue(LinearStructure<T>* c) : OrderedContainer<T>::OrderedContainer(c) {
    this->front = 0;
    this->rear = 0;
}


template<class T>
Queue<T>::Queue(const Queue<T>& other) : OrderedContainer<T>::OrderedContainer(other){
    this->front = other.front;
    this->rear = other.rear;

    if(other.dataStructure != NULL){
		this->dataStructure = other.dataStructure->clone();
	}else{
		this->dataStructure = NULL;
	}
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other){
    this->front = other.front;
    this->rear = other.rear;

    if(other.dataStructure != NULL){
		this->dataStructure = other.dataStructure->clone();
	}else{
		this->dataStructure = NULL;
	}

    return *this;
}

template<class T>
Queue<T>::~Queue(){}

template<class T>
T Queue<T>::remove()
{
	T myTemp= Queue<T>::dataStructure->remove(front);
	rear--;
	return myTemp;
}


template<class T>
T Queue<T>::next(){
    return Queue<T>::dataStructure->get(front + 1);
}


template<class T>
void Queue<T>::insert(T el){
    Queue<T>::dataStructure->insert(rear,el);
    front++;

}

template<class T>
void Queue<T>::reverse() {
    while (front < rear) {

        T temp = this->dataStructure->get(front);
        this->dataStructure->insert(front, this->dataStructure->get(rear));
        this->dataStructure->insert(rear, temp);

        // Move indices towards each other
        front++;
        rear--;

        // Adjust indices when the queue size is odd
        if (front == rear) {
            front++;
            rear--;
        }
    }

}

