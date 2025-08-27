#include <iostream>
#include <vector>
#include <utility> //pair<type, type> p (1, "Hello");


using namespace std;

class Solution {
    public: 
        int maxConsecBits(vector<int> v) {

            pair<int, int> p (0, 0);
            int maximum = 0;

            for(int el: v) {
                if(el == 0) p.first++;
                if(el == 1) p.second++;

                maximum = max(maximum, max(p.first, p.second));

                if(el == 0) p.second = 0;
                if(el == 1) p.first = 0;
            }
            return maximum;
        }
};


int main() {
    // vector<int> v = {0, 0, 1, 0, 1, 0};
     vector<int> v = {0, 1, 0, 1, 1, 1, 1};
    Solution mcb;
    int maximum = mcb.maxConsecBits(v);
    cout<<"maximum: "<<maximum<<endl;

    return 0;
}