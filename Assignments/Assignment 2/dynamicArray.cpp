#include <iostream>

#include "dynamicArray.h"

using namespace std;

template<class T>
DynamicArray<T>::DynamicArray(int s){
    size = s;
    numElements = s;

    elements = new T*[size];

    for(int i= 0; i < size; i++){
        elements[i] = NULL;
    }
}

template<class T>
DynamicArray<T>::~DynamicArray(){
    for(int i = 0; i < size; i++){
        if(elements[i] != NULL){
            delete elements[i];
        }
    }

    delete [] elements;
}

template<class T>
ostream& operator<<(ostream& output,DynamicArray<T>& myArray){
    if(myArray.size <= 0){ output << "Invalid size provided." << endl;}

    output << "[" ;

    for(int i = 0; i < myArray.size; i++){
        if(myArray.elements[i] == NULL){
            output << "*";
        }else{
            output << *myArray.elements[i];
        }

        if (i < myArray.size - 1) {
            output << ",";
        }
    }

    output << "]" <<endl;

    return output;
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other){
    size = other.size;
    numElements = other.numElements;

    elements = new T*[size];

    for(int i = 0; i < size; i++){
        if(elements[i] != NULL){
            elements[i] = new T(*(other.elements[i]));
        }else{
            elements[i] = NULL;
        }
    }
    
}

template<class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other){
    if(this == &other){
        return *this;
    }

    for(int i = 0; i < size; i++){
        if(elements[i] != NULL){
            delete elements[i];
        }
    }

    delete [] elements;

    size = other.size;
    numElements = other.numElements;

    elements = new T*[size];
    for(int i = 0; i < size; i++){
        if(other.elements[i] != NULL){
            elements[i] = new T(*(other.elements[i]));
        }else{
            elements[i] = NULL;
        }
    }

    return *this;
}

template<class T>
DynamicArray<T>* DynamicArray<T>::clone(){
    
    DynamicArray<T>* copy = new DynamicArray(*this);

    return copy;
}

template<class T>
void DynamicArray<T>::insert(int index, T element){
    if(index < size){
        if(elements[index] == NULL){
            elements[index] = new T(element);
        }else{
            resize(size + 1);
            T** temp = new T*[size + 1];

            for (int i = 0; i < size; ++i) {
                temp[i] = elements[i];
            }

            // Insert the new element at the specified index
            temp[index] = new T(element);

            // Copy the remaining elements after the inserted element
            for (int i = index + 1; i <= size; ++i) {
                temp[i] = elements[i - 1];
            }

            // Clean up the old array and update elements with the new one
            elements = temp;

        }
    }else{
        resize(index + 1);
        elements[index] = new T(element);
    }
    
}

template<class T>
T DynamicArray<T>::remove(int index){
    if(elements[index] == NULL){ cout << "Empty Structure." << endl;}
    if(index >= size){ cout << "Invalid index." << endl; }

    T** temp = new T*[size];
    //remove from head
    if(index == 0){
        T* ret = new T(*(elements[index]));

        for(int j = index + 1; j < size; j++){
            temp[j] = elements[j];
        }

        *elements = *temp;

        elements[0] = *temp;
        
        for(int r = 0; r < size; r++){
            elements[r] = elements[r + 1];
        }

        return *ret;

    }else if(index == size - 1){
        T* ret = new T(*(elements[index]));

        for(int i = 0; i < size - 1; i++){
            temp[i] = elements[i];
        }

        elements = temp;

        return *ret;
    }else{
        T* ret = new T(*(elements[index]));
        for(int i = index; i < size; i++){
            elements[i] = elements[i + 1];

            
        }

        return *ret;
    }
}

template<class T>
T DynamicArray<T>::get(int index) const{
    
    return *elements[index];
}

template<class T>
bool DynamicArray<T>::isEmpty(){
    for(int i = 0; i < size; i++){
        if(elements[i] != NULL){
            return false;
        }else{
            return true;
        }
    }
}

template<class T>
void DynamicArray<T>::clear(){

    T** temp = new T*[size];

    for(int i = 0; i < size; i++){
        temp[i] = NULL;
    }

    for(int j = 0; j < size; j++){
        elements[j] = temp[j];
    }
}

template<class T>
ostream& DynamicArray<T>::print(ostream& os){
    
    if(this->size <= 0){ os << "Invalid size provided." << endl;}

    os << "[" ;

    for(int i = 0; i < this->size; i++){
        if(this->elements[i] == NULL){
            os << "*";
        }else{
            os << *this->elements[i];
        }

        if (i < this->size - 1) {
            os << ",";
        }
    }

    os << "]" <<endl;

    return os;

}

template<class T>
void DynamicArray<T>::resize(int howMuch){
    //size = howMuch;

    T** newElements = new T* [howMuch];

    
    for(int i = 0; i < size; i++){
        if(elements[i] == NULL){
            newElements[i] = NULL;
        }else{
            newElements[i] = new T(*(elements[i]));
        }
    }


    for(int i = 0; i < size; i++){
        delete elements[i];
    }

    delete [] elements;

    size = howMuch;

    elements = newElements;


}
