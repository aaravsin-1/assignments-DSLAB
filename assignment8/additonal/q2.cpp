#include <iostream>
#include <vector>
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
class BST
{
public:
    vector<Node *> build(int l, int r)
    {
        vector<Node *> res;
        if (l > r)
        {
            res.push_back(NULL);
            return res;
        }
        for (int i = l; i <= r; i++)
        {
            auto L = build(l, i - 1), R = build(i + 1, r);
            for (auto a : L)
                for (auto b : R)
                {
                    Node *root = new Node(i);
                    root->left = a;
                    root->right = b;
                    res.push_back(root);
                }
        }
        return res;
    }
};
int main()
{
    BST b;
    auto v = b.build(1, 3);
    cout << v.size();
}
/*
Pseudo Code
Class Node:
    val, left, right

Class BST:
    Function build(l, r):
        If l > r:
            return [NULL]
        result = empty list
        For i = l to r:
            leftTrees = build(l, i - 1)
            rightTrees = build(i + 1, r)
            For each L in leftTrees:
                For each R in rightTrees:
                    root = new Node(i)
                    root.left = L
                    root.right = R
                    add root to result
        return result

Main:
    read n
    trees = BST.build(1, n)
    print number of trees





*/