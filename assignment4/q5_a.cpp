#include <iostream>
using namespace std;

//push in O(1) and pop in O(n) -> pop heavy

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
    CircularQueue q1, q2; // two queues
    int maxSize;

public:
    Stack(int s) {
        maxSize = s;
        q1.size = s;
        q2.size = s;
    }

    void push(int x) {
        if (q1.isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        q1.enqueue(x);  // Just enqueue into q1
        cout << x << " pushed" << endl;
    }

    int pop() {
        if (q1.isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        // Move all except last from q1 to q2
        while (q1.front != q1.rear) {
            int val = q1.dequeue();
            q2.enqueue(val);
        }

        // Last element of q1 is the stack "top"
        int popped = q1.dequeue();

        // Swap q1 and q2
        CircularQueue temp = q1;
        q1 = q2;
        q2 = temp;

        cout << popped << " popped" << endl;
        return popped;
    }

    int top() {
        if (q1.isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        // Similar trick: move till last
        while (q1.front != q1.rear) {
            int val = q1.dequeue();
            q2.enqueue(val);
        }
        int val = q1.peek(); // top element
        q2.enqueue(q1.dequeue());

        // swap back
        CircularQueue temp = q1;
        q1 = q2;
        q2 = temp;

        return val;
    }

    bool isEmpty() {
        return q1.isEmpty();
    }

    void display() {
        q1.display();
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