#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
public:
    void insertionAtEnd(Node *&tail);

    void insertionAtBegin(Node *&head);

    void insertionAtKthPosition(Node *&head, int k, int value);

    void insertAfterGivenValue(Node *&head, Node *&tail, int value);

    void insertBeforeGivenValue(Node *&head, Node *&tail, int value);

    void traverseForward(Node *head);

    void traverseBackward(Node *tail);

    int findLengthOfList(Node *&head);

    void insertAtTheMiddle(Node *&head, int value);
};

void DoublyLinkedList::insertBeforeGivenValue(Node *&head, Node *&tail, int value)
{

    Node *temp = head, *temp2;

    if (temp == nullptr)
        return;

    if (temp->data == value)
    {
        Node *newNode = new Node(-10);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    while (temp != nullptr && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Value: " << value << " not found!" << endl;
        return;
    }

    Node *newNode = new Node(15);
    temp2 = temp->prev;
    temp2->next = newNode;
    newNode->prev = temp2;
    newNode->next = temp;
    temp->prev = newNode;
}

void DoublyLinkedList::insertAfterGivenValue(Node *&head, Node *&tail, int value)
{
    Node *temp = head, *temp2;
    if (temp == nullptr)
        return;

    while (temp != nullptr && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Value: " << value << " not found!" << endl;
        return;
    }

    Node *newNode = new Node(45);

    // inserting at the end
    if (temp->next == nullptr)
    {
        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;
    }
    else
    {
        temp2 = temp->next; // by the way I can create temp2 only when necessary too
        newNode->next = temp2;
        newNode->prev = temp;
        temp->next = newNode;
        temp2->prev = newNode;
    }
}

void DoublyLinkedList::insertionAtEnd(Node *&tail)
{
    Node *newNode = new Node(50);
    newNode->prev = tail;
    if (tail != nullptr) // to avoid segmentation fault
    {
        tail->next = newNode;
    }
    tail = newNode;
}

void DoublyLinkedList::insertionAtBegin(Node *&head)
{
    Node *newNode = new Node(0);
    newNode->next = head;
    if (head != nullptr)
    {
        head->prev = newNode;
    }
    head = newNode;
}

void DoublyLinkedList::insertionAtKthPosition(Node *&head, int k, int value)
{
    cout<<"hello"<<endl;
    Node *temp = head, *temp2;
    int i = 1;
    while (i < k)
    {
        temp2 = temp;
        temp = temp->next;
        i++;
    }

    Node *newNode = new Node(value);
    newNode->next = temp;
    newNode->prev = temp2;
    temp2->next = newNode;
    temp->prev = newNode;
    cout<<"Hello from last!"<<endl;
}

void DoublyLinkedList::traverseForward(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void DoublyLinkedList::traverseBackward(Node *tail)
{
    Node *temp = tail;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

int DoublyLinkedList::findLengthOfList(Node *&head)
{
    int count = 0;
    Node *temp = head;
    if (temp == nullptr)
        return count;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void DoublyLinkedList::insertAtTheMiddle(Node *&head, int value)
{

    Node *temp = head;
    if (temp == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    int length = findLengthOfList(head);
    cout<<"Length is: "<<length<<endl;

    int halfLength = length / 2;
    cout<<"Half Length is: "<<halfLength<<endl;
    insertionAtKthPosition(head, halfLength + 1, value);
}

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

    DoublyLinkedList dll;
    dll.insertionAtEnd(tail);

    dll.insertionAtBegin(head);
    dll.insertionAtKthPosition(head, 5, 35);
    dll.insertAfterGivenValue(head, tail, 40);
    dll.insertBeforeGivenValue(head, tail, 20);
    dll.insertAtTheMiddle(head, 100);

    // dll.traverseBackward(tail);
    // cout << endl;
    dll.traverseForward(head);
    // int length = dll.findLengthOfList(head);
    // cout<<endl;
    // cout<<"The length of the list is: "<<length;

    return 0;
}