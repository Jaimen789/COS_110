#include <iostream>
#include <string>

#include "weapon.h"

using namespace std;

weapon::weapon(){
    ammo = 0;
    type = "";
    name = "";
}

weapon:: weapon(int a, string t, string n){
    ammo = a;
    type = t;
    name = n;
}

weapon::~weapon(){}

int weapon::getAmmo(){
    return ammo;
}

void weapon::setAmmo(int a){
    ammo = a;
}

string weapon::getType(){
    return type;
}

void weapon::setType(string t){
    type = t;
}

string weapon::getName(){
    return name;
}

void weapon::setName(string n){
    name = n;
}

template<typename T>
void weapon::ventWeapon(T heat){
    int cycles = heat/10;

    for(int i = 0; i < cycles; i++){
        cout << "Heat Cycle: " << i + 1 << endl;
    }
}

template void weapon::ventWeapon<int>(int);
template void weapon::ventWeapon<double>(double);