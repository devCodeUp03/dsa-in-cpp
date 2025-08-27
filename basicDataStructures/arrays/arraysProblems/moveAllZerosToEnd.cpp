#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    void pushZerosToEnd(vector<int> &arr)
    {
        int lastNonZeroIndex = -1;//index
        // for (int el : arr)
        // {
        //     if (el != lastNonZero && el != 0)
        //         lastNonZero = el;
        // }
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != 0) lastNonZeroIndex = i;
        }        

        for (int i = 0; i < arr.size(); i++) //O(n^2)
        {
            
            if (i == lastNonZeroIndex)
                break;

            if (arr[i] == 0)
            {

                for (int j = i; j < arr.size(); j++)
                {
                    arr[j] = arr[j + 1];
                }
                arr[arr.size() - 1] = 0;
                lastNonZeroIndex--;
                i--; //need to backtrack after every series of shifts 
            }
        }
    }
};

int main()
{

    // vector<int> v = {1, 2, 0, 4, 3, 0, 5, 0};
    // // vector<int> v = {10, 20, 30};
    // vector<int> v = {3, 5, 0, 0, 4};
    vector<int> v= {4, 0, 4, 0, 4, 0};
    Solution pzte;
    pzte.pushZerosToEnd(v);
    for (auto el : v)
    {
        cout << el << " ";
    }

    return 0;
}