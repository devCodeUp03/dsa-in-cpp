#include <iostream>
#include <stack>

using namespace std;

int main() {

    string original = "Devashish";
    string reverse = "";
    stack<char> st;

    for(char ch: original) {
        st.push(ch);
    }

    while(!st.empty()) {
        reverse = reverse + st.top();
        st.pop();
    }

    cout<<reverse<<endl;

}