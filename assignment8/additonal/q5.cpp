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
    Node *build(int pre[], int in[], int s, int e, int &idx)
    {
        if (s > e)
            return NULL;
        Node *r = new Node(pre[idx++]);
        int pos = find(in, s, e, r->val);
        r->left = build(pre, in, s, pos - 1, idx);
        r->right = build(pre, in, pos + 1, e, idx);
        return r;
    }
    void inorder(Node *r)
    {
        if (!r)
            return;
        inorder(r->left);
        cout << r->val << " ";
        inorder(r->right);
    }
};
int main()
{
    int pre[] = {3, 9, 20, 15, 7}, in[] = {9, 3, 15, 20, 7}, idx = 0;
    Tree t;
    Node *r = t.build(pre, in, 0, 4, idx);
    t.inorder(r);
}
