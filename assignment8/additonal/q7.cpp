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
class BST
{
public:
    void inorder(Node *r, Node *&h, Node *&p)
    {
        if (!r)
            return;
        inorder(r->left, h, p);
        if (!h)
            h = r;
        else
        {
            p->right = r;
            r->left = p;
        }
        p = r;
        inorder(r->right, h, p);
    }
    Node *merge(Node *a, Node *b)
    {
        Node *h1 = NULL, *p1 = NULL, *h2 = NULL, *p2 = NULL;
        inorder(a, h1, p1);
        p1->right = NULL;
        inorder(b, h2, p2);
        p2->right = NULL;
        Node *h = NULL, *t = NULL;
        while (h1 && h2)
        {
            Node *x;
            if (h1->val < h2->val)
            {
                x = h1;
                h1 = h1->right;
            }
            else
            {
                x = h2;
                h2 = h2->right;
            }
            if (!h)
                h = x;
            else
            {
                t->right = x;
                x->left = t;
            }
            t = x;
        }
        while (h1)
        {
            t->right = h1;
            h1->left = t;
            t = h1;
            h1 = h1->right;
        }
        while (h2)
        {
            t->right = h2;
            h2->left = t;
            t = h2;
            h2 = h2->right;
        }
        return h;
    }
};
int main()
{
    Node *a = new Node(20);
    a->left = new Node(10);
    a->right = new Node(30);
    a->left->left = new Node(25);
    a->right->left = new Node(50);
    a->right->right = new Node(100);
    Node *b = new Node(5);
    b->right = new Node(70);
    BST bst;
    Node *h = bst.merge(a, b);
    while (h)
    {
        cout << h->val << " ";
        h = h->right;
    }
}
