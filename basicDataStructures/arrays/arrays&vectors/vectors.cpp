#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(const vector<int> &v);

int main()
{

    // vector<int> v = {-10, 0};
    // v.push_back(10);
    // v.push_back(20);//adding element at the end
    // v.push_back(30);
    // v.insert(v.begin() + 2, 5);
    // cout<<v.size()<<endl;
    // for(auto it = v.begin(); it != v.end(); it++) {
    //     cout<<*it<<" ";
    // }

    // vector<int> v(5, 11);
    // v.push_back(20);
    // printVector(v);
    // cout<<"Hello, World"<<endl;

    vector<int> v = {8, 9, 2, 1, 5, 4};
    sort(v.begin(), v.end(), greater<int>());
    printVector(v);
}

void printVector(const vector<int> &v)
{
    for (int el : v)
        cout << el << " ";
    cout << "\n";
}