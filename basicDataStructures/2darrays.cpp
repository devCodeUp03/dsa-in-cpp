#include <iostream>
using namespace std;


int main() {

    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }; //declaring and initializing 2d array

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout<<matrix[i][j]<<" "; //accessing element of 2d array
        }
        cout<<"\n";
    }


    return 0;
}