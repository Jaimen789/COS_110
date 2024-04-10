#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>

#include "locomotive.h"

locomotive::locomotive(){
    supplyRange = 0;
}

locomotive::~locomotive(){
    cout << "Locomotive: " << this->getName() << " Removed." << endl;
}

int locomotive::getSupplyRange(){
    return supplyRange;
}

void locomotive::setSupplyRange(int s){
    supplyRange = s;
}

void locomotive::determineRouteStatistics(){
    // * -> Supply Station
    // O -> Origin Point
    // E -> Exit Point
    // # -> Rail Road
    int oX = 0;
    int oY = 0;

    int eX = 0;
    int eY = 0;

    int distance = 0;

    int numStations = 0;

    for(int i = 0; i < this->getSize(); i++){
        for(int j = 0; j < this->getSize(); j++){
            if(this->getMapAt(i,j) == 'O'){
                //cout << this->getMapAt(i,j) << endl;
                oX = i;
                oY = j;
            }

            if(this->getMapAt(i,j) == 'E'){
                eX = i;
                eY = j;
            }

            if(this->getMapAt(i,j) == '#'){
                distance++;
            }

            if(this->getMapAt(i,j) == '*'){
                numStations++;
            }
        }
    }

    

    cout << "Name: " << this->getName() << endl;
    cout << "Supply Range: " << supplyRange << endl;
    cout << "Origin Co-ordinates: " << oX << ", " << oY << endl;
    cout << "Exit Co-ordinates: " << eX << ", " << eY << endl;
    cout << "Distance: " << distance << endl;
    cout << "Number of Stations: " << numStations << endl;

    if(supplyRange > distance || numStations > 1){
        cout << "Status: Viable" << endl;
    }else{
        cout << "Status: Not Viable" << endl;
    }
}