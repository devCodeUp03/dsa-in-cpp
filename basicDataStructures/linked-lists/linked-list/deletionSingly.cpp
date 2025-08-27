#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void traverseLinkedList(Node *head);

class LinkedList{
    public:
        void deleteAtTheMiddle(Node *head) {
            Node *temp = head, *temp2;
            while(temp != nullptr && temp->data != 15) {
                temp2 = temp;
                temp = temp->next;
            }

            if(temp == nullptr) return;

            temp2->next = temp->next;
            delete temp;
        }

};

int main()
{

    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->data = 5;
    head->next = second;

    second->data = 15;
    second->next = third;

    third->data = 25;
    third->next = NULL;

    // deletion at the beginning
    // Node *temp = head;
    // head = temp->next;
    // delete temp;

    // deletion at the end

    // Node *temp = head, *temp2;
    // while(temp->next != NULL) {
    //     temp2 =temp;
    //     temp = temp->next;
    // }

    // temp2->next = NULL;
    // delete temp;

    // deletion at the middle

    // Node *temp = head, *temp2;
    // while (temp!= nullptr && temp->data != 20)
    // {
    //     temp2 = temp;
    //     temp = temp->next;
    // }

    // temp2->next = temp->next;

    // if(temp == nullptr) return;

    // delete temp;
    LinkedList ll;
    ll.deleteAtTheMiddle(head);

    traverseLinkedList(head);

    return 0;

}

void traverseLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}