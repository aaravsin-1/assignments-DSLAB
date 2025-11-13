#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *left, *right;
    Node(int x)
    {
        val = x;
        left = right = NULL;
    }
};
class Tree
{
public:
    int sumLeft(Node *root, bool left = false)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right && left)
            return root->val;
        return sumLeft(root->left, true) + sumLeft(root->right, false);
    }
};
int main()
{
    Node *root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    Tree t;
    cout << t.sumLeft(root);
}

/*
Pesudo Code
Class Node:
    val, left, right

Class Tree:
    Function sumLeft(node, isLeft = false):
        If node is NULL:
            return 0
        If node.left is NULL and node.right is NULL and isLeft is true:
            return node.val
        return sumLeft(node.left, true) + sumLeft(node.right, false)

Main:
    create nodes and link as binary tree
    print Tree.sumLeft(root)
*/