#ifndef MISSILE_H
#define MISSILE_H
#include "weapon.h"

class missile : public weapon{
    public:
        missile();
        ~missile();

        string fire();
};

#endif