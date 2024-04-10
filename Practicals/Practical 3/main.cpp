#include <iostream>
#include <string>

#include "cauldron.h"
#include "ingredient.h"

using namespace std;

int main(){
    cout << "First Ingredient " << endl;
    ingredient ingredient1("Pepper", 6);
    cout << "Name: " << ingredient1.getName() << endl;
    cout << "DangerRating: " << ingredient1.getDanger() << endl;
    cout << endl;

    cout << "Second Ingredient " << endl;
    ingredient ingredient2("Onion", 4);
    cout << "Name: " << ingredient2.getName() << endl;
    cout << "DangerRating: " << ingredient2.getDanger() << endl;
    cout << endl;
    

    cout << "Testing the first copy constructor (copy ingredient 2)" << endl;
    ingredient ingredient3(&ingredient2);
    cout << "Name: " << ingredient3.getName() << endl;
    cout << "DangerRating: " << ingredient3.getDanger() << endl;

    cout << endl;

    cout << "Testing the 2nd copy constructor (copy ingredient 1)" << endl;
    ingredient ingredient4(ingredient1);
    cout << "Name: " << ingredient4.getName() << endl;
    cout << "DangerRating: " << ingredient4.getDanger() << endl;

    cout << endl;

    cout << "Testing cauldron constructor" << endl;

    cout << "Cauldren 1: " << endl;
    string ingredientList = "ingredients.txt";
    int maxIngredients = 5;

    cauldron myCauldron(ingredientList, maxIngredients);
    cout << "Printing Ingredients: " << endl;
    myCauldron.printIngredients();

    cout << endl;

    cout << "Cauldren 2: " << endl;
    string ingredientList2 = "ingredients2.txt";
    int maxIngredients2 = 5;

    cauldron myCauldron2(ingredientList2, maxIngredients2);
    cout << "Printing Ingredients: " << endl;
    myCauldron2.printIngredients();

    cout << endl;

    cout << "Cauldren 3: " << endl;
    string ingredientList3 = "ingredients3.txt";
    int maxIngredients3 = 5;

    cauldron myCauldron3(ingredientList3, maxIngredients3);
    cout << "Printing Ingredients: " << endl;
    myCauldron3.printIngredients();

    cout << endl;

    cout << "Cauldren 4: " << endl;
    string ingredientList4 = "ingredients4.txt";
    int maxIngredients4 = 5;

    cauldron myCauldron4(ingredientList4, maxIngredients4);
    cout << "Printing Ingredients: " << endl;
    myCauldron4.printIngredients();

    cout << endl;

    cout << "Testing Cauldron Copy Constructor: " << endl;

    cout << "copy cauldron 1: " << endl;
    cauldron copyCauldron(&myCauldron);
    copyCauldron.printIngredients();

    cout << "copy cauldron 2: " << endl;
    cauldron copyCauldron2(&myCauldron2);
    copyCauldron2.printIngredients();

    cout << "copy cauldron 3: " << endl;
    cauldron copyCauldron3(&myCauldron3);
    copyCauldron3.printIngredients();

    cout << endl;

    cout << "Testing the assignment operator: " << endl;

    myCauldron = myCauldron4;

    cout << endl;

    cout << "Cauldron 1: " << endl;
    myCauldron.printIngredients();

    cout << endl;

    cout << "Cauldron 4: " << endl;
    myCauldron4.printIngredients();

    cout << endl;

    myCauldron.print();

    cout << endl;

    cout << "Adding Ingredients to the list " << endl;

    myCauldron4.addIngredient("lion mane", 5);
    myCauldron4.addIngredient("fish scale", 3);
    myCauldron4.addIngredient("star", 10);

    myCauldron4.print();

    cout << endl; 

    myCauldron4.printIngredients();

    cout << endl;

    cout << "Testing the remove: " << endl;

    myCauldron2.removeIngredient(0);

    cout << endl;

    myCauldron2.printIngredients();

    cout << endl;

    cout << "Testing Distill potion: " << endl;
    
    string removeFromList[] = {"mandrake root", "basilisk scale"};

    

    myCauldron3.distillPotion(myCauldron3, removeFromList, 2);

    myCauldron3.printIngredients();

    cout << endl;

    cout << "Testing list ingredients: " << endl;
    myCauldron3.listIngredients();

    cout << endl;



    return 0;

};
