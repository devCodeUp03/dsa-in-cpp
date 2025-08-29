#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *prev;
        Node *next;

        Node(int val): data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList{
    private: 
        Node *head;
        Node *tail;
    
    public:

        DoublyLinkedList (){
            head = nullptr;
            tail = nullptr;
        }
        void addAtEnd(int val) {
            Node *temp = tail;
            Node *newNode = new Node(val);
            if(temp == nullptr) {
                head = tail = newNode;
                return;
            }

            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        void traverseForward() {
            Node *temp = head;
            if(temp == nullptr) {
                cout<<"list if empty!"<<endl;
                return;
            }

            while(temp != nullptr) {
                cout<<temp->data<<" ";
                temp = temp->next;
            }

        }

        void reverse() {
            Node *temp = nullptr;
            Node *curr = head;
            while(curr != nullptr) {
                temp = curr->prev;
                curr->prev = curr->next;
                curr->next = temp;
                curr = curr->prev;
            }

            if(temp != nullptr) {
                head = temp->prev;
            }
        }
};

int main() {
    DoublyLinkedList dll;
    dll.addAtEnd(10);
    dll.addAtEnd(15);
    dll.addAtEnd(20);
    dll.traverseForward();
    dll.reverse();
    cout<<endl;
    dll.traverseForward();

    return 0;
}