#ifndef DIESELLOCOMOTIVE_H
#define DIESELLOCOMOTIVE_H

#include "locomotive.h"

class dieselLocomotive : public locomotive{
    private:
        int passengerLimit;
    
    public:
        dieselLocomotive();
        ~dieselLocomotive();

        int getPassengerLimit();
        void setPassengerLimit(int s);

        void determineRouteStatistics();
};
#endif