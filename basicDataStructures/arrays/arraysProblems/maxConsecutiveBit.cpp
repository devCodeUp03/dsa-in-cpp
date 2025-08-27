#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> v);


class Solution
{
public:
    int maxConsecBits(vector<int> &arr)
    {
        if (arr.size() == 1)
            return 1;

        int zeroes = 0, ones = 0;
        vector<int> v1, v2;

        for (int el : arr)
        {
            if (el == 0)
            {
                zeroes++;
                v2.push_back(ones);
                ones = 0;
            }
            else
            {
                ones++;
                v1.push_back(zeroes);
                zeroes = 0;
            }
        }

        if(ones != 0) v2.push_back(ones);
        if(zeroes != 0) v1.push_back(zeroes);

        int large1 = -1;
        int large2 = -1;
        for (int el : v1)
        {
            if (el > large1)
                large1 = el;
        }

        for (int el : v2)
        {
            if (el > large2)
                large2 = el;
        }

        return max(large1, large2);
    }
};

int main()
{

    // vector<int> v = {0, 1, 0, 1, 1, 1, 1};
    vector<int> v = {0, 0, 1, 0, 1, 0};
    Solution mcb;
    int maximum = mcb.maxConsecBits(v);
    cout << "Maximum: " << maximum << endl;
    return 0;
}

void printVector(vector<int> v) {
    for(int el: v) cout<<el<<" ";
}