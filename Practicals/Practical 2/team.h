#ifndef TEAM_H
#define TEAM_H
#include<string>
#include "creature.h"

using namespace std;

class Team{
    private:
        Creature ** list; // points to an array of pointers that point to the creatures
        string trainerName;
        string trainerId;
        int rank;
        int teamLimit;
        int teamSize;
    public:
        Team(string tName, string tID, int sizeTeam, int rank);
        Team(string tName, string tID, int rank, Creature ** creatures, int SizeTeam, int currSize);
        ~Team();

        int addCreature(Creature* c);
        int removeCreature(string name);

        string getName();
        string getID();
        int getCurrSize();
        int getLimit();
        
        void printTeam(string s);
        void printTeamInfo();
};
#endif