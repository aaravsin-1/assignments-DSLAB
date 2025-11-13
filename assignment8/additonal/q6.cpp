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
    int find(int in[], int s, int e, int val)
    {
        for (int i = s; i <= e; i++)
            if (in[i] == val)
                return i;
        return -1;
    }
    Node *build(int in[], int post[], int s, int e, int &idx)
    {
        if (s > e)
            return NULL;
        Node *r = new Node(post[idx--]);
        int pos = find(in, s, e, r->val);
        r->right = build(in, post, pos + 1, e, idx);
        r->left = build(in, post, s, pos - 1, idx);
        return r;
    }
    void preorder(Node *r)
    {
        if (!r)
            return;
        cout << r->val << " ";
        preorder(r->left);
        preorder(r->right);
    }
};
int main()
{
    int in[] = {9, 3, 15, 20, 7}, post[] = {9, 15, 7, 20, 3}, idx = 4;
    Tree t;
    Node *r = t.build(in, post, 0, 4, idx);
    t.preorder(r);
}
/*
Pseuod Code
Class Node:
    val, left, right

Class Tree:
    Function find(in[], start, end, value):
        For i = start to end:
            If in[i] == value:
                return i
        return -1

    Function build(in[], post[], start, end, indexRef):
        If start > end:
            return NULL
        root = new Node(post[indexRef])
        indexRef = indexRef - 1
        pos = find(in, start, end, root.val)
        root.right = build(in, post, pos + 1, end, indexRef)
        root.left = build(in, post, start, pos - 1, indexRef)
        return root

    Function preorder(node):
        If node is NULL:
            return
        print node.val
        preorder(node.left)
        preorder(node.right)

Main:
    define inorder and postorder arrays
    index = n - 1
    root = Tree.build(in, post, 0, n-1, index)
    Tree.preorder(root)

*/