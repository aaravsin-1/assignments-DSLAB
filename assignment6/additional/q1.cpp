#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

void splitCircularList(Node* head, Node** head1_ref, Node** head2_ref) {
    if (!head || head->next == head) {
        *head1_ref = head;
        *head2_ref = nullptr;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // Move fast by two and slow by one until fast reaches or crosses head
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // For odd number of nodes, move fast one more step
    if (fast->next->next == head)
        fast = fast->next;

    // Set the heads of the two halves
    *head1_ref = head;
    *head2_ref = slow->next;

    // Make the first half circular
    slow->next = *head1_ref;

    // Make the second half circular
    fast->next = *head2_ref;
}

void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    // Create a circular linked list: 1 -> 2 -> 3 -> 4 -> 5 -> (back to 1)
    int arr[] = {1, 2, 3, 4, 5};
    Node* head = new Node(arr[0]);
    Node* tail = head;

    for (int i = 1; i < 5; i++) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    tail->next = head;

    Node* head1 = nullptr;
    Node* head2 = nullptr;

    splitCircularList(head, &head1, &head2);

    cout << "First Circular List: ";
    printList(head1);

    cout << "Second Circular List: ";
    printList(head2);

    return 0;
}
