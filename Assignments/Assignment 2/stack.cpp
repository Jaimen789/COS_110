#include <iostream>
#include "stack.h"


using namespace std;

template<class T>
Stack<T>::Stack(LinearStructure<T>* c) : OrderedContainer<T>::OrderedContainer(c){
    this->stackTop = -1;
}

template<class T>
Stack<T>::Stack(const Stack<T>& other) : OrderedContainer<T>::OrderedContainer(other){
    this->stackTop = other.stackTop;

	if(other.dataStructure != NULL){
		this->dataStructure = other.dataStructure->clone();
	}else{
		this->dataStructure = NULL;
	}
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other){

    this->stackTop = other.stackTop;

    delete this->dataStructure;

	if(other.dataStructure != NULL){
		this->dataStructure = other.dataStructure->clone();
	}else{
		this->dataStructure = NULL;
	}
    
    return *this;
}

template<class T>
Stack<T>::~Stack(){}

template<class T>
T Stack<T>::remove()
{
	
	T myTemp= Stack<T>::dataStructure->remove(stackTop-1);
	stackTop--;
	return myTemp;
	
}

template<class T>
T Stack<T>::next(){
    return Stack<T>::dataStructure->get(stackTop-1);
}

template<class T>
void Stack<T>::insert(T el)
{
	Stack<T>::dataStructure->insert(stackTop,el);
	stackTop = stackTop + 1;
}

template<class T>
void Stack<T>::reverse(){}
