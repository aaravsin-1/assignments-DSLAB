#include <iostream>
using namespace std;

struct Node {
    int coeff, power;
    Node* next;
    Node(int c, int p): coeff(c), power(p), next(NULL) {}
};

Node* addPolynomials(Node* p1, Node* p2) {
    Node* res = new Node(0, 0);
    Node* temp = res;

    while (p1 && p2) {
        if (p1->power == p2->power) {
            temp->next = new Node(p1->coeff + p2->coeff, p1->power);
            p1 = p1->next; p2 = p2->next;
        } else if (p1->power > p2->power) {
            temp->next = new Node(p1->coeff, p1->power);
            p1 = p1->next;
        } else {
            temp->next = new Node(p2->coeff, p2->power);
            p2 = p2->next;
        }
        temp = temp->next;
    }

    while (p1) { temp->next = new Node(p1->coeff, p1->power); temp = temp->next; p1 = p1->next; }
    while (p2) { temp->next = new Node(p2->coeff, p2->power); temp = temp->next; p2 = p2->next; }

    return res->next;
}

int main() {
    Node* poly1 = new Node(5, 2);
    poly1->next = new Node(4, 1);
    poly1->next->next = new Node(2, 0);

    Node* poly2 = new Node(5, 1);
    poly2->next = new Node(5, 0);

    Node* res = addPolynomials(poly1, poly2);
    while (res) {
        cout << "[" << res->coeff << ", " << res->power << "] ";
        res = res->next;
    }
}
