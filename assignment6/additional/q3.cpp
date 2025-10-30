#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

Node* reverseGroup(Node* head, int k) {
    if (!head || k <= 1) return head;

    Node* curr = head;
    Node* newHead = nullptr;
    Node* groupPrev = nullptr;

    while (curr) {
        Node* groupStart = curr;
        Node* prev = nullptr;
        int count = 0;

        while (curr && count < k) {
            Node* nxt = curr->next;
            curr->next = prev;
            curr->prev = nxt;
            prev = curr;
            curr = nxt;
            count++;
        }

        if (!newHead) newHead = prev;
        if (groupPrev) groupPrev->next = prev;
        groupStart->next = curr;
        if (curr) curr->prev = groupStart;
        groupPrev = groupStart;
    }

    return newHead;
}

void printList(Node* head) {
    for (Node* p = head; p; p = p->next) cout << p->data << " ";
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < n; i++) {
        tail->next = new Node(arr[i]);
        tail->next->prev = tail;
        tail = tail->next;
    }

    cout << "Original: ";
    printList(head);

    int k = 4;
    head = reverseGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);
    return 0;
}
