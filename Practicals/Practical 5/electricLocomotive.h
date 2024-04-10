#ifndef ELECTRICLOCOMOTIVE_H
#define ELECTRICLOCOMOTIVE_H

#include "locomotive.h"

class electricLocomotive : public locomotive{
    private:
        double perUnitCost;

    public:
        electricLocomotive();
        ~electricLocomotive();

        double getUnitCost();
        void setUnitCost(double s);

        void determineRouteStatistics();
};
#endif