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
class Stack {
    CircularQueue q;
    int maxSize;

public:
    Stack(int s) {
        maxSize = s;
        q.size = s;
    }

    void push(int x) {
        if (q.isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }

        // Step 1: enqueue new element
        q.enqueue(x);

        // Step 2: rotate previous elements behind new one
        int rotations = (q.rear - q.front + q.size) % q.size;
        for (int i = 0; i < rotations; i++) {
            int val = q.dequeue();
            q.enqueue(val);
        }

        cout << x << " pushed" << endl;
    }

    int pop() {
        if (q.isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int val = q.dequeue();
        cout << val << " popped" << endl;
        return val;
    }

    int top() {
        if (q.isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q.peek();
    }

    bool isEmpty() {
        return q.isEmpty();
    }

    void display() {
        q.display();
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;

    s.pop();
    s.pop();

    s.push(40);
    s.push(50);

    cout << "Current stack: ";
    s.display();

    return 0;
}
