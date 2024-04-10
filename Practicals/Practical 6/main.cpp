#include <iostream>

#include "weapon.h"
#include "fireControl.h"
#include "laser.h"
#include "missile.h"

using namespace std;

int main(){

    try{
        laser laserCannon(70);
        laserCannon.setName("Eagle Artilllary");
        laserCannon.setAmmo(4);
        laserCannon.setType("range");
        laserCannon.setStrength(5);

        cout << laserCannon.fire() << endl;
        cout << laserCannon.fire() << endl;
        cout << laserCannon.fire() << endl;
        cout << laserCannon.fire() << endl;
        // cout << laserCannon.fire() << endl;

        cout << endl;

        cout << "Testing Vent: " << endl;
        laserCannon.ventWeapon(40);

        cout << endl;

        laserCannon.ventWeapon(35);

        cout << endl;

        laserCannon.ventWeapon(25.5);

        cout << endl;

        laserCannon.ventWeapon(75.75);

        cout << endl;

    }catch(weapon::ammoOut e){
        cout << e.what() << endl;
    }

    try{
        missile launcher1;
        launcher1.setName("Rocket Bunny");
        launcher1.setAmmo(4);
        launcher1.setType("range");

        cout << launcher1.fire() << endl;
        cout << launcher1.fire() << endl;
        cout << launcher1.fire() << endl;
        cout << launcher1.fire() << endl;
        cout << launcher1.fire() << endl;
    }catch(weapon::ammoOut e){
        cout << e.what() << endl;
    }

    cout << "Testing firecontrol: " << endl;

    string* weaponsList = new string[4];
    weaponsList[0] = "Laser Beam";
    weaponsList[1] = "laser rifle";
    weaponsList[2] = "missile pod";
    weaponsList[3] = "missiles";

    fireControl fireSystem(4,weaponsList);

    cout << "Testing accessWeapon: " << endl;
    try{
        cout << fireSystem.accessWeapon(0)->getName() << endl;
        cout << fireSystem.accessWeapon(1)->getName() << endl;
        cout << fireSystem.accessWeapon(2)->getName() << endl;
        cout << fireSystem.accessWeapon(3)->getName() << endl;
        fireSystem.print();
    }catch(fireControl::weaponFailure e){
        cout << e.what() << endl;
    }

    try{
        fireSystem.accessWeapon(4)->setAmmo(10);
        cout << fireSystem.accessWeapon(4)->getAmmo() << endl;
    }catch(fireControl::weaponFailure e){
        cout << e.what() << endl;
    }
    


    

    return 0;
}