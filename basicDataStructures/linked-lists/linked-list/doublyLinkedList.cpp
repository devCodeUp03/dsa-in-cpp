#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DLL{
    public:
        void traverseForward(Node *head) {
            Node *temp = head;
            while(temp != nullptr) {
                cout<<temp->data<<" ";
                temp = temp ->next;
            }
        }

        void traverseBackward(Node *tail) {
            Node *temp = tail;
            while (temp != nullptr) {
                cout<<temp->data<<" ";
                temp = temp->prev;
            }
        }
};

int main()
{

    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *tail = new Node(40);

    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;
    third->next = tail;

    tail->prev = third;

    DLL dll;
    dll.traverseForward(head);
    cout<<endl;
    dll.traverseBackward(tail);





    return 0;
}