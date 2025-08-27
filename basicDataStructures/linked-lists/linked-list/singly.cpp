#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    // traversal
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;

    // insertion at the end
    {
        Node *fourth = new Node();
        fourth->data = 40;
        fourth->next = NULL;

        Node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
        }

        temp = fourth;

        Node *temp2 = head;
        while (temp2 != NULL)
        {
            cout << temp2->data << " ";
            temp2 = temp2->next;
        }
    }

    return 0;
}