#include <iostream>
using namespace std;

class Node {
    public: 
     int data;
     Node *prev;
     Node *next;

     Node(int val): data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    private:
        Node *head;
        Node *tail;
    public:
        DoublyLinkedList(){
            head = nullptr;
            tail = nullptr;
        }

        void insertAtEnd(int val) {
            Node *newNode = new Node(val);
            if(head == nullptr) {
                head = tail = newNode;
            }

            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        void traverseForward() {
            Node *temp = head;
            if(temp == nullptr) {
                cout<<"list is empty!"<<endl;
                return;
            }

            while(temp != nullptr) {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }

        void deleteAtEnd() {
            //list is empty
            if(tail == nullptr) {
                cout<<"List is empty, can't delete!"<<endl;
                return;
            }

            Node *temp = tail;

            //only one node 
            if(head == tail) { //instead of temp->prev == nullptr
                head = tail = nullptr;
                delete temp;
                return;
            }

            //for multiple nodes
            tail = tail -> prev;
            tail->next = nullptr;
            delete temp;
        }

};


int main() {

    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.deleteAtEnd();
    dll.deleteAtEnd();
    dll.deleteAtEnd();
    // dll.deleteAtEnd();
    dll.traverseForward();

 

    return 0;
}