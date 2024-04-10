#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

using namespace std;

class matrix {
    friend ostream& operator<<(ostream& output, const matrix& m);
    private:
        int rows;
        int columns;
        double** matrixArr;

        //linear equations
        double denominator;
        double* linearDeterminants;
        double* linearSolutions;


    public:
        matrix(int r, int c);
        ~matrix();

        void initialize();

        matrix(const matrix& other); //copy constructor
        matrix& operator=(const matrix &rhs); //assign one obj to another
        double* operator[](int row) const;
        
        //arithmetic operations:
        matrix operator+(const matrix& rhs);
        matrix& operator+=(const matrix& rhs);

        matrix operator-(const matrix& rhs);
        matrix& operator-=(const matrix& rhs);

        matrix operator*(const matrix &rhs);
        matrix &operator*=(const matrix &rhs);

        matrix operator^(int pow);
        matrix &operator^=(int pow);

        //scalars
        matrix operator*(const double &rhs);
        matrix& operator*=(const double &rhs);  
        matrix operator/(const double &rhs);

        //linear equations:
        double operator~();
        double* operator|(matrix& rhs);
        matrix operator|=(matrix &rhs);
        

        //getters:
        int getRows() const;
        int getCols() const;

};

#endif
