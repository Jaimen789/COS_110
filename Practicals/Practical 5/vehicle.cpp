#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>

#include "vehicle.h"


using namespace std;

vehicle::vehicle(){
    name = "";
    size = 0;
}

void vehicle::setName(string s){
    name = s;
}

string vehicle::getName(){
    return name;
}

char** vehicle::getMap(){
    return map;
}

int vehicle::getSize(){
    return size;
}

void vehicle::setMap(string s){

    ifstream infile(s);

    string line;
    string sizeStr = "";
    char data;

    if (getline(infile, sizeStr)) {
        size = stoi(sizeStr);

        //cout << "size: " << sizeStr << endl;
        // Allocate memory for the map based on size
        map = new char*[size];
        for (int i = 0; i < size; ++i) {
            map[i] = new char[size];
        }
    }


    for (int i = 0; i < size && infile >> line; ++i) {
        for (int j = 0; j < size; ++j) {
            map[i][j] = line[j];
            cout << map[i][j];
        }
        cout << endl;
    }
    
    
}

char vehicle::getMapAt(int x, int y){
    return map[x][y];
}

vehicle::~vehicle(){
    for(int i = 0; i < size; i++){
        delete [] map[i];
    }

    delete [] map;
    map = nullptr;
}

void vehicle::operator--()
{

	for (int i = 0; i < size; i++)
	{
		delete [] map[i];
	}
	delete [] map; 
    map = nullptr;
}


void vehicle::determineRouteStatistics(){}