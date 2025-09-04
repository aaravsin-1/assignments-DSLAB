/*
    Write a program to find first non-repeating character in a string using Queue. Sample I/P: a a
    b c Sample O/P: a -1 b b
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

int main() {
    CircularQueue qobj;
    char arr[] = {'a', 'a', 'b', 'c'};
    int s = 4;
    qobj.size = 100; 

    int freq[1000] = {0}; // frequency tracker

    for (int i = 0; i < s; i++) {
        int x = arr[i];
        freq[x]++;

        qobj.enqueue(x);

        // remove elements that repeat
        while (!qobj.isEmpty() && freq[qobj.peek()] > 1) {
            qobj.dequeue();
        }

        if (qobj.isEmpty()) cout << -1 << " ";
        else cout << (char)qobj.peek() << " ";
    }
    return 0;
}