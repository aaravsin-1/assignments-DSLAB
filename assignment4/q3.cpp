/*
    Circular Queue implementation with menu
*/
#include <iostream>
using namespace std;

class CircularQueue {
public:
    int front, rear, size;
    int arrq[100];

    CircularQueue() {
        front = -1;
        rear = -1;
        size = 0;
    }

    bool enqueue(int n);
    int dequeue();
    bool isEmpty();
    bool isFull();
    int peek();
    void display();
};

bool CircularQueue::enqueue(int n) {
    if (isFull()) {
        cout << "Queue Full, Overflow Error" << endl;
        return false;
    }
    if (front == -1) { // first element
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    arrq[rear] = n;
    return true;
}

int CircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Empty, Underflow Error" << endl;
        return -1;
    }
    int temp = arrq[front];
    if (front == rear) {
        // Queue had 1 element, now empty
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
    return temp;
}

bool CircularQueue::isEmpty() {
    return (front == -1 && rear == -1);
}

bool CircularQueue::isFull() {
    return ((rear + 1) % size == front);
}

int CircularQueue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return arrq[front];
}

void CircularQueue::display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << arrq[i] << " ";
        if (i == rear) break;
        i = (i + 1) % size;
    }
    cout << endl;
}
int main() 
{
    CircularQueue qobj;
    CircularQueue temp;
    
    int input[] = {4,7,11,20,5,9};
    int s= 6;
    qobj.size = s;
    temp.size = s;

    //configure
    for(int i = 0;i<s;i++)//putting elements in the queue
    {
        qobj.enqueue(input[i]);
    }
    int half = s/2;
    for(int i  = 0;i<half;i++)
    { 
        temp.enqueue(qobj.dequeue());
    }
    
    // ? repeat half times
    for(int i = 0;i<half;i++)
    {
        // ! dequeue from temp and enqueue onto q
        int t = temp.dequeue();
        qobj.enqueue(t);

        // ! dequeue from self and enqueue onto q
        t = qobj.dequeue();
        qobj.enqueue(t);
    }
    qobj.display();

}