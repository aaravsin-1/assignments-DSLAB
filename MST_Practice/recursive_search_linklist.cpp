#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Recursive search function
bool search_list(Node* head, int num) {
    if (head == nullptr) 
        return false;          // base case: end of list, not found
    if (head->data == num)    
        return true;           // base case: element found
    return search_list(head->next, num); // recursive call
}

// Example usage
int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};

    int key = 2;
    if (search_list(head, key))
        cout << "Element found\n";
    else
        cout << "Element not found\n";
    return 0;
}
