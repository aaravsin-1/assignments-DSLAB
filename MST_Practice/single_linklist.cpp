#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert new node at the beginning
void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node();   // allocate memory
    newNode->data = value;        // assign data
    newNode->next = head;         // link new node to old head
    head = newNode;               // update head
}

// Print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void search_list(Node *head, int num)
{
    if(head == NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }

    Node *temp = head;
    while(temp!=NULL && temp->data!=num)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        cout<<"element not found"<<endl;
    }
    else
    {
        cout<<"Element found"<<endl;
    }
}
int main() {
    Node* head = nullptr;  // start with empty list

    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        insertAtHead(head, val);
    }

    cout << "Linked List: ";
    printList(head);

    cout<<"Enter an element to search for:";
    int ele = 0;
    cin>>ele;
    search_list(head,ele);
    return 0;
}
