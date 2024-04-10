#include <iostream>
#include <string>

#include "heatNode.h"
#include "heatStack.h"

#include "heatNode.cpp"
#include "heatStack.cpp"

#include "msgNode.h"
#include "msgNode.cpp"

#include "msgQueue.h"
#include "msgQueue.cpp"

using namespace std;

int main(){

    cout << "HeatStack: " << endl;
    heatStack<double> heatStack1;

    heatNode<double>* node1 = new heatNode(34.78, 12);
    heatNode<double>* node2 = new heatNode(65.43, 24);
    heatNode<double>* node3 = new heatNode(12.34, 22);
    heatNode<double>* node4 = new heatNode(56.78, 44);
    heatNode<double>* node5 = new heatNode(45.67, 50);
    heatNode<double>* node6 = new heatNode(75.67, 53);

    heatStack1.push(node1);
    heatStack1.push(node2);
    heatStack1.push(node3);
    heatStack1.push(node4);
    heatStack1.push(node5);

    heatStack1.print();

    heatStack1.pop();

    cout << "=======================" << endl;

    heatStack1.print();

    cout << "=======================" << endl;

    heatStack1.push(node6);

    heatStack1.print();

    int* arr = new int[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = 10 * (i + 1);
    }


    heatStack1.validateCooling(arr,5);

    cout << endl;

    cout << "msgQueue: " << endl;
    
    msgQueue<string> msgQueue1;

    string string1 = "Hello World";
    string string2 = "C++ is awesome!";
    string string3 = "Programming is fun!";
    string string4 = "Strings in C++ are versatile.";
    string string5 = "Learning new things every day.";

    size_t sizeInBytes1 = string1.size();
    size_t sizeInBytes2 = string2.size();
    size_t sizeInBytes3 = string3.size();
    size_t sizeInBytes4 = string4.size();
    size_t sizeInBytes5 = string5.size();

    double sizeInKB1 = static_cast<double>(sizeInBytes1) / 1024.0;
    double sizeInKB2 = static_cast<double>(sizeInBytes2) / 1024.0;
    double sizeInKB3 = static_cast<double>(sizeInBytes3) / 1024.0;
    double sizeInKB4 = static_cast<double>(sizeInBytes4) / 1024.0;
    double sizeInKB5 = static_cast<double>(sizeInBytes5) / 1024.0;

    // std::cout << "Size in KB 1: " << sizeInKB1 << std::endl;
    // std::cout << "Size in KB 2: " << sizeInKB2 << std::endl;
    // std::cout << "Size in KB 3: " << sizeInKB3 << std::endl;
    // std::cout << "Size in KB 4: " << sizeInKB4 << std::endl;
    // std::cout << "Size in KB 5: " << sizeInKB5 << std::endl;

    msgNode<string>* msg1 = new msgNode(string1,sizeInKB1);
    msgNode<string>* msg2 = new msgNode(string2,sizeInKB2);
    msgNode<string>* msg3 = new msgNode(string3,sizeInKB3);
    msgNode<string>* msg4 = new msgNode(string4,sizeInKB4);
    msgNode<string>* msg5 = new msgNode(string5,sizeInKB5);

    msgQueue1.enqueue(msg1);
    msgQueue1.enqueue(msg2);
    msgQueue1.enqueue(msg3);
    msgQueue1.enqueue(msg4);
    msgQueue1.enqueue(msg5);


    msgQueue1.print();

    cout << endl;

    msgQueue1.dequeue();
    // msgQueue1.dequeue();
    // msgQueue1.dequeue();
    // msgQueue1.dequeue();
    // msgQueue1.dequeue();
    // msgQueue1.dequeue();

    msgQueue1.print();

    cout << endl;

    msgQueue1.compileMessageData();

    cout << endl;





    return 0;
}