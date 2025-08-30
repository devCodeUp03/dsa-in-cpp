#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    bool push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (top == nullptr)
        {
            cout << "stack is empty!" << endl;
            return -1;
        }

        Node *temp = top;
        int pop = temp->data;
        top = top->next;
        delete temp;
        return pop;
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "stack is empty!" << endl;
            return -1;
        }

        return top->data;
    }

    bool isEmpty() {
        if(top == nullptr) return true;
        else return false;
    }
};

int main()
{

    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty();

    return 0;
}
