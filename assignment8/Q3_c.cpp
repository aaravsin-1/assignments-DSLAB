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

int maxDepth(Node *root)
{
    if (!root)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + (left > right ? left : right);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    cout << maxDepth(root) << endl;
    return 0;
}
