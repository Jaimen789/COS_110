#include <iostream>
#include "fireControl.h"
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include "weapon.h"
#include "laser.h"
#include "missile.h"


using namespace std;

fireControl::fireControl(int numofWeapons, string* weaponList) {
    numWeapons = numofWeapons;
    weapons = new weapon*[numWeapons];

    cout << "numWeapons: " << numofWeapons << endl;

    for(int i = 0; i < numofWeapons; i++){
        
        string text = weaponList[i];
        // cout << "i: " << i << endl;
        // cout << "text: " << text << endl;
        if(text.find("Laser") != string::npos|| text.find("laser") != string::npos){
            
            weapons[i] = new laser(5);
            weapons[i]->setName(weaponList[i]);
            weapons[i]->setType("Laser");

            cout << "weapons laser: " << weapons[i]->getName() << " at index: "<< i << endl;

        }

        cout << "============================================" << endl;

        if(text.find("missile") != string::npos|| text.find("missiles") != string::npos){
            weapons[i] = new missile();
            weapons[i]->setName(weaponList[i]);
            weapons[i]->setType("Missile");

            cout << "weapons missiles: " << weapons[i]->getName() << " at index: "<< i << endl;
        }
    }

    // cout << "======================================" << endl;

    // for(int i = 0; i < numofWeapons; i++){
        
    //     string text = weaponList[i];
    //     // cout << "i: " << i << endl;
    //     // cout << "text: " << text << endl;
    //     if(text.find("missile") != string::npos|| text.find("missiles") != string::npos){
    //         weapons[i] = new missile();
    //         weapons[i]->setName(weaponList[i]);
    //         weapons[i]->setType("Missile");

    //         cout << "weapons missiles: " << weapons[i]->getName() << endl;
    //     }
    // }    

}

void fireControl::print(){
    for(int i = 0; i < this->numWeapons; i++){
        cout << weapons[i] << endl;
    }
}

fireControl::~fireControl(){
    for(int i = 0; i < this->numWeapons; i++){
        delete weapons[i];
    }

    delete [] weapons;
}

weapon* fireControl::accessWeapon(int i){
    for(int j = 0; j < numWeapons; j++){
        if(i < 0) throw weaponFailure();
        if(i >= numWeapons) throw weaponFailure();
        if(j == i){
            return weapons[j];
        }
    }
}