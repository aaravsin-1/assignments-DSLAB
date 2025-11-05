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
    Node* findMin(Node* x)
    {
        while (x->lchild != NULL)
            x = x->lchild;
        return x;
    }
    Node* TREE_DELETE(Node* x, int k)
    {
        if (x == NULL)
            return x;

        if (k < x->data)
            x->lchild = TREE_DELETE(x->lchild, k);

        else if (k > x->data)
            x->rchild = TREE_DELETE(x->rchild, k);

        else
        {
            // Case 1: no left child
            if (x->lchild == NULL)
            {
                Node* temp = x->rchild;
                delete x;
                return temp;
            }
            // Case 2: no right child
            else if (x->rchild == NULL)
            {
                Node* temp = x->lchild;
                delete x;
                return temp;
            }

            // Case 3: two children → replace with inorder successor
            Node* temp = findMin(x->rchild);
            x->data = temp->data;
            x->rchild = TREE_DELETE(x->rchild, temp->data);
        }
        return x;
    }

    void del(int val)
    {
        root = TREE_DELETE(root, val);
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
        BST.insert(ele[i]);

    // Example: delete a node
    BST.del(7);
}
