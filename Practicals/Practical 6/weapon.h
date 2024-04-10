#ifndef WEAPONS_H
#define WEAPONS_H
#include <string>
#include <exception>

using namespace std;

class weapon{

    private:
        int ammo;
        string type;
        string name;
    
    public:
        weapon();
        weapon(int a, string t, string n);

        int getAmmo();
        void setAmmo(int a);

        string getType();
        void setType(string t);

        string getName();
        void setName(string n);

        template<typename T>
        void ventWeapon(T heat);

        virtual ~weapon();
        virtual string fire() = 0;

        struct ammoOut : public exception{
            public:
                const char * what() const throw(){
                    return "Ammo Depleted";
                }
        };
};

#endif