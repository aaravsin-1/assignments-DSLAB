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
