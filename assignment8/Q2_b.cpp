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
    int Max(Node *t)
    {
        if(t==NULL)
        {
            cout<<"empty tree"<<endl;
            return -1;
        }
        if (t->rchild != NULL)
        {
            return Max(t->rchild);
        }
        else
            return t->data;
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
    int x = BST.Max(BST.root);
    cout << x << endl;
}
