#ifndef TOME_H
#define TOME_H
#include <string>

using namespace std;

class tome{
    private:
        string references[5];
        string tomeName;
        string author;
        int currSpells;
    
    public:
        tome(string name, string author);
        tome(string name, int tomeSize, string author, string* initialList);
        ~tome();

        const int getTomeSize();
        const string getSpell(int i);
        const string getName();
        const string getAuthor();
        
        friend ostream& operator<<(ostream& output, const tome& t);

        tome operator+(const string& add);
        tome operator-(const string& sub);

        
    
        bool operator>(const tome& t);
        bool operator<(const tome& t);
        
        tome& operator=(const tome& t);
        bool operator==(const tome& t);

        void print();
        

};
#endif