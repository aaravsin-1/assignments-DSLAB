#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value = 0)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    Node* get_head()
    {
        return head;
    }

    void append(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            {
                temp = temp->next;
            }
        temp->next = newNode;
    }

    void display()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

bool search_list(Node* h, int val)
{
    Node* t = h;
    while (t != nullptr) // include last node
    {
        if (t->data == val) // comparison
            return true;
        t = t->next;
    }
    return false;
}

int main()
{
    LinkedList myList;
    int size;
    cout << "Please enter the number of nodes: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int ele;
        cout << "Enter element: ";
        cin >> ele;
        myList.append(ele);
    }

    cout << "Elements: ";
    myList.display();

    int v;
    cout << "\nEnter a value to be searched: ";
    cin >> v;

    bool found = search_list(myList.get_head(), v);
    found ? cout << "Element found" << endl : cout << "Element not found" << endl;

    return 0;
}
