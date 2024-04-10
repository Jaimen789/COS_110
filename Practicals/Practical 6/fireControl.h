#ifndef FIRECONTROL_H
#define FIRECONTROL_H
#include <exception>

#include "weapon.h"
using namespace std;

class fireControl{
    private:
        weapon** weapons;
        int numWeapons;

    public:
        fireControl(int numWeapons, string* weaponList);
        ~fireControl();
        weapon* accessWeapon(int i);

        void print();

        struct weaponFailure : public exception {
            public:
                const char * what() const throw(){
                    return "Weapons system failure!!!!";
                }
        };
};  

#endif