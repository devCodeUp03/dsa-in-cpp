#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int arr[5] = {1, 2, 3, 4, 5}; // declaring and initializing 1D array
    // cout<<arr[4]; //accessing 1D array
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n, greater<int>());
    for (int el : arr)
    {
        cout << el << " ";
    }
}