#include <iostream>

#include "matrix.h"


using namespace std;

int main(){

    matrix matrix1(2,2);
    matrix matrix2(2,1);
    matrix matrix3(2,1);
    matrix matrix4(3,3);

    matrix matrix5(3,3);
    matrix matrix6(2,2);

    matrix1.initialize();
    matrix2.initialize();

    cout << "matrix 1: " << endl;
    cout << matrix1 << endl;

    cout << endl;

    

    double det = ~matrix1;
    double* determinants =  matrix1|matrix2;

    cout << matrix3 << endl;

    matrix3 = matrix1|=matrix2;

    cout << matrix3 << endl;

    // cout << "matrix 2: " << endl;
    // cout << matrix2 << endl;

    cout << endl;

    // matrix5 = matrix1 ^ 3;

    // cout << matrix5 << endl;

    // matrix6.initialize();

    // matrix5 *= matrix6;

    // cout << matrix5 << endl;

    // cout << "matrix 3: matrix1 + matrix2 " << endl;
    // matrix3 = matrix1 + matrix2;

    // cout << matrix3 << endl;

    // matrix3 += matrix1;

    // cout << "matrix 3: matrix3 += matrix1 " << endl;
    // cout << matrix3 << endl;

    // cout << "matrix 3: matrix1 - matrix2 " << endl;
    // matrix3 = matrix1 - matrix2;

    // cout << matrix3 << endl;

    // matrix3 -= matrix1;

    // cout << "matrix 3: matrix3 -= matrix1 " << endl;
    // cout << matrix3 << endl;

    // cout << "Scalars " << endl;
    // matrix4.initialize();
    // matrix4 = matrix4 * 2;

    // cout << "matrix 4: " << endl;
    // cout << matrix4 << endl;

    // matrix4 = matrix4 / 2;
    // cout << matrix4 << endl;

    // matrix4 *= 2;
    // cout << matrix4 << endl;

    



    
    return 0;
}