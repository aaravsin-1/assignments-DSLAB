#include <iostream>
using namespace std;


class CLLNode {
public:
    int data;
    CLLNode* next;

    CLLNode(int value)
        : data(value), next(this) {}  
};


int sizeCLL(CLLNode* head) {
    if (!head) return 0;

    int count = 0;
    CLLNode* node = head;
    do {
        ++count;
        node = node->next;
    } while (node != head);

    return count;
}

int main() {
    
    CLLNode* head = new CLLNode(5);
    CLLNode* second = new CLLNode(6);

    head->next = second;
    second->next = head;

    cout << "Size of CLL: " << sizeCLL(head) << "\n";

    
    delete second;
    delete head;

    return 0;
}
