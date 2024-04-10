#include <iostream>
#include <string>
#include "item.h"
#include "item.cpp"

#include "LL.h"
#include "LL.cpp"

using namespace std;

int main(){

    item<string>* item1 = new item<string>("Oranges");
    item<double>* item2 = new item<double>(30.55);

    item<int>* item3 = new item<int>(88);
    item<int>* item4 = new item<int>(10);
    item<int>* item5 = new item<int>(55);
    item<int>* item6 = new item<int>(78);
    item<int>* item7 = new item<int>(5);    
    item<int>* item8 = new item<int>(93);
    item<int>* item9 = new item<int>(57);
    item<int>* item10 = new item<int>(28);
    item<int>* item11 = new item<int>(95);    
    item<int>* item12 = new item<int>(100);

    LL<int> LL1(5);
    LL1.addItem(item3);
    LL1.addItem(item4);
    LL1.addItem(item8);
    LL1.addItem(item5);
    LL1.addItem(item6);
    LL1.addItem(item7);

    cout << endl;

    LL1.printList();

    cout << "=================" << endl;

    LL<int> LL2(3);
    
    LL2.addItem(item9);
    LL2.addItem(item11);
    LL2.addItem(item10);
    LL2.addItem(item12);

    LL2.printList();

    cout << "==================" << endl;

    LL2.randonShuffleList();

    LL2.printList();

    cout << "====================" << endl;

    LL2.randonShuffleList(2);

    LL2.printList();

    cout << "====================" << endl;

    // LL2.pop();

    LL2.printList();

    cout << endl;

    LL2.reverseList();
    
    cout << endl;

    LL2.printList();

    cout << endl;


    // cout << "String Item Data: " << item1->getData() << std::endl;
    // cout << "Integer Item Data: " << item2->getData() << std::endl;
    // cout << "Double Item Data: " << item3->getData() << std::endl;
   

    return 0;
}