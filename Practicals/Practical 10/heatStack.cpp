#include<iostream>
#include "heatStack.h"
#include "heatNode.h"

using namespace std;

template<class T>
heatStack<T>::heatStack(){
    top = NULL;
}

template<class T>
heatStack<T>::~heatStack(){
    heatNode<T>* temp = top;

    while(top != NULL){
        temp = top;
        top = top->next;
        delete temp;
    }
}

template<class T>
void heatStack<T>::push(heatNode<T>* t){
    heatNode<T>* temp = top;

    if(top == NULL){
        top = t;
        top->next = NULL;
    }else{
        temp = t;
        temp->next = top;
        top = temp;
    }
}

template<class T>
void heatStack<T>::pop(){
    top = top->next;
}

template<class T>
heatNode<T>* heatStack<T>::peek(){
    return top;
}

template<class T>
void heatStack<T>::print(){
    heatNode<T>* temp = top;

    if(temp == NULL){
        cout << "Stack is empty." << endl;
    }else{
        while(temp != NULL){
            cout << "Heat Sink CL: " << temp->getCoolantLevel() << endl;
            temp = temp->next;
        }
        
    }

}

template<class T>
bool heatStack<T>::validateCooling(int* heat, int numSinks){
    //use one temp next time by reseting temp back to top after use
    heatNode<T>* temp = top;
    heatNode<T>* temp2 = top;
    heatNode<T>* temp3 = top;
    heatNode<T>* temp4 = top;

    //get numOfNodes
    int numNodes = 0;
    while(temp != NULL){
        numNodes++;
        temp = temp->next;
    }


    //get cumulative cooling power of the stack
    int cumulative_cp = 0;
    while(temp2 != NULL){
        cumulative_cp = cumulative_cp + temp2->getPower() ;
        temp2 = temp2->next;
    }

    //get cumulative cooling power of the requirements
    int cumulative_cp_req = 0;
    for(int i = 0; i < numSinks; i++){
        cumulative_cp_req = cumulative_cp_req + heat[i];
    }

    //no heatNode has a coolant level lower than the number of heatNodes
    int res = 0; //0 - false    1 - true

    while(temp3 != NULL){
        if(temp3->getCoolantLevel() >= numNodes){
            res = 1;
        }else{
            res = 0;
        }

        temp3 = temp3->next;
    }

    if(numNodes == numSinks && cumulative_cp >= cumulative_cp_req && res == 1){
        cout << "Validation is met." << endl;
        return true;
    }else{
       cout << "Validation is not met." << endl;
        return false;
    }
}


