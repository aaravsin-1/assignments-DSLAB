#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x): data(x), next(nullptr) {}
};

void removeEven(Node*& head) {
    if (!head) return;

    Node* curr = head;
    Node* prev = nullptr;

    while (true) {
        if (curr->data % 2 == 0) {
            if (curr == head) {
                Node* tail = head;
                while (tail->next != head) tail = tail->next;
                if (head->next == head) {
                    delete head;
                    head = nullptr;
                    return;
                }
                tail->next = head->next;
                Node* temp = head;
                head = head->next;
                delete temp;
                curr = head;
                continue;
            } else {
                prev->next = curr->next;
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
        if (curr == head) break;
    }
}

void printCLL(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    int arr[] = {2, 5, 8, 7, 10, 3};
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < 6; i++) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    tail->next = head;

    cout << "Before: "; printCLL(head);
    removeEven(head);
    cout << "After:  "; printCLL(head);
    return 0;
}
