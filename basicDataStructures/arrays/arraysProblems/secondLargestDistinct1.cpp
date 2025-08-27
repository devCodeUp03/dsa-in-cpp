#include <iostream>
using namespace std;

int getSecondLargest(int *arr, int n);
int main()
{
    // int arr[] = {10, 10, 10};
    int arr[] = {28078, 19451, 935, 28892, 2242, 3570, 5480, 231};
    int secondLargest = getSecondLargest(arr, 8);
    cout << "SecondLargest: " << secondLargest << endl;
    return 0;
}

int getSecondLargest(int *arr, int n)
{
    int largest = arr[0], secondLargest = -1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
            secondLargest = arr[i];
    }
    return secondLargest;
}