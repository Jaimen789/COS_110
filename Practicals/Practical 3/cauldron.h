#ifndef CAULDRON_H
#define CAULDRON_H
#include <string>
#include "ingredient.h"

using namespace std;

class cauldron{
    private:
        ingredient** ingredients;
        int numIngredients;
        int maxIngredients;

    public:
        cauldron(string ingredientList, int maxIngredients);
        cauldron(const cauldron* oldCauldron);
        void operator=(const cauldron& oldCauldron);
        ~cauldron();

        void print();

        const int getMax();
        const int gerCurr();

        const ingredient* getIngredients(int a);

        int addIngredient(string in, int dR);
        void removeIngredient(int in);

        void distillPotion(cauldron& currCauldron, string * list, int numRemove);

        void listIngredients();

        void printIngredients();

};
#endif