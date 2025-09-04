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

int main() {
    CircularQueue qobj;
    int choice, val;

    cout << "Enter the size of the circular queue: ";
    cin >> qobj.size;

    do {
        cout << "\n---- Circular Queue Menu ----" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Check Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            if (qobj.enqueue(val)) 
                cout << "Enqueued " << val << endl;
            break;

        case 2:
            val = qobj.dequeue();
            if (val != -1) cout << "Dequeued: " << val << endl;
            break;

        case 3:
            val = qobj.peek();
            if (val != -1) cout << "Front element: " << val << endl;
            break;

        case 4:
            qobj.display();
            break;

        case 5:
            cout << (qobj.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
            break;

        case 6:
            cout << (qobj.isFull() ? "Queue is full" : "Queue is not full") << endl;
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 0);

    return 0;
}