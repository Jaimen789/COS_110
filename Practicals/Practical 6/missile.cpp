#include <iostream>
#include <sstream>
#include "missile.h"

using namespace std;

missile::missile(){}

missile::~missile(){
    cout << this->getName() << " Uninstalled!" << endl;
}

string missile::fire(){
    if(this->getAmmo() > 0){
        setAmmo(this->getAmmo() - 1);

        stringstream ss;

        ss << this->getName() << " fired!" ;
        return ss.str();
    }else{
        throw weapon::ammoOut();
    }
}