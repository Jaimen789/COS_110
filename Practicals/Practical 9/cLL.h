#ifndef CLL_H
#define CLL_H

#include "citem.h"

template<class T>
class cLL{
    private:
        citem<T>* head;
        int size;

    public:
        cLL();
        ~cLL();

        bool isEmpty();

        int getSize();

        T maxNode();

        void push(citem<T>* newItem);

        citem<T>* pop();

        citem<T>* removeAt(T x);

        void printList();

};

#endif