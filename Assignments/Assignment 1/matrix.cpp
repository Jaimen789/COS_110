#include <iostream>
#include "matrix.h"

using namespace std;

matrix::matrix(int r, int cols){
    rows = r;
    columns = cols;

    matrixArr = new double*[rows];
    for(int i = 0; i < rows; i++){
        matrixArr[i] = new double[columns];
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            matrixArr[i][j] = 0;
        }
    }

    linearDeterminants = nullptr;
    linearSolutions = nullptr;
    denominator = 0;

}

matrix::~matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] matrixArr[i];
    }

    delete[] matrixArr;

}



void matrix::initialize(){
    if(rows < 0 || columns < 0){
        cout << "Array is invalid." << endl;
    }else{
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                cout << "Enter value for matrix[" << i << "][" << j << "]: " << endl;
                cin >> matrixArr[i][j];
            }
        }
    }

    
}

ostream& operator<<(ostream& output, const matrix& m){
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.columns; ++j) {
            output << m.matrixArr[i][j] << "\t";
        }
        output << endl;
    }

    return output;
}


matrix& matrix::operator=(const matrix &rhs){

    if(this == &rhs){
        return *this;
    }

    rows = rhs.rows;
    columns = rhs.columns;

    matrixArr = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        matrixArr[i] = new double[columns];
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            matrixArr[i][j] = rhs.matrixArr[i][j];
        }
    }

    return *this;

}

matrix::matrix(const matrix& other){
    rows = other.rows;
    columns = other.columns;

    matrixArr = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        matrixArr[i] = new double[columns];
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            matrixArr[i][j] = other.matrixArr[i][j];
        }
    }
}

int matrix::getRows() const{
    return rows;
}

int matrix::getCols() const{
    return columns;
}


matrix matrix::operator+(const matrix& rhs){
    if(this->rows == rhs.rows && this->columns == rhs.columns){
        matrix resMatrix(rows, columns);

        for(int j = 0; j < rows; j++){
            for(int k = 0; k < columns; k++){
                resMatrix.matrixArr[j][k] = this->matrixArr[j][k] + rhs.matrixArr[j][k];
            }
        }

        return resMatrix;
    }else{
        cout << "Invalid: MatrixA and MatrixB have different dimensions." << endl;
    }
}

matrix& matrix::operator+=(const matrix& rhs){
    if(this->rows == rhs.rows && this->columns == rhs.columns){

        for(int j = 0; j < rows; j++){
            for(int k = 0; k < columns; k++){
                this->matrixArr[j][k] = this->matrixArr[j][k] + rhs.matrixArr[j][k];
            }
        }

        return *this;
    }else{
        cout << "Invalid: MatrixA and MatrixB have different dimensions." << endl;
    }
}

matrix matrix::operator-(const matrix& rhs){
    if(this->rows == rhs.rows && this->columns == rhs.columns){
        matrix resMatrix(rows, columns);

        for(int j = 0; j < rows; j++){
            for(int k = 0; k < columns; k++){
                resMatrix.matrixArr[j][k] = this->matrixArr[j][k] - rhs.matrixArr[j][k];
            }
        }

        return resMatrix;
    }else{
        cout << "Invalid: MatrixA and MatrixB have different dimensions." << endl;
    }
}

matrix& matrix::operator-=(const matrix& rhs){
    if(this->rows == rhs.rows && this->columns == rhs.columns){

        for(int j = 0; j < rows; j++){
            for(int k = 0; k < columns; k++){
                this->matrixArr[j][k] = this->matrixArr[j][k] - rhs.matrixArr[j][k];
            }
        }

        return *this;
    }else{
        cout << "Invalid: MatrixA and MatrixB have different dimensions." << endl;
    }
}

double* matrix::operator[](int row) const{
    if(row < 0 || row > rows){
        cout << "Invalid Index." << endl;
    }

    return matrixArr[row];
}

matrix matrix::operator*(const matrix &rhs){
    // Matrix A's columns == Matrix B's Rows
    //matrix 1 cols[i] * matrix 2 rows[j]

    if(this->columns != rhs.rows){
        cout << "Invalid dimensions for multiplication." << endl;
    }
    
    matrix res_matrix(this->rows, rhs.columns);

    double finalResult;

    for(int i = 0; i < res_matrix.rows; i++){
        for(int j = 0; j < res_matrix.columns; j++){
            for(int k = 0; k < columns; k++){
                res_matrix[i][j] += (matrixArr[i][k] * rhs.matrixArr[k][j]);
            }
        }
    }

    return (*this = res_matrix);
    
}

matrix& matrix::operator*=(const matrix &rhs){
    // Matrix A's columns == Matrix B's Rows
    //matrix 1 cols[i] * matrix 2 rows[j]

    if(this->columns != rhs.rows){
        cout << "Invalid dimensions for multiplication." << endl;
    }
    
    matrix res_matrix(this->rows, rhs.columns);

    double finalResult;

    for(int i = 0; i < res_matrix.rows; i++){
        for(int j = 0; j < res_matrix.columns; j++){
            for(int k = 0; k < columns; k++){
                res_matrix[i][j] += (matrixArr[i][k] * rhs.matrixArr[k][j]);
            }
        }
    }

    return (*this = res_matrix);
    
}

matrix matrix::operator^(int pow){
    matrix res_matrix(this->rows, this->columns);

    if(pow  == 0){
        if(this->rows == this->columns){
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    if(i == j){
                        res_matrix[i][j] = 1;
                    }else{
                        res_matrix[i][j] = 0;
                    }
                }
            }
        }else{
            cout << "Invalid: Original Matrix is not a square." << endl;
        }

        return (*this = res_matrix);
    }

    if(pow ==  1){
        return *this;
    }

    //initialize res_matrix with the identity matrix 
    //and then perform the multiplication with the original matrix (*this)
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(i == j){
                res_matrix[i][j] = 1;
            } else {
                res_matrix[i][j] = 0;
            }
        }
    }

    while(pow > 0){
        if(pow % 2 == 1){
            res_matrix = res_matrix * (*this);
        }

        (*this) *= (*this);
        pow = pow / 2;
    }

    return res_matrix;

}

matrix matrix::operator*(const double &rhs){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            this->matrixArr[i][j] = this->matrixArr[i][j] * rhs;
        }
    }

    return *this;
}

matrix& matrix::operator*=(const double &rhs){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            this->matrixArr[i][j] = this->matrixArr[i][j] * rhs;
        }
    }

    return *this;
}


matrix matrix::operator/(const double &rhs){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            this->matrixArr[i][j] = this->matrixArr[i][j] / rhs;
        }
    }

    return *this;
}


double matrix::operator~(){
    if(this->rows == 2 && this->columns == 2){
        double determinant = 0;
        double rtl = 0;
        double ltr = 0;

        rtl = matrixArr[0][0] * matrixArr[1][1];
        ltr = matrixArr[0][1] * matrixArr[1][0];

        determinant = rtl - ltr;

       denominator = determinant;
       return determinant;

    }else if(this->rows == 3 && this->columns == 3){
        double multiplier1 = matrixArr[0][0];
        double multiplier2 = matrixArr[0][1];
        double multiplier3 = matrixArr[0][2];

        double detA = multiplier1 * (matrixArr[1][1]*matrixArr[2][2] - matrixArr[2][1]*matrixArr[1][2]) 
            - multiplier2 * (matrixArr[1][0]*matrixArr[2][2] - matrixArr[2][0]*matrixArr[1][2]) 
            + multiplier3 * (matrixArr[1][0]*matrixArr[2][1] - matrixArr[2][0]*matrixArr[1][1]);

        denominator = detA;
        return detA;


    }else{
        cout << "Invalid Matrix Dimensions." << endl;
    }
}

double* matrix::operator|(matrix& rhs){
    if(this->rows != this->columns) cout << "Error: not a square matrix." << endl;
    if(rhs.columns != 1 || rows != rhs.rows) cout << "Error: Incorrect number of variables." << endl;


    if(this->rows == 2 && this->columns == 2){
        //Dx
        double numeratorX = *(rhs[0]) * matrixArr[1][1] - *(rhs[1]) * matrixArr[0][1];
        
        //Dy
        double numeratorY = *(rhs[1]) * matrixArr[0][0]  - *(rhs[0]) * matrixArr[1][0];

        
        linearDeterminants = new double[2];
        linearDeterminants[0] = numeratorX;
        linearDeterminants[1] = numeratorY;

    
        return linearDeterminants;
       


    }else if(this->rows == 3 && this->columns == 3){
        //Dx
        double numeratorX = *(rhs[0]) * (matrixArr[1][1] * matrixArr[2][2] - matrixArr[2][1] * matrixArr[1][2]) 
            - matrixArr[0][1] * (*(rhs[1])* matrixArr[2][2] - *(rhs[2]) * matrixArr[1][2]) 
            + matrixArr[0][2] * (*(rhs[1]) * matrixArr[2][1] - *(rhs[2]) * matrixArr[1][1]);


        //Dy
        double numeratorY = matrixArr[0][0] * (*(rhs[1]) * matrixArr[2][2] - *(rhs[2]) * matrixArr[1][2]) 
            - *(rhs[0]) * (matrixArr[1][0] * matrixArr[2][2] - matrixArr[2][0] * matrixArr[1][2]) 
            + matrixArr[0][2] * (matrixArr[1][0] * *(rhs[2]) - matrixArr[2][0] * *(rhs[1]));


        //Dz
        double numeratorZ = matrixArr[0][0] * (matrixArr[1][1] * *(rhs[2]) - matrixArr[2][1] * *(rhs[1])) 
            - matrixArr[0][1] * (matrixArr[1][0] * *(rhs[2]) - matrixArr[2][0] * *(rhs[1])) 
            + *(rhs[0]) * (matrixArr[1][0] * matrixArr[2][1] - matrixArr[2][0] * matrixArr[1][1]);

        linearDeterminants = new double[3];
        linearDeterminants[0] = numeratorX;
        linearDeterminants[1] = numeratorY;
        linearDeterminants[2] = numeratorZ;

        // cout << "linearDeterminants: " << endl;
        // for(int i = 0; i < 3; i++){
        //     cout << linearDeterminants[i] << endl;
        // }

        return linearDeterminants;


    }else{
        cout << "Invalid Matrix Dimensions." << endl;
    }

    return nullptr;
}


matrix matrix::operator|=(matrix &rhs){
    if(rhs.columns != 1) cout << "Error: Incorrect number of variables." << endl;

    double x = 0.0;
    double y = 0.0;
    double z = 0.0;


    if(this->rows == 2 && this->columns == 2){
        // Check if denominator is not zero before division

        if (denominator != 0) {
            x = linearDeterminants[0] / denominator;
            y = linearDeterminants[1] / denominator;
        } else {
            cout << "Error: Division by zero." << endl;
        }

        linearSolutions = new double[2];
        linearSolutions[0] = x;
        linearSolutions[1] = y;

        matrix matrix_res(2,1);
        matrix_res[0][0] = x;
        matrix_res[1][0] = y;


        return matrix_res;

        
    } else if(this->rows == 3 && this->columns == 3){

        if (denominator != 0) {
            x = linearDeterminants[0] / denominator;
            y = linearDeterminants[1] / denominator;
            z = linearDeterminants[2] / denominator;
        } else {
            cout << "Error: Division by zero." << endl;
        }

        linearSolutions = new double[3];
        linearSolutions[0] = x;
        linearSolutions[1] = y;
        linearSolutions[2] = z;

        matrix matrix_res(3,1);
        matrix_res[0][0] = x;
        matrix_res[1][0] = y;
        matrix_res[2][0] = z;

        return matrix_res;
    } else {
        cout << "Invalid Matrix Dimensions." << endl;
    }
}

