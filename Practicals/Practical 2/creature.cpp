#include<iostream>
#include<string>
#include "creature.h"

using namespace std;

Creature::Creature(Creature* c){
    name = c->name;
    type = c->type;
    hp = c->hp;
    mana = c->mana;

}

Creature::Creature(string name, string type, int hp, double mana){
    this->name = name;
    this->type = type;
    this->hp = hp;
    this->mana = mana;
}

Creature::~Creature(){
    cout << name << " deleted." << endl;
}

string Creature::getName(){
    return name;
}

string Creature::getType(){
    return type;
}

int Creature::getHp(){
    return hp;
}

double Creature::getMana(){
    return mana;
}

void Creature::print(){
    cout << "Name: " << name << endl;
    cout << "Type: " << type << endl;
    cout << "HP: " << hp << endl;
    cout << "Mana: " << mana <<  endl;
}


