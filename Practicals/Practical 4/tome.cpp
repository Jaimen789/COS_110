#include <iostream>
#include <string>
#include <cstring>
#include "tome.h"

using namespace std;

tome::tome(string name, string author){
    this->tomeName = name;
    this->author = author;

    for(int i = 0; i < 5; i++){
        references[i] = "";
    }
}

tome::tome(string name, int tomeSize, string author, string* initialList){
    this->tomeName = name;
    this->currSpells = tomeSize;
    this->author = author;

    for(int i = 0; i < currSpells; i++){
        references[i] = initialList[i];
    }
}

tome::~tome(){}

const int tome::getTomeSize(){
    return currSpells;
}

const string tome::getSpell(int i){
    if(i < currSpells){
        for(int j = 0; j < currSpells ; j++){
            if(j == i){
                cout << references[i] << endl;
                return references[i];
            }
        }
    }else{
        cout << "Index out of Bounds" << endl;
    }
}

const string tome::getName(){
    return tomeName;
}

const string tome::getAuthor(){
    return author;
}

tome tome::operator+(const string& sub){
    int currNum = this->currSpells;

    for(int i = currNum ; i < 5; i++){
        if(references[i] == ""){
            references[i] = sub;
            currSpells++;
            return *this;
        }
    }

    return *this;
}

tome tome::operator-(const string& sub) {
    for(int i  = 0; i < currSpells; i++){
        if(references[i] == sub){
            for(int j = i; j < currSpells - 1; j++){
                references[j] = references[j + 1];
            }

            references[currSpells - 1] = "";
            currSpells--;
            break;
        }
    }

    return *this;
}

bool tome::operator>(const tome& t){
    if(currSpells > t.currSpells){
        return true;
    }

    return false;
}

bool tome::operator<(const tome& t){
    if(currSpells <= t.currSpells){
        return true;
    }

    return false;
}

tome& tome::operator=(const tome& t){
    currSpells = t.currSpells;
    author = t.author;
    for(int i = 0; i < t.currSpells; i++){
        references[i] = t.references[i];
    }
    

    return *this;
}

bool tome::operator==(const tome& t){
    if(currSpells == t.currSpells){
        for(int i = 0 ; i < currSpells; i++){
            if(references[i] == t.references[i]){
                return true;
            }
        }
    }else{
        return false;
    }
}

ostream& operator<<(ostream& output, const tome& t){
    output << "Tome Name: " << t.tomeName << endl;
    output << "Authors: " << t.author << endl;
    output << "References: ";

    for(int i = 0 ; i < t.currSpells ; i++){
        output << t.references[i];
        if(i < t.currSpells - 1){
            output << ", ";
        }
    }

    return output;

}

void tome::print(){
    for(int i = 0; i < 5; i++){
        cout << references[i] << " " << endl;
    }
}

