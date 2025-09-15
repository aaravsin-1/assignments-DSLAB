#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// LinkedList class
class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // Insert at beginning
    void insert_beg(int val)
    {
        Node *n = new Node(val);
        n->next = head;
        head = n;
    }

    // Display list
    void display()
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

    int deletekey(int key)
    {
        int count = 0;

        while (head != nullptr && head->data == key)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            count++;
        }

        Node *t = head;
        Node *prev = nullptr;

        while (t != nullptr)
        {
            if (t->data == key)
            {
                count++;
                prev->next = t->next;
                delete t;
                t = prev->next;
            }
            else
            {
                prev = t;
                t = t->next;
            }
        }

        return count;
    }
};

int main()
{
    LinkedList myList;
    myList.insert_beg(1);
    myList.insert_beg(3);
    myList.insert_beg(1);
    myList.insert_beg(2);
    myList.insert_beg(1);
    myList.insert_beg(2);
    myList.insert_beg(1);

    cout << "Original List: ";
    myList.display();

    int key = 1;
    int count = myList.deletekey(key);

    cout << "Count: " << count << endl;
    cout << "Updated List: ";
    myList.display();

    return 0;
}
