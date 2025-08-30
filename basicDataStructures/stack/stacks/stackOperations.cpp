#include <iostream>
using namespace std;

class Stack{
    private: 
        int top;
        int stack[10];
    public: 
        Stack() {
            top = -1;
        }

        void push(int val) {
            if(top == 9) {
                cout<<"Stack is full!";
                return;
            }

            top++;
            stack[top] = val;
        }

        void pop() {
            if(top == -1) {
                cout<<"stack is empty!";
                return;
            }
            top--;
        }

        int peek() {
            if(top == -1) {
                cout<<"stack is empty!";
                return -1;
            }

            return stack[top];
        }

        bool isEmpty() {
            if(top == -1) return true;
            else return false; 
        }

        void traverse() {
            for(int i  = 0; i <=top ; i++) {
                cout<<stack[i]<<" ";
            }
        }
};


int main() {

    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.pop();
    s.push(20);
    cout<<s.peek()<<endl;

    s.traverse();



    return 0;
}