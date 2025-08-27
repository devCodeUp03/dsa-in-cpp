// Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.
#include <iostream>
using namespace std;

int getSecondLargest(int *arr, int n);
void sortArray(int *arr, int n);
void printArray(int *arr, int n);
int main()
{
    // int arr[] = {12, 35, 1, 10, 34, 1};
    int arr[] = {10, 5, 10};
    int secondLargest = getSecondLargest(arr, 3);
    cout << "SecondLargest: " << secondLargest << endl;

    return 0;
}

int getSecondLargest(int *arr, int n)
{
    // code here

    sortArray(arr, n);
    printArray(arr, n);
    
    for(int i = n-2; i >= 0; i--) {
        if(arr[i] < arr[n-1]) {
            return arr[i];
        }
    }
    return -1;
}

void sortArray(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}

void printArray(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
}
