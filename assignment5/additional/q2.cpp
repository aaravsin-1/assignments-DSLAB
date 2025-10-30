#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x): data(x), next(NULL) {}
};

Node* reverseK(Node* head, int k) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;

    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL)
        head->next = reverseK(next, k);

    return prev;
}

int main() {
    Node* head = new Node(1);
    Node* temp = head;
    for (int i = 2; i <= 9; i++) {
        temp->next = new Node(i);
        temp = temp->next;
    }

    int k = 3;
    head = reverseK(head, k);

    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}
