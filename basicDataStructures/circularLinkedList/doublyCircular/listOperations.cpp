#include <iostream>
using namespace std;


class Node {
    public:
        int data;
        Node *prev;
        Node *next;
        Node(int val) {
            data = val;
            prev = nullptr;
            next = nullptr;
        }
};


class DoublyCircularLinkedList{
    private:
        Node *head;
        Node *tail;
    
    public:
        DoublyCircularLinkedList(){
            head = nullptr;
            tail = nullptr;
        }

        void addAtEnd(int val) {
            Node *temp = head;
            Node *newNode = new Node(val);
            if(temp == nullptr) {
                head = tail = newNode;
                head->next = head->prev = newNode;
                tail->next = tail->prev = newNode;
                return;
            }

            do {
                temp = temp->next;
            } while(temp->next != head);

            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
            temp->next = newNode;
        }

        void traversalForward() {
            Node *temp = head;
            if(temp == nullptr) {
                cout<<"list is empty!"<<endl;
                return;
            }

            do{
                cout<<temp->data<<" ";
                temp = temp->next;
            } while(temp != head);
        }

        void deletion(int val) {
            Node *temp = head;
            if(temp == nullptr) {
                cout<<"list is empty!"<<endl;
                return;
            }

            Node *temp2;

            do {
                temp2 = temp;
                temp = temp->next;
            } while(temp != head && temp->data != val);

            if(temp == head) {
                cout<<"Element not found!"<<endl;      
                
                return;
            }

            Node *temp0 = temp->next;
            temp2->next = temp->next;
            temp0->prev = temp->prev;
            delete temp;          


        }
};


int main() {

    DoublyCircularLinkedList dcll;
    dcll.addAtEnd(10);
    dcll.addAtEnd(20);
    dcll.addAtEnd(30);
    dcll.deletion(30);

    dcll.traversalForward();



    return 0;
}