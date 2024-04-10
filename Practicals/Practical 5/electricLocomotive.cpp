#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>

#include "electricLocomotive.h"

electricLocomotive::electricLocomotive(){
    perUnitCost = 0;
}

electricLocomotive::~electricLocomotive(){}

double electricLocomotive::getUnitCost(){
    return perUnitCost;
}

void electricLocomotive::setUnitCost(double s){
    perUnitCost = s;
}

void electricLocomotive::determineRouteStatistics(){
    int oX = 0;
    int oY = 0;

    int eX = 0;
    int eY = 0;

    int distance = 0;

    double cost = 0;
    int railCount = 0;

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
                railCount++;
            }

        }
    }

    cost = this->perUnitCost * railCount;

    

    cout << "Name: " << this->getName() << endl;
    cout << "Origin Co-ordinates: " << oX << ", " << oY << endl;
    cout << "Exit Co-ordinates: " << eX << ", " << eY << endl;
    cout << "Distance: " << distance << endl;
    cout << "Cost " << cost << endl;

}