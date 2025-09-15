//Write a program to reverse a linked list.
// Input: 1->2->3->4->NULL
// Output: 4->3->2->1->NULL

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert_end(int val) {
        Node* n = new Node(val);
        if (head == nullptr) {
            head = n;
            return;
        }
        Node* t = head;
        while (t->next != nullptr) {
            t = t->next;
        }
        t->next = n;
    }

    void display() {
        Node* t = head;
        while (t != nullptr) {
            cout << t->data;
            if (t->next != nullptr) cout << " -> ";
            t = t->next;
        }
        cout << " -> NULL" << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;   // store next
            curr->next = prev;   // reverse current node
            prev = curr;         // move prev forward
            curr = next;         // move curr forward
        }
        head = prev;  // new head
    }
};

int main() {
    LinkedList myList;

    // Input: 1->2->3->4->NULL
    myList.insert_end(1);
    myList.insert_end(2);
    myList.insert_end(3);
    myList.insert_end(4);

    cout << "Original List: ";
    myList.display();

    myList.reverse();

    cout << "Reversed List: ";
    myList.display();

    return 0;
}

