#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};


void traverseLinkedList(Node *head);

int main() {

    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();


    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    //traversing through the linked-list
    // traverseLinkedList(head);

    //add node at the beginning
    // Node *newNode = new Node();
    // newNode->data = 0;
    // newNode->next = head;
    // head = newNode;

    // traverseLinkedList(head);

    //adding at the end
    Node *newNode = new Node();
    newNode->data = 25;
    newNode->next = NULL;
    cout<<"New node 0: "<<newNode<<endl;
    // Node *temp;

    // for(temp = head; temp -> next != NULL; temp = temp->next) {
    //     cout<<"Temp: "<<temp<<endl;
    // }

    // temp->next = newNode;    

    // Node *temp = head;
    // while(temp->next != NULL) {
    //     temp = temp->next;
    // }
    // temp->next = newNode;

    Node *temp = head, *temp2;

    while(temp->data != 30) {
        temp2 = temp;
        temp = temp->next;
    }


    Node *middleNode = new Node();

    middleNode->data = 25;
    middleNode->next = temp;
    temp2->next = middleNode;






    traverseLinkedList(head);


    return 0;
}

void traverseLinkedList(Node *head) {
     for(Node* temp = head; temp!=NULL; temp=temp->next) {
        cout<<temp->data<<" "<<temp->next<<endl;
    }
}