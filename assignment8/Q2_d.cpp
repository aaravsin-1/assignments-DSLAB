#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
    Node(int value)
    {
        data = value;
        lchild = NULL;
        rchild = NULL;
    }
};
class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
    int Min(Node *t)
    {
        if (t == NULL)
        {
            cout << "empty tree" << endl;
            return -1;
        }
        if (t->lchild != NULL)
        {
            return Min(t->lchild);
        }
        else
            return t->data;
    }
    void successor(int val)
    {
        Node *y = NULL;
        Node *t = root;
        while (t != NULL)
        {
            if (t->data < val)
            {
                t = t->rchild;
            }
            else if (t->data > val)
            {
                y = t;
                t = t->lchild;
            }
            else
            {
                if (t->rchild != NULL)
                {
                    cout << "successor is:" << Min(t->rchild) << endl;
                    return;
                }
                break;//successor is y
            }
        }
        if (y != NULL)
            cout << "Successor is: " << y->data << endl;
        else
            cout << "No successor" << endl;
    }
    void insert(int val)
    {
        Node *n = new Node(val);
        if (root == NULL)
        {
            root = n;
            return;
        }
        Node *t = root;
        while (t != NULL)
        {
            if (t->data > val)
            {
                if (t->lchild != NULL)
                {
                    t = t->lchild;
                }
                else
                {
                    t->lchild = n;
                    return;
                }
            }
            else if (t->data < val)
            {
                if (t->rchild != NULL)
                {
                    t = t->rchild;
                }
                else
                {
                    t->rchild = n;
                    return;
                }
            }
            else
            {
                delete n;
                return;
            }
        }
    }
};
int main()
{
    int ele[] = {12, 100, 2, 3, 4, 5, 7, 8, 9, 10, 11, 22, 34};
    Tree BST;
    for (int i = 0; i < sizeof(ele) / sizeof(ele[0]); i++)
    {
        BST.insert(ele[i]);
    }
    BST.successor(100);
}
