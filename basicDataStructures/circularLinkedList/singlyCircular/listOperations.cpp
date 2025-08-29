#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class SinglyCircularLinkedList
{
private:
    Node *head;

public:
    SinglyCircularLinkedList(){
        head = nullptr;
    }
    void addAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    void addAtTheBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    void traversal()
    {
        Node *temp = head;
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }

    void deletion(int val) {
        Node *temp = head;
        if(temp == nullptr) {
            cout<<"list is empty!"<<endl;
            return;
        }

        Node *temp2;
        do{
            temp2= temp;
            temp = temp->next;
        } while(temp != head && temp->data != val);

        if(temp == head) {
            cout<<"Element not found!"<<endl;
            return;
        }

        temp2->next = temp->next;
        delete temp;
    }
};

int main()
{
    SinglyCircularLinkedList scll;
    scll.addAtEnd(10);
    scll.addAtEnd(20);
    scll.addAtEnd(30);
    scll.addAtTheBeginning(0);

    scll.deletion(30);

    scll.traversal();
    return 0;
}