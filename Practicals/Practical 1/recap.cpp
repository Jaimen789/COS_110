#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int getRows(){
    ifstream infile("data.txt");
    string line;
    int numRows = 0;

    while(!infile.eof()){
        getline(infile, line);
        numRows++;
    }

    cout << numRows << endl;
    return numRows;
}

int main(){
    int rows = getRows();
    string line = "";
    string temp = "";
    string** array = new string*[rows];

    //intialize everything in array to nullptr
    for(int i = 0; i < rows ; i++){
        array[i] = nullptr;
    }


    ifstream infile("data.txt");
    if(infile.is_open()){
        int rowCount = 0;

        while(getline(infile, line))
            if(!line.empty()){
                istringstream ss(line);

                int colCount = 0;

                while(getline(ss, temp , ',')){
                    if(colCount == 0){
                        array[rowCount] = new string[rows];
                    }

                    array[rowCount][colCount] = temp;
                    colCount++;
                }

                rowCount++;
            }

    infile.close();

    for (int l = 0; l < rows; l++) {
            for (int m = 0; m < rows; m++) {
                cout << array[l][m] << " ";
            }
            cout << endl;
    }

    for (int i = 0; i < rows; i++) {
            delete[] array[i];
        }
        delete[] array;

    }else{
        cout << "error opening file." << endl;
    }

    return 0;
}