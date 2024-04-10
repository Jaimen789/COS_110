#include <iostream>
#include "dieselLocomotive.h"

using namespace std;

dieselLocomotive::dieselLocomotive(){
    passengerLimit = 0;
}

dieselLocomotive::~dieselLocomotive(){}

int dieselLocomotive::getPassengerLimit(){
    return passengerLimit;
}

void dieselLocomotive::setPassengerLimit(int s){
    passengerLimit = s;
}

void dieselLocomotive::determineRouteStatistics(){
    // M -> 50 people
    // N -> 25 people
    // P -> 10 passengers

    int oX = 0;
    int oY = 0;

    int eX = 0;
    int eY = 0;

    int distance = 0;

    int passengersCarried = 0;

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

            if(this->getMapAt(i,j) == 'M'){
                passengersCarried += 50;
                distance++;
            }

            if(this->getMapAt(i,j) == 'N'){
                passengersCarried += 25;
                distance++;
            }

            if(this->getMapAt(i,j) == 'P'){
                passengersCarried += 10;
                distance++;
            }
        }
    }

    

    cout << "Name: " << this->getName() << endl;
    cout << "Origin Co-ordinates: " << oX << ", " << oY << endl;
    cout << "Exit Co-ordinates: " << eX << ", " << eY << endl;
    cout << "Distance: " << distance << endl;
    cout << "Passengers Carried: " << passengersCarried << endl;

    if(passengersCarried <= passengerLimit){
        cout << "Status: Viable" << endl;
    }else{
        cout << "Status: Not Viable -> not enough space on train" << endl;
    }

}