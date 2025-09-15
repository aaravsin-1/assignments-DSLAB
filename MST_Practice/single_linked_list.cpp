#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
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

    // Insert at end
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
            temp = temp->next;

        temp->next = newNode;
    }

    // Iterative search
    bool search(int num)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return false;
        }

        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp->data == num)
                return true;
            temp = temp->next;
        }

        return false;
    }

    // Display list
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

int main()
{
    LinkedList myList;
    int size;
    cout << "Enter the number of nodes: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int ele;
        cout << "Enter element: ";
        cin >> ele;
        myList.append(ele); // Properly add node
    }

    cout << "Your linked list: ";
    myList.display();

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    if (myList.search(key))
        cout << "Element " << key << " found" << endl;
    else
        cout << "Element " << key << " not found" << endl;

    return 0;
}
