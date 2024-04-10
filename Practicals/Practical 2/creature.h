#ifndef CREATURE_H
#define CREATURE_H
#include <string>  
using namespace std;

class Creature{
    private:

        string name;
        string type;
        int hp;
        double mana;

    public:
        Creature(Creature* c);
        Creature(string name, string type, int hp, double mana);
        ~Creature();
        string getName();
        string getType();
        int getHp();
        double getMana();

        void print();
};

#endif