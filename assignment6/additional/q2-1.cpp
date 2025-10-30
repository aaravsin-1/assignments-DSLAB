#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int x): data(x), prev(nullptr), next(nullptr) {}
};

void removeEven(DNode*& head) {
    DNode* curr = head;
    while (curr) {
        if (curr->data % 2 == 0) {
            if (curr->prev) curr->prev->next = curr->next;
            else head = curr->next;
            if (curr->next) curr->next->prev = curr->prev;
            DNode* temp = curr;
            curr = curr->next;
            delete temp;
        } else curr = curr->next;
    }
}

void printDLL(DNode* head) {
    for (DNode* p = head; p; p = p->next) cout << p->data << " ";
    cout << endl;
}

int main() {
    int arr[] = {2, 5, 8, 7, 10, 3};
    DNode* head = new DNode(arr[0]);
    DNode* tail = head;
    for (int i = 1; i < 6; i++) {
        tail->next = new DNode(arr[i]);
        tail->next->prev = tail;
        tail = tail->next;
    }

    cout << "Before: "; printDLL(head);
    removeEven(head);
    cout << "After:  "; printDLL(head);
    return 0;
}
