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

    void preorder(Node *t) // P, L, R
    {
        if (t == NULL)
            return;

        cout << t->data << " ";
        preorder(t->lchild);
        preorder(t->rchild);
    }
    void inorder(Node *t) // L, P, R
    {
        if (t == NULL)
            return;

        inorder(t->lchild);
        cout << t->data << " ";
        inorder(t->rchild);
    }
    void postorder(Node *t) // L, R, P
    {
        if (t == NULL)
            return;

        postorder(t->lchild);
        postorder(t->rchild);
        cout << t->data << " ";
    }
    void insert(int v)
    {
        Node *n = new Node(v);
        if (root == NULL)
        {
            root = n;
            return;
        }

        Node *t = root;
        Node *parent = NULL;

        while (t != NULL)
        {
            parent = t;
            if (v < t->data)
                t = t->lchild;
            else if (v > t->data)
                t = t->rchild;
            else
            {
                cout << "Cannot insert duplicate value: " << v << endl;
                delete n;
                return;
            }
        }

        if (v < parent->data)
            parent->lchild = n;
        else
            parent->rchild = n;
    }
    void rec_search(Node *t, int v)
    {
        if (t == NULL)
        {
            cout << "Element doesn't exist" << endl;
            return;
        }
        if (v < t->data)
        {
            rec_search(t->lchild, v);
        }
        else if (v > t->data)
        {
            rec_search(t->rchild, v);
        }
        else
        {
            cout << "Element exists" << endl;
            return;
        }
    }
    int Max(Node *t)
    {
        if (t->rchild != NULL)
        {
            Max(t->rchild);
        }
        else
            return t->data;
    }

    int Min(Node *t)
    {
        if (t->lchild != NULL)
        {
            Min(t->lchild);
        }
        else
            return t->data;
    }

    int SUCC(Node *t, int v)
    {
        while (t != NULL)
        {
            if (t->data < v)
            {
                t = t->rchild;
            }
            else if (t->data > v)
            {
                t = t->lchild;
            }
        } // takes me to the node i want, now we need the next node.
        if (t->rchild != NULL)
        {
            cout << t->rchild->data << endl;
        }
        else
        {
        }
    }
    void inorder_succ(Node *t, int v, int &flag)
    {
        if (t == NULL)
            return;

        inorder_succ(t->lchild, v, flag);

        if (flag == 1)
        {
            cout << "Inorder successor of " << v << " is: " << t->data << endl;
            flag = 2; // To stop further printing
            return;
        }

        if (t->data == v)
        {
            flag = 1; // Next node visited will be successor
        }

        inorder_succ(t->rchild, v, flag);
    }
};

int main()
{
    int ele[] = {12, 100, 2, 3, 4, 5, 7, 8, 9, 10, 11, 22, 34};
    Tree BST;
    for (int i = 0; i < sizeof(ele) / 4; i++)
    {
        BST.insert(ele[i]);
    }
    cout << "Preorder traversal: ";
    BST.preorder(BST.root);
    cout << endl;
    BST.inorder(BST.root);
    cout << endl;
    BST.postorder(BST.root);
    cout << endl;
    BST.rec_search(BST.root, 12);
    cout << endl;
    int x = BST.Max(BST.root);
    cout << x << endl;
    x = BST.Min(BST.root);
    cout << x << endl;
    int flag = 0;
    BST.inorder_succ(BST.root, 34, flag);
    return 0;
}
