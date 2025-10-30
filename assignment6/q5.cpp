#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int value)
        : data(value), next(nullptr) {}
};


bool isCircular(Node* head) {
    if (!head) return false;

    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        if (slow == fast)
            return true;  

        slow = slow->next;
        fast = fast->next->next;
    }

    return false;
}

int main() {
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    
    head->next->next->next = head;

    cout << (isCircular(head) ? "True" : "False") << "\n";

    // Note: Memory not freed here since list is circular (would loop forever if deleted naively)
    return 0;
}
