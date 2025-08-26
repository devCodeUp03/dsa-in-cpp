#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> arr)
    {
    
        int largest, secondLargest, thirdLargest;

        // finding the largest
        if (arr[0] > arr[1] && arr[0] > arr[2])
            largest = arr[0];
        else if (arr[1] > arr[0] && arr[1] > arr[2])
            largest = arr[1];
        else if (arr[2] > arr[0] && arr[2] > arr[1])
            largest = arr[2];

        // finding third largest
        if (arr[0] < arr[1] && arr[0] < arr[2])
            thirdLargest = arr[0];
        else if (arr[1] < arr[0] && arr[1] < arr[2])
            thirdLargest = arr[1];
        else if (arr[2] < arr[0] && arr[2] < arr[1])
            thirdLargest = arr[2];

        // finding the second largest

        if (arr[0] > arr[1] && arr[0] < arr[2] || arr[0] < arr[1] && arr[0] > arr[2])
            secondLargest = arr[0];
        else if (arr[1] > arr[0] && arr[1] < arr[2] || arr[1] < arr[0] && arr[1] > arr[2])
            secondLargest = arr[1];
        else if (arr[2] > arr[0] && arr[2] < arr[1] || arr[2] < arr[0] && arr[2] > arr[1])
            secondLargest = arr[2];

        for (int i = 3; i < arr.size(); i++)
        {
            if (arr[i] > largest)
            {
                thirdLargest = secondLargest;
                secondLargest = largest;
                largest = arr[i];
            }
            else if (arr[i] > secondLargest)
            {
                thirdLargest = secondLargest;
                secondLargest = arr[i];
            }
            else if (arr[i] > thirdLargest)
            {
                thirdLargest = arr[i];
            }
        }
        int smallest, secondSmallest;
        if (arr[0] > arr[1])
        {
            smallest = arr[1];
            secondSmallest = arr[0];
        } else {
            smallest = arr[0];
            secondSmallest = arr[1];
        }
        for (int i = 2; i < arr.size(); i++)
        {
            if (arr[i] < smallest)
            {
                secondSmallest = smallest;
                smallest = arr[i];
            }
            else if (arr[i] < secondSmallest)
            {
                secondSmallest = arr[i];
            }
        }

        int large1 = largest * secondLargest * thirdLargest;
        int large2 = largest * smallest * secondSmallest;

        if(large1 > large2) return large1;
        else return large2;
    }

    void sortVector(vector<int> &v)
    {
        for (int i = 0; i < v.size() - 1; i++)
        {
            for (int j = 0; j < v.size() - i - 1; j++)
            {
                if (v[j] > v[j + 1])
                {
                    int temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                }
            }
        }
    }

    void printVector(vector<int> &v)
    {
        for (int el : v)
        {
            cout << el << " ";
        }
    }
};

int main()
{
    // vector<int> v = {10, 3, 5, 6, 20};
    //-10, -3, -5, -6, -20
    // vector<int> v = {-10, -3, -5, -6, -20};
    // vector<int> v = {852, -566, 182, -638, -693, -323};
    // vector<int> v = {-55, 848, 625, -744, -604, 631, 794, 259, -310};
    // vector<int> v = {-406, 876, -26, 68};
    vector<int> v = {453, 453, -890, 219, 127, 852, -443, -527, -978, -238, 672, -877, -236, 909, -278, 811, 234, 668, -97};
    Solution mp;
    mp.sortVector(v);
    mp.printVector(v);

    int max = mp.maxProduct(v);
    cout << "maximum: " << max << endl;
    return 0;
}