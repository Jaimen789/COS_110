#include<iostream>

#include "bin.h"
#include "bin.cpp"

#include "train.h"
#include "train.cpp"

using namespace std;

int main(){

    train<int> train1(3);
    train<double> train2(3);

    bin<int>* bin1 = new bin<int>(10);
    bin<int>* bin2 = new bin<int>(20);
    bin<int>* bin3 = new bin<int>(30);

    bin<double>* bin4 = new bin<double>(10.55);
    bin<double>* bin5 = new bin<double>(20.79);
    bin<double>* bin6 = new bin<double>(30.99);

   cout << endl;


    train1.addBin(bin1);
    train1.addBin(bin2);
    train1.addBin(bin3);

    cout << endl;

    train1.printStorage();

    cout << endl;

    train2.addBin(0, bin4);
    train2.addBin(1, bin5);
    train2.addBin(2, bin6);

    cout << endl;

    train2.printStorage();

    cout << endl;

    train1.removeBin(0);
    train1.removeBin(1);

    train1.printStorage();

    cout << endl;

    train2.removeBin(0,bin4);

    train2.printStorage();

    cout << endl;

    // delete bin1;
    // delete bin2;
    // delete bin3;
    


    return 0;
}