#include <iostream>

#include "vehicle.h"
#include "locomotive.h"
#include "dieselLocomotive.h"
#include "electricLocomotive.h"

using namespace std;

int main() {

    cout << "Testing locomotive.cpp: " << endl;

    locomotive locomotive1;
    locomotive1.setName("Fire Dragon");
    locomotive1.setSupplyRange(8);

    cout << "Setting the map: " << endl;
    locomotive1.setMap("map2.txt");
    
    cout << endl;

    cout << "Size of " << locomotive1.getName() << "is : " << locomotive1.getSize() << endl;

    locomotive1.determineRouteStatistics();

    cout << endl;

    cout << "Testing DieselLocomotive.cpp: " << endl;
    dieselLocomotive dieselLocomotive1;
    dieselLocomotive1.setName("Black Dragon");
    dieselLocomotive1.setMap("map4.txt");
    cout << "Size of " << dieselLocomotive1.getName() << " map is " << dieselLocomotive1.getSize() << endl;
    dieselLocomotive1.setPassengerLimit(55);
    dieselLocomotive1.determineRouteStatistics();

    cout << endl;

    cout << "Testing electricLocomotive.cpp: " << endl;
    electricLocomotive electricLocomotive1;
    electricLocomotive1.setName("Gold Dragon");
    electricLocomotive1.setMap("map1.txt");
    cout << "Size of " << electricLocomotive1.getName() << " map is " << electricLocomotive1.getSize() << endl;
    electricLocomotive1.setUnitCost(10.50);
    electricLocomotive1.determineRouteStatistics();

    cout << endl;




}