#ifndef LOCOMOTIVE_H
#define LOCOMOTIVE_H
#include "vehicle.h"

class locomotive : public vehicle{
    private:
        int supplyRange;

    public:
        locomotive();
        ~locomotive();

        int getSupplyRange();
        void setSupplyRange(int s);
        
        void determineRouteStatistics();
};
#endif