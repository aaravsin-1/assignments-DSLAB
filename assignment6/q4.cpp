/*
Doubly Linked List
*/
#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int v)
    {
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};
class DLL
{
    Node *head;
    Node *tail;

public:
    DLL()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insert_end(int v)
    {
        Node *n = new Node(v);
        if (head == nullptr)
        {
            head = n;
            tail = n;
            n->prev = nullptr;
            n->next = nullptr;
            return;
        }
        Node *t = head;
        while (t->next != nullptr)
        {
            t = t->next;
        }
        t->next = n;
        n->prev = t;
        n->next = nullptr;
        tail = n;
    }
    void display()
    {
        cout << endl;
        Node *t = head;
        while (t != nullptr)
        {
            cout << t->val << "->";
            t = t->next;
        }
        cout << "NULL" << endl;
        t = tail;
        while (t != nullptr)
        {
            cout << t->val << "->";
            t = t->prev;
        }
        cout << "NULL" << endl;
    }
    bool ch_pali()
    {
        Node *right = head;
        Node *left = tail;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {

            fast = fast->next->next;
            if (right->val != left->val)
            {
                return false;
            }
            else
            {
                right = right->next;
                left = left->prev;
            }
        }
        return true;
    }
};

int main()
{
    DLL myList;
    myList.insert_end(1);
    myList.insert_end(2);
    myList.insert_end(3);
    myList.insert_end(2);
    myList.insert_end(1);
    myList.display();
    myList.ch_pali() ? cout << "It is a palindome" << endl : cout << "It is not a palindome" << endl;
}