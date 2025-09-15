#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// LinkedList class
class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at end
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
        cout << endl;
    }

    void findMiddle() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast->next != nullptr && fast->next != nullptr) {
            slow = slow->next;        
            fast = fast->next->next;   
        }

        cout << "Middle element: " << slow->data << endl;
    }
};

int main() {
    LinkedList myList;

    myList.insert_end(1);
    myList.insert_end(2);
    myList.insert_end(3);
    myList.insert_end(4);
    myList.insert_end(5);

    cout << "Linked List: ";
    myList.display();

    myList.findMiddle();

    return 0;
}
