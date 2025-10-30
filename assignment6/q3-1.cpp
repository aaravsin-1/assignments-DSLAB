#include <iostream>
using namespace std;


class DLLNode {
public:
    int data;
    DLLNode* prev;
    DLLNode* next;

    DLLNode(int value)
        : data(value), prev(nullptr), next(nullptr) {}
};


int sizeDLL(DLLNode* head) {
    int count = 0;
    for (DLLNode* node = head; node; node = node->next)
        ++count;
    return count;
}

int main() {
    
    DLLNode* head = new DLLNode(1);
    DLLNode* second = new DLLNode(2);

    head->next = second;
    second->prev = head;

    cout << "Size of DLL: " << sizeDLL(head) << "\n";

    
    delete second;
    delete head;

    return 0;
}
