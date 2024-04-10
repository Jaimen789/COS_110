#include <iostream>
#include <sstream>

#include "laser.h"


laser::laser(int s){
    strength = s;
}

laser::~laser(){
    cout << this->getName() << " Uninstalled!" << endl;
}

int laser::getStrength(){
    return strength;
}

void laser::setStrength(int s){
    strength = s;
}

string laser::fire(){
    int oldStrength = strength;

    if(this->getAmmo() > 0){
        setAmmo(this->getAmmo() - 1);
        strength++;

        stringstream ss;
        ss << this->getName() << " fired at strength: " << oldStrength;
        return ss.str();

    }else{
        throw weapon::ammoOut();
    }

    
}