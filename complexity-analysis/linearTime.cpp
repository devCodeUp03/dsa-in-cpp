#include <iostream>
using namespace std;


int main() {
    int elementToBeFound = 4;
    int arr[] = {1, 2, 3, 4, 5};
    
    for(int i = 0; i < 5; i++) {
        if(arr[i] == elementToBeFound) 
            cout<<"Element has been found in "<<i<<" index."; // linear search (loop) -> O(n)     
    }



    return 0;
}