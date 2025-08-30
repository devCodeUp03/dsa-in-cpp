#include <iostream>
#include <stack>

using namespace std;


class Stack{
    private: 
        stack<char> c;
    public: 

        bool checkBalancedString(string s) {
            if(s.length() < 2) return false;
            for(char ch: s) {
                if(ch == '(' || ch == '{' || ch == '[') c.push(ch);
                else if(!c.empty() && (ch == ')' && c.top() == '(' || ch == '}' && c.top() == '{' || ch == ']' && c.top() == '[')) c.pop();
                else return false;
            }
            return c.empty();
        }
};


int main() {
    string s = ")([{()}]";

    Stack st;
    bool valid = st.checkBalancedString(s);
    cout<<valid<<endl;



}