#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int v)
    {
        data = v;
        left = 0;
        right = 0;
    }
};

bool checkBst(Node *root, int min, int max)
{
    if (!root)
        return true;
    if (root->data <= min || root->data >= max)
        return false;
    return checkBst(root->left, min, root->data) && checkBst(root->right, root->data, max);
}

bool isBST(Node *root)
{
    return checkBst(root, -2147483648, 2147483647);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    cout << isBST(root) << endl;
    return 0;
}
