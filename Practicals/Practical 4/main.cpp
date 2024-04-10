#include <iostream>
#include "tome.h"

using namespace std;

int main(){

    string spellList[] = {"Lumos Aeternum", "Aqua Vortex", "Silentum Obscurum" , "Pyroclasmic Ignition"};
    string spellList2[] ={"Chrono Shield" , "Mystical Illusion", "Gala's embrace"};


    tome book1("The Magisterial Cookbook", 4 ,"Jaimen" , spellList);
    tome book2("Eye of Newt & Other Curses", 3 , "James", spellList2);
    tome book3("The Magisterial Cookbook", 4 ,"Jaimen" , spellList);

    book1.print();

    cout << endl;

    book2.print();

    cout << endl;

    book3.print();

    cout << endl;

    cout << "Testing getSpell(): " << endl;
    book1.getSpell(1);

    cout << endl;

    cout << "Testing add spell: " << endl;
    book1+"Temporal";

    cout << endl;
    book1.print();

    cout << endl;

    book3+"Temporal";

    cout << endl;
    book3.print();

    cout << endl;

    book1+"Temporal2";
    book1.print();

    cout <<endl;

    cout << "Testing spell remove: " << endl;
    book1-"Temporal";
    book1.print();
    
    cout << endl;

    book3-"Temporal";
    book3.print();
    
    cout << endl;

    book2.print();

    cout << "Testing less than symbol: " << endl;

     if (book1 < book2) {
        cout << book1.getName() << " has fewer spells than " << book2.getName() << std::endl;
    } else {
        cout << book1.getName() << " does not have fewer spells than " << book2.getName() << std::endl;
    }

    // Test the operator>
    if (book1 > book2) {
        cout << book1.getName() << " has more spells than " << book2.getName() << std::endl;
    } else {
        cout << book1.getName() << " does not have more spells than " << book2.getName() << std::endl;
    }

    cout << endl;

    cout << "Testing = operator: " << endl;
    book1=book2;

    book1.print();

    cout << endl;


    cout << "Testing == operator: " << endl;
    if(book1 == book2){
        cout << "books are equal." << endl;
    }else{
        cout << "books are not  equal." << endl;
    }

    if(book1 == book3){
        cout << "books are equal." << endl;
    }else{
        cout << "books are not  equal." << endl;
    }

    cout << endl;

    cout << "Testing <<: " << endl;
    cout << book1 << endl;

    cout << endl;

    cout << book3 << endl;

   


    return 0;
}