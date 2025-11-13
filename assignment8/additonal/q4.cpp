#include <iostream>
#include <queue>
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
    void rightView(Node *r)
    {
        if (!r)
            return;
        queue<Node *> q;
        q.push(r);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *c = q.front();
                q.pop();
                if (c->left)
                    q.push(c->left);
                if (c->right)
                    q.push(c->right);
                if (i == n - 1)
                    cout << c->val << " ";
            }
        }
    }
};
int main()
{
    Node *r = new Node(1);
    r->left = new Node(2);
    r->right = new Node(3);
    r->left->left = new Node(4);
    r->left->right = new Node(5);
    Tree t;
    t.rightView(r);
}
/*
Pseudo Code
Class Node:
    val, left, right

Class Tree:
    Function rightView(root):
        If root is NULL:
            return
        queue = new empty queue
        enqueue(root)
        While queue not empty:
            size = number of elements in queue
            For i = 0 to size-1:
                current = dequeue
                If current.left exists:
                    enqueue(current.left)
                If current.right exists:
                    enqueue(current.right)
                If i == size - 1:
                    print current.val

Main:
    build tree
    Tree.rightView(root)

*/