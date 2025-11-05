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
    bool r_search(Node *t, int val)
    {
        if (t == NULL)
            return false;

        if (t->data == val)
            return true;

        if (val < t->data)
            return r_search(t->lchild, val);
        else
            return r_search(t->rchild, val);
    }
    void nr_search(int val)
    {
        int level = 0;
        string position = "";
        if (root == NULL)
        {
            cout << "EMPTY TREE" << endl;
            return;
        }
        Node *t = root;
        while (t != NULL)
        {
            if (t->data < val)
            {
                level++;
                position += "right,";
                t = t->rchild;
            }
            else if (t->data > val)
            {
                level++;
                position += "left,";
                t = t->lchild;
            }
            else
            {
                cout << "element found at:" << endl;
                cout << "Level = " << level << " And position =" << position << endl;
                return;
            }
        }
        cout << "Element not found" << endl;
        return;
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
    BST.nr_search(35);
    if (BST.r_search(BST.root, 34))
        cout << "VALUE FOUND" << endl;
    else
        cout << "VALUE NOT FOUND" << endl;
}
