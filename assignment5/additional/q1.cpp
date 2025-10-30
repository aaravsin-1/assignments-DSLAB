#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

Node* getIntersectionNode(Node* headA, Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    int diff = abs(lenA - lenB);

    if (lenA > lenB) while (diff--) headA = headA->next;
    else while (diff--) headB = headB->next;

    while (headA && headB) {
        if (headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

int main() {
    // Example: manually create intersection
    Node* newNode = new Node(8);
    newNode->next = new Node(5);

    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = newNode;

    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);
    headB->next->next->next = newNode;

    Node* intersection = getIntersectionNode(headA, headB);
    if (intersection)
        cout << "Intersected at " << intersection->data;
    else
        cout << "No intersection";
}
