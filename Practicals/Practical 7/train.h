#ifndef TRAIN_H
#define TRAIN_H

#include "bin.h"

template<class T>
class train{
    private:
        bin<T>** storage;
        int bins;

    public:
        train(int numBins);
        ~train();

        int addBin(bin<T>* item);
        int addBin(int index, bin<T>* item);

        int removeBin(int index);
        int removeBin(int index, bin<T>* item);

        void printStorage();

};

#endif