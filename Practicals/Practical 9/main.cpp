#include <iostream>
#include "ditem.h"
#include "ditem.cpp"

#include "dLL.h"
#include "dLL.cpp"

#include "citem.h"
#include "citem.cpp"

#include "cLL.h"
#include "cLL.cpp"

using namespace std;

int main(){

    cout << "Doubly Linked List: " << endl;

    ditem<int>* item1 = new ditem(10);
    ditem<int>* item2 = new ditem(5);
    ditem<int>* item3 = new ditem(15);
    ditem<int>* item4 = new ditem(28);
    ditem<int>* item5 = new ditem(17);

    dLL<int> dList;
    dList.push(item1);
    dList.push(item2);
    dList.push(item3);
    dList.push(item4);
    dList.push(item5);

    dList.printList();

    dList.pop();
    dList.pop();

    dList.printList();

    cout << dList.getItem(0)->getData() << endl;
    cout << dList.getItem(1)->getData() << endl;
    cout << dList.getItem(2)->getData() << endl;

    cout << endl;

    cout << "Circular Linked List: " << endl;
    citem<double>* item6 = new citem(30.23);
    citem<double>* item7 = new citem(55.89);
    citem<double>* item8 = new citem(22.45);
    citem<double>* item9 = new citem(88.62);
    citem<double>* item10 = new citem(72.07);

    cLL<double> cList;

    cList.push(item6);
    cList.push(item7);
    cList.push(item8);
    cList.push(item9);
    cList.push(item10);

    cList.printList();

    cout << endl;

    cList.pop();

    cList.printList();

    cout << endl;

    cList.removeAt(22.45);

    cList.printList();


    return 0;
}