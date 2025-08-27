#include <iostream>
#include <vector>
#include <algorithm> //for remove
using namespace std;


class Solution {
    public:
        void pushZerosToEnd(vector<int> &arr) {
            int originalSizeOfArray = arr.size();
            int count = 0;


            for(int i = 0; i < arr.size(); i++) {
                if(arr[i] == 0) count++;
            }

            // arr.erase(remove(arr.begin(), arr.end(), 0), arr.end());
            for(int i = 0; i < arr.size(); i++) {
                if(arr[i] == 0) arr.erase(arr.begin() + i);
            } // quadratic time compexity
            for(int i = 0; i < arr.size(); i++) {

            }
            int sizeAfterRemove = arr.size();

            for(int i = sizeAfterRemove; i < originalSizeOfArray; i++) {
                arr.push_back(0);
            }
        }
};


int main() {
    // vector<int> v = {4, 0, 4, 0, 4, 0};
    vector<int> v = {1, 2, 0, 4, 3, 0, 5, 0};
    Solution pzte;
    pzte.pushZerosToEnd(v);
    for(auto el: v) cout<<el<<" ";
    return 0;
}