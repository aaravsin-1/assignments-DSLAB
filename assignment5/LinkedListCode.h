#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value = 0)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }
    void insert_beg(int val);
    void insert_end(int val);
    void insert_after(int val, int newval);
    void insert_before(int val, int newval);
    void delete_beg();
    void delete_end();
    void delete_spec(int val);
    void search_node(int val);
    void display();
    Node* get_head()
    {
        return head;
    }
};

void LinkedList::insert_beg(int val)
{
    Node *n = new Node(val);
    n->next = head;
    head = n;
}

void LinkedList::insert_end(int val)
{
    Node *n = new Node(val);
    if (head == nullptr)
    {
        head = n;
        return;
    }
    Node *t = head;
    while (t->next != nullptr)
    {
        t = t->next;
    }
    t->next = n;
}

void LinkedList::insert_after(int val, int newval)
{
    Node *t = head;
    while (t != nullptr && t->data != val)
    {
        t = t->next;
    }
    if (t != nullptr)
    {
        Node *n = new Node(newval);
        n->next = t->next;
        t->next = n;
    }
    else
        cout << "Value " << val << " not found!" << endl;
}

void LinkedList::insert_before(int val, int newval)
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    // Special case: val is at head
    if (head->data == val)
    {
        insert_beg(newval);
        return;
    }

    Node *t = head;
    while (t->next != nullptr && t->next->data != val)
    {
        t = t->next;
    }
    if (t->next != nullptr)
    {
        Node *n = new Node(newval);
        n->next = t->next;
        t->next = n;
    }
    else
        cout << "Value " << val << " not found!" << endl;
}

void LinkedList::delete_beg()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::delete_end()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *t = head;
    while (t->next->next != nullptr)
    {
        t = t->next;
    }
    delete t->next;
    t->next = nullptr;
}

void LinkedList::delete_spec(int val)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->data == val)
    {
        delete_beg();
        return;
    }
    Node *t = head;
    while (t->next != nullptr && t->next->data != val)
    {
        t = t->next;
    }
    if (t->next != nullptr)
    {
        Node *temp = t->next;
        t->next = temp->next;
        delete temp;
    }
    else
        cout << "Value " << val << " not found!" << endl;
}

void LinkedList::search_node(int val)
{
    Node *t = head;
    int pos = 1;
    while (t != nullptr)
    {
        if (t->data == val)
        {
            cout << "Value " << val << " found at position " << pos << endl;
            return;
        }
        t = t->next;
        pos++;
    }
    cout << "Value " << val << " not found!" << endl;
}

void LinkedList::display()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *t = head;
    while (t != nullptr)
    {
        cout << t->data;
        if (t->next != nullptr)
            cout << " -> ";
        t = t->next;
    }
    cout << endl;
}
