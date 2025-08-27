#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
    public: 
        int maxProduct(vector<int> arr) {
            sort(arr.begin(), arr.end()); //using introsort combination of quick, heap and sometimes selection as per chatgpt
            int n = arr.size(); //greater<int>() to sort in descending order
            int max1 = arr[n - 1] * arr[n - 2] * arr[n - 3];
            int max2 = arr[n - 1] * arr[0] * arr[1];
            int maximum = max(max1, max2);
            return maximum;
        }
};



int main() {

        vector<int> v = {453, 453, -890, 219, 127, 852, -443, -527, -978, -238, 672, -877, -236, 909, -278, 811, 234, 668, -97};
        Solution mp;
        int  maximum = mp.maxProduct(v);
        cout<<"Maximum: "<<maximum<<endl;


    return 0;
}