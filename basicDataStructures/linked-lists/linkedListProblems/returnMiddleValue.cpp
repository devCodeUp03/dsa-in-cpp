#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }

    void addAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void traverse()
    {
        Node *temp = head;
        if (temp == nullptr)
        {
            cout << "list is empty!" << endl;
            return;
        }

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    int returnMiddleValue()
    {
        if (head == nullptr)
        {
            cout << "list is empty!" << endl;
            return 0;
        }

        Node *temp = head;
        if (temp->next == nullptr)
            return temp->data;

        int count = 0;
        temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        int middle = (count / 2) + 1;

        int i = 1;
        temp = head;
        while (i < middle)
        {
            temp = temp->next;
            i++;
        }

        return temp->data;
    }
};

int main()
{
    SinglyLinkedList sll;
    sll.addAtEnd(10);
    sll.addAtEnd(20);
    sll.addAtEnd(30);
    sll.addAtEnd(40);

    int count = sll.returnMiddleValue();
    cout << count << endl;
    sll.traverse();
}