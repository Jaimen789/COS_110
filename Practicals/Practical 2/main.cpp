#include<iostream>
#include<string>
#include "creature.h"
#include "team.h"

using namespace std;

int main(){

    cout << "Testing creature creation: " << endl;
    Creature creature1("Dragon", "Fire", 100 , 50);
    Creature creature2("Snake", "Earth", 70 , 90);
    Creature creature3("Megladon", "Water", 110 , 40);
    Creature creature4("Eagle", "Air", 60 , 100);

    creature1.print();
    cout << endl;
    creature2.print();
    cout << endl;
    creature3.print();
    cout << endl;
    creature4.print();
    cout << endl;

    Team* team1 = new Team("Jaimen", "1", 6 , 4);
    cout << "ATeam name: " << team1->getName() << endl;
	cout << "ATeam id: " << team1->getID() << endl;
	cout << "ATeam current size: " << team1->getCurrSize() << endl;
	cout << "ATeam limit: " << team1->getLimit() << endl;
	
    cout << endl;

    cout << "Adding Creatures to the Team " << endl;

    Creature** newList = new Creature*[5];

    string names[] = {"Dragon", "Shark", "Eagle","Snake", "Human"};
    string types[] = {"Fire","Water","Air", "Earth" ,"Nuclear"};

    for(int i = 0; i < 5; i++){
        Creature* c = new Creature(names[i], types[i], i*100, 1000*i);
        newList[i] = new Creature(c);
        cout << "Position of new member: " << team1->addCreature(c) << endl;
    }
    // cout << endl;

    cout << "A Team current size:" << team1->getCurrSize() << endl;
	
	cout << "Testing remove of member shark at index: " << team1->removeCreature("Shark") << endl;
	
	cout << "A Team current size:" << team1->getCurrSize() << endl;

    cout << endl;

    cout << "Team information after sorting by HP:" << endl;
    team1->printTeam("hp");

    Team *team2 = new Team("Jaimen2", "2", 5 , newList , 5 , 5);
    team2->printTeam("hp");

    cout << endl;
     
   // team1.printTeamInfo();

    

    

   




    return 0;
}