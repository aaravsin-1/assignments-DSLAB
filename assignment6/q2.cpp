#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int value)
        : data(value), next(this) {} 
};


void printWithHeadRepeat(Node* head) {
    if (!head) {
        cout << "\n";
        return;
    }

    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);

    cout << head->data << "\n"; 
}

int main() {
    int arr[] = {20, 100, 40, 80, 60};
    Node* head = nullptr;

    
    for (int x : arr) {
        Node* newNode = new Node(x);

        if (!head) {
            head = newNode;
        } else {
           
            Node* tail = head;
            while (tail->next != head)
                tail = tail->next;

            tail->next = newNode;
            newNode->next = head;
        }
    }

   
    printWithHeadRepeat(head);

    return 0;
}
