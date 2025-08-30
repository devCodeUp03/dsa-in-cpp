#include <iostream>
#include <string>
using namespace std;

#define MAX 10

class Stack
{
private:
    int top;
    char arr[MAX];

public:
    Stack()
    {
        top = -1;
    }

    void push(char val)
    {
        if (top == MAX - 1)
        {
            cout << "stack is full!" << endl;
            return;
        }

        arr[++top] = val;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "stack is empty!" << endl;
            return;
        }

        top--;
    }

    char peek()
    {
        if (top == -1)
        {
            cout << "stack is empty!" << endl;
            return -1;
        }

        return arr[top];
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool checkParenthesis(string s)
    {
        int i = 0;
        while (s[i] != '\0')
        {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                cout << "Pushed: " << s[i] << endl;

                push(s[i]);
            }
            else if (s[i] == ')' && arr[top] == '(' || s[i] == '}' && arr[top] == '{' || s[i] == ']' && arr[top] == '[')
            {

                cout << "Popped Out: " << s[i] << endl;
                pop();
            }
            else 
                break;
            // else if (s[i] == ']' || s[i] == '}' || s[i] == ')')
            //     push(s[i]);

            i++;
        }

        return isEmpty() && s[i] == '\0';
    }
};

int main()
{

    Stack st;
    string s = "[{()}]";
    bool valid = st.checkParenthesis(s);
    if (valid)
    {
        cout << "Valid Parenthesis!" << endl;
    }
    else
    {
        cout << "Invalid Parenthesis!!!" << endl;
    }
}