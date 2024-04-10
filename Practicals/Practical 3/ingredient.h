#ifndef INGREDIENTS_H
#define INGREDIENTS_H
#include <string>

using namespace std;

class ingredient{
    private:
        string name;
        int dangerRating;

    public:
        ingredient(string name, int dangerRating);

        ingredient(const ingredient* newIngredient);
        ingredient(const ingredient& newIngredient);
        
        ~ingredient();

        int getDanger();
        string getName();
};
#endif