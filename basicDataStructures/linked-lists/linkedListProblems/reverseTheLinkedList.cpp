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

    void traverseForward()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    Node *reverse()
    {
        Node *prev = nullptr;
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void traverseWithNewHead(Node *&newHead)
    {
        if (newHead == nullptr)
        {
            cout << "Empty list!";
            return;
        }

        Node *temp = newHead;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{

    SinglyLinkedList sll;
    sll.addAtEnd(10);
    sll.addAtEnd(20);
    sll.addAtEnd(30);
    sll.addAtEnd(40);
    Node *newHead = sll.reverse();

    // sll.traverseForward();
    sll.traverseWithNewHead(newHead);
}