/*
    Queue implementation with menu
*/
#include <iostream>
using namespace std;

class Q {
public:
    int front, rear, size;
    int arrq[100];

    Q() {
        front = -1;
        rear = -1;
        size = 0;
    }

    int enqueue(int n);
    int dequeue();
    bool isEmpty();
    bool isFull();
    int peek();
    void display();
};

int Q::enqueue(int n) {
    if (isFull()) {
        cout << "Queue Full, Overflow Error" << endl;
        return -1;
    }
    if (front == -1) front = 0; // first element
    rear++;
    arrq[rear] = n;
    return 1; // success
}

int Q::dequeue() {
    if (isEmpty()) {
        cout << "Queue Empty, Underflow Error" << endl;
        return -1;
    }
    int temp = arrq[front];
    if (front == rear) {
        // queue had 1 element, now empty
        front = rear = -1;
    } else {
        arrq[front] = 0;
        front++;
    }
    return temp;
}

bool Q::isEmpty() {
    return (front == -1 && rear == -1);
}

bool Q::isFull() {
    return (rear == size - 1);
}

int Q::peek() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return arrq[front];
}

void Q::display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << arrq[i] << " ";
    }
    cout << endl;
}

int main() {
    Q qobj;
    int choice, val;

    cout << "Enter the size of the queue: ";
    cin >> qobj.size;

    do {
        cout << "\n---- Queue Menu ----" << endl;
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
            qobj.enqueue(val);
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