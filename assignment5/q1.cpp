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

int main()
{
    LinkedList myList;
    int choice, val, newval;

    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a value\n";
        cout << "4. Insert before a value\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific node\n";
        cout << "8. Search for a node\n";
        cout << "9. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            myList.insert_beg(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            myList.insert_end(val);
            break;
        case 3:
            cout << "Enter existing value: ";
            cin >> val;
            cout << "Enter new value: ";
            cin >> newval;
            myList.insert_after(val, newval);
            break;
        case 4:
            cout << "Enter existing value: ";
            cin >> val;
            cout << "Enter new value: ";
            cin >> newval;
            myList.insert_before(val, newval);
            break;
        case 5:
            myList.delete_beg();
            break;
        case 6:
            myList.delete_end();
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> val;
            myList.delete_spec(val);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> val;
            myList.search_node(val);
            break;
        case 9:
            myList.display();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
