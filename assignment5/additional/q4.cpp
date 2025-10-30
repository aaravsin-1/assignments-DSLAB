#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x): data(x), next(NULL) {}
};

Node* rotateLeft(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    Node* tail = head;
    int len = 1;
    while (tail->next) {
        tail = tail->next;
        len++;
    }

    k = k % len;
    if (k == 0) return head;

    tail->next = head; // make circular
    for (int i = 0; i < k; i++) tail = tail->next;
    head = tail->next;
    tail->next = NULL;
    return head;
}

int main() {
    Node* head = new Node(1);
    Node* temp = head;
    for (int i = 2; i <= 6; i++) {
        temp->next = new Node(i);
        temp = temp->next;
    }

    head = rotateLeft(head, 2);
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}
