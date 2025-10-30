#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *right, *left, *up, *down;
    Node(int val) : data(val), right(nullptr), left(nullptr), up(nullptr), down(nullptr) {}
};

Node* convertMatrixToLinkedList(int mat[][3], int m, int n) {
    Node* head = nullptr;
    Node* rowStart[m];   // store start of each row

    for (int i = 0; i < m; i++) {
        Node* prev = nullptr;
        for (int j = 0; j < n; j++) {
            Node* curr = new Node(mat[i][j]);

            if (j == 0) rowStart[i] = curr;
            if (prev) { prev->right = curr; curr->left = prev; }

            if (i > 0) {
                Node* upper = rowStart[i - 1];
                for (int k = 0; k < j; k++) upper = upper->right;
                curr->up = upper;
                upper->down = curr;
            }

            prev = curr;
            if (i == 0 && j == 0) head = curr;
        }
    }
    return head;
}

void printLinkedList2D(Node* head) {
    Node* row = head;
    while (row) {
        Node* col = row;
        while (col) {
            cout << col->data << " ";
            col = col->right;
        }
        cout << endl;
        row = row->down;
    }
}

int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Node* head = convertMatrixToLinkedList(mat, 3, 3);
    cout << "Doubly Linked 2D List Representation:\n";
    printLinkedList2D(head);

    return 0;
}
