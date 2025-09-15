#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
int main()
{
    node *n;//new node
    node *t;//temp
    node *h;//head

    n = new node;//! we point pointer n(of type node) to the node object(with both data and next pointer) 
    //? now we can assign it data
    n->data = 1;
    
    t = n;//temp also now points to the node object that n is pointing to
    h = n;//head also now points to the same node object
    // ! Note these do not point to n, they point to the same node object that is pointing to

    //? head is going to stay in this position the whole time ( we can later on come to the starting of the list and access data)
    //? but temp is going to traverse the entire list

    n = new node;// now n is pointing to a newly created node object(list isnt linked yet)

    n->data = 2;//now we put 2 in the data box

    t->next = n;//! the previous node that temp was pointing to, we use the next pointer of that node and now we connect 
    //!the two nodes by linking the next of the temp/previous node to the newly created node. This creates our link.

    t = n;// ? shift t to the new pointer (we could also write t = t->next [same thing])

    n = new node;//create node
    n->data = 3;//fill with data
    t->next = n;//connect nodes(previous temp to new n)
    t = n;//shift temp to the new(latest) node

    n->next = NULL;//! terminate list
}