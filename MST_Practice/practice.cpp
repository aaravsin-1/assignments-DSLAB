#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;

        Node(int value  = 0)
        {
            data = value;
            next = nullptr;
        }
};
class LinkedList
{
    Node *head;
    public:
        LinkedList(Node *n = nullptr)
        {
            head = n;
        }
        Node* get_head()
        {
            return head;
        }
};
bool search_list(Node *h,int val)
{
    Node *t = h;
    while(t != nullptr)
    {
        if(t->data == val)
        {
            return true;
        }
        t = t->next;
    }
    return false;
}
int main()
{
    Node *n = new Node;
    LinkedList myList(n);
    Node *t;

    int size;
    cout<<"Please enter the number of nodes:";
    cin>>size;
    for(int i = 0;i<size;i++)//initialising linked list(adding to end)
    {
        cout<<"Enter Element:";
        cin>>n->data;
        t = n;
        n = new Node;
        t->next = n;
    }
    n->next = NULL;//! for termination
    cout<<"Elements:"<<endl;
    t = myList.get_head();//head element
    for(int i = 0;i<size;i++)
    {
        cout<<t->data<<"->";
        t = t->next;
    }
    
    int v;
    cout<<"\nEnter a value to be searched:";
    cin>>v;

    bool search = search_list(myList.get_head(),v);
    search == 1?cout<<"Element found"<<endl : cout<<"Element not found"<<endl;
}

