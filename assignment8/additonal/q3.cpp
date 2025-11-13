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
    int depth(Node *r)
    {
        if (!r)
            return 0;
        int l = depth(r->left), rr = depth(r->right);
        return 1 + (l > rr ? l : rr);
    }
};
int main()
{
    Node *r = new Node(1);
    r->left = new Node(2);
    r->left->left = new Node(4);
    r->right = new Node(3);
    Tree t;
    cout << t.depth(r);
}
/*
Pseudo Code
Class Node:
    val, left, right

Class Tree:
    Function depth(node):
        If node is NULL:
            return 0
        leftDepth = depth(node.left)
        rightDepth = depth(node.right)
        return 1 + max(leftDepth, rightDepth)

Main:
    build a binary tree
    print Tree.depth(root)



*/