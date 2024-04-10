#ifndef ITEM_H
#define ITEM_H

using namespace std;


#include <string>
#include <iostream>
#include <cstdlib>

template <class T>

class item 
{
private:
	T data;

public:
	item(T t);
	~item();
	item* next;
	T getData();
	
};
 #endif