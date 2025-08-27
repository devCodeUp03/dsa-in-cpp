#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int thirdLargestElement(vector<int> &arr)
    {
        // code here
        if (arr.size() < 3)
        {
            return -1;
        }

        int largest = arr[0], secondLargest = 0, thirdLargestElement = -1;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > largest)
            {
                if (secondLargest != 0)
                {
                    thirdLargestElement = secondLargest;
                }
                secondLargest = largest;
                largest = arr[i];
            }
            else if (arr[i] > secondLargest)// in this case distinct is not necessary
            {
                if (secondLargest != 0)
                {
                    thirdLargestElement = secondLargest;
                }
                secondLargest = arr[i];
            }
            else if (arr[i] > thirdLargestElement)
            {
                thirdLargestElement = arr[i];
            }
        }
        return thirdLargestElement;
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

    // vector<int> arr = {2, 4, 1, 3, 5};
    // vector<int> arr = {5, 5};
    vector<int> arr = {855, 450, 132, 359, 233, 825, 604, 481, 262, 337, 720, 525, 652, 300, 906, 219, 926, 906, 293, 864, 817, 498, 30, 639, 661};
    Solution tle;
    // tle.sortVector(arr);
    // tle.printVector(arr);
    int thirdLargestElement = tle.thirdLargestElement(arr);
    cout << "Third Largest Element: " << thirdLargestElement << endl;

    return 0;
}