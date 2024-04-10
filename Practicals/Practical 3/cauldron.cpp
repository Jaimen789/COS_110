#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "cauldron.h"
#include "ingredient.h"

using namespace std;

cauldron::cauldron(string ingredientList, int maxIngredients){
    this->maxIngredients = maxIngredients;

    ifstream infile;
    infile.open(ingredientList);

    if(!infile.is_open()){cout << "Error opening file" << endl;}

    string line;
    string temp;

    string name = "";
    string dangerRating = "";

    int count = 0;
   
   ingredients = new ingredient*[maxIngredients];

   for (int i = 0; i < maxIngredients; ++i) {
        ingredients[i] = nullptr;
    }

    while(infile){
        getline(infile, line);
        

        if(!line.empty() && count < maxIngredients){
            
            // cout << "count" << count << endl;

            istringstream ss(line);

            getline(ss, temp, ',');
            getline(ss, dangerRating, ',');

            int dR = stoi(dangerRating);

            // cout << "name: " << temp << endl;
            // cout << "dR: " << dR << endl;

            ingredients[count] = new ingredient(temp, dR);
            count++;      
        }

    }

    numIngredients = count;

    infile.close();
}

cauldron::cauldron(const cauldron* oldCauldron){
    this->numIngredients = oldCauldron->numIngredients;
    this->maxIngredients = oldCauldron->maxIngredients;

    // cout << "MaxIngredients: " << maxIngredients << endl;
    // cout << "numIngredients: " << numIngredients  << endl;

    ingredients = new ingredient* [numIngredients];


    for(int i = 0; i < numIngredients; i++){   
        ingredients[i] = new ingredient(*oldCauldron->ingredients[i]);
    }

}

cauldron::~cauldron(){
    for(int i = 0; i < numIngredients; i++){
        delete ingredients[i];
    }

    delete [] ingredients;
}

void cauldron::operator=(const cauldron& oldCauldron){
    this->numIngredients = oldCauldron.numIngredients;
    this->maxIngredients = oldCauldron.maxIngredients;

    ingredients = new ingredient*[numIngredients];

    for(int i = 0; i < numIngredients; i++){
        ingredients[i] = new ingredient(oldCauldron.ingredients[i]);
    }
}

void cauldron::print(){
    cout << "Number of ingredients: " << numIngredients << endl;

    
    int sum = 0;
    int count = 0;
    double avgDr = 0;

    for(int i = 0; i < numIngredients; i++){
        sum = sum + ingredients[i]->getDanger();
        count++;
    }

    avgDr = sum/count;
    cout << "Average Danger Rating: " << avgDr << endl;

    int max = 0;

    for(int i = 0; i < numIngredients; i++){
        if(ingredients[i]->getDanger() > max){
            max = ingredients[i]->getDanger();
        }

    }

    cout << "Maximum Danger Rating: " << max << endl;

    int min = 0;

    for(int i = 0; i < numIngredients; i++){
        if(ingredients[i]->getDanger() < min){
            min = ingredients[i]->getDanger();
        }
    }

    cout << "Minimum Danger Rating: " << min << endl;

}

const int cauldron::getMax(){
    return maxIngredients;
}

int cauldron::addIngredient(string in, int dR) {
    //cout << "numIngredients " << numIngredients << endl;
    
    
    if(numIngredients < maxIngredients){
        for(int i = 0; i < maxIngredients; i++){
            if(ingredients[i] == nullptr){
                ingredients[i] = new ingredient(in,dR);
                numIngredients++;
                return i;
            }
        }
    }else{
        int newSize = maxIngredients + 1;
        ingredient **newIngredients = new ingredient*[newSize];
        
        for(int i  = 0; i < maxIngredients; i++){
            newIngredients[i] = ingredients[i];
        }

        newIngredients[maxIngredients] = new ingredient(in, dR);

        delete[] ingredients;

        ingredients = newIngredients;

        maxIngredients = newSize;
        numIngredients++;

        return maxIngredients - 1;
    }
}

    

void cauldron::removeIngredient(int in){
    for(int i = 0; i < maxIngredients; i++){
        if(i == in){
            delete ingredients[i];
            ingredients[i] = nullptr;

            for(int j = 0; j < maxIngredients - 1; j++){
                ingredients[j] = ingredients[j + 1];
                
            }
            numIngredients--;

        }else{
            return;
        }
    }
}

void cauldron::distillPotion(cauldron& currCauldron, string * list, int numRemove) {
    for (int i = 0; i < numRemove; i++) {


        for (int j = 0; j < numIngredients; j++) {

            if (list[i] == ingredients[j]->getName()) {
                delete ingredients[j];
                ingredients[j] = nullptr;

                // Shift the remaining elements to fill the gap
                for (int k = j; k < numIngredients - 1; k++) {
                    ingredients[k] = ingredients[k + 1];
                }

                // Decrement the number of ingredients
                numIngredients--;

                // Exit the loop after finding the match
                break;
            }
        }
    }
}


void cauldron::listIngredients(){
    for(int i = 0; i < numIngredients; i++){
        if(ingredients[i] != nullptr){
            cout << "Ingredient at index " << i << ": " << ingredients[i]->getName() << endl;
        }
    }
}

void cauldron::printIngredients() {
    for (int i = 0; i < numIngredients; ++i) {
        if (ingredients[i] != nullptr) {
            cout << "Ingredient at index " << i << ": " << ingredients[i]->getName()
                 << ", Danger Rating: " << ingredients[i]->getDanger() << endl;
        } else {
            cout << "No ingredient at index " << i << endl;
        }
    }
}


