#include<iostream>
#include<string>
#include "team.h"

using namespace std;

Team:: Team(string tName, string tID, int sizeTeam, int rank){
    this->trainerName = tName;
    this->trainerId = tID;
    this->teamLimit = sizeTeam;
    this->rank = rank;

    //initialize array
    list = new Creature*[teamLimit];

    for(int i = 0; i < teamLimit ; i++){
        list[i] = 0;
    }
}

Team:: Team(string tName, string tID, int rank, Creature ** creatures, int SizeTeam, int currSize){
    this->trainerName = tName;
    this->trainerId = tID;
    this->rank = rank;
    teamLimit = SizeTeam;
    teamSize = currSize;

    
    list = new Creature*[teamLimit];

    for(int i = 0; i < teamSize; i++){
        list[i] = new Creature(creatures[i]);
    }

    for(int i = currSize; i < teamLimit; i++){
        list[i] = 0;
    }
}

Team::~Team(){
    for(int i = 0; i < teamSize; i++){
        delete list[i];
    }

    delete [] list;
}

int Team::addCreature(Creature* c){
    
    if(teamSize < teamLimit){
        for(int i = 0; i < teamLimit; i++){
            if(list[i] == nullptr){
                list[i] = c;
                teamSize++;
                return i;
            }
        }
    }
    return -1;
}

int Team::removeCreature(string name) {
    for (int i = 0; i < teamSize; i++) {
        if (list[i] != nullptr && list[i]->getName() == name) {
            delete list[i];
            list[i] = nullptr;
            
            // Shift the remaining elements to fill the gap
            for (int j = i; j < teamSize - 1; j++) {
                list[j] = list[j + 1];
            }
            
            teamSize--;
            return i;
        }
    }
    return -1;
}

string Team::getName(){
    return trainerName;
}

string Team::getID(){
    return trainerId;
}

int Team::getCurrSize(){
    return teamSize;
}

int Team::getLimit(){
    return teamLimit;
}

void Team::printTeam(string s)
{
	int itemp;

	Creature *swap[teamLimit];
	for (int i = 0; i < teamLimit; i++)
	{
		swap[i] = list[i];
	}

    // for (int i = 0; i < teamSize; i++)
    // {
    //     if (swap[i] != nullptr)
    //     {
    //         cout << swap[i]->getName() << endl;
    //     }
    //     else
    //     {
    //         cout << "Null creature pointer at index " << i << endl;
    //     }
    // }


	cout << "Trainer Name: " << trainerName << endl;
	cout << "ID: " << trainerId << endl;
	cout << "Number of Creatures: " << teamSize << endl;
	cout << "Creature Limit: " << teamLimit << endl;
	cout << "Rank: ";

	for(int i = 0; i < rank; i++)
	{
		cout << "*";
	}
	cout << endl;

	if(s == "hp")
	//OUTPUT BY hp ASCENDING
	{
		for(int i = 0; i < teamSize; i++)
		{
			itemp = i;
			for(int j = i+1; j < teamSize; j++)
			{
				if(swap[j]->getHp() < swap[itemp]->getHp())
				{
					itemp = j;
				}
			}

			if(itemp != i)
			{
				Creature *temp = swap[i];
				swap[i] = swap[itemp];
				swap[itemp] = temp;
			}
		}
	}
	else if(s == "m")
	//OUTPUT BY mana DESCENDING
	{
		int itemp2;

		for(int i = 0; i < teamSize - 1; i++)
		{
			itemp2 = i;
			for(int j = i + 1; j < teamSize; j++)
			{
				if(swap[j]->getMana() > swap[itemp2]->getHp())
				{
					itemp2 = j;
				}
			}

			if(itemp2 != i)
			{
				Creature *temp = swap[i]; //TEMP POINTER VARIABLE
				swap[i] = swap[itemp2];
				swap[itemp2] = temp;
			}
		}
	}

	for(int i = 0; i < teamSize; i++)
	{
		cout<< swap[i]->getName() << endl;
	}

}

