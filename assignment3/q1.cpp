#include <iostream>
using namespace std;

int stack[100];
int s = 0;
int top = -1;

void peek() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Top element is: " << stack[top] << endl;
    }
}

void display() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack elements:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
}

int pop() {
    if (top == -1) {
        cout << "Stack Underflow Error" << endl;
        return -1;  // error value
    } else {
        int val = stack[top];
        top--;
        return val;
    }
}

int isEmpty() {
    return (top == -1) ? 1 : 0;
}

int push(int n) {
    if (top == s - 1) {
        cout << "Stack Overflow" << endl;
        return 1;
    } else {
        top++;
        stack[top] = n;
        return 0;
    }
}

int main() {
    cout << "Enter size of stack: ";
    cin >> s;

    int ex = 0;
    while (ex == 0) {
        cout << "\n1.push()" << endl;
        cout << "2.pop()" << endl;
        cout << "3.isEmpty()" << endl;
        cout << "4.display()" << endl;
        cout << "5.peek()" << endl;
        cout << "6.exit" << endl;

        int ch = 0;
        cin >> ch;

        switch (ch) {
            case 1: {
                int n = 0;
                cout << "Enter an element to be pushed: ";
                cin >> n;
                int log = push(n);
                if (log == 1) {
                    // stack overflow, no exit needed; just continue
                }
                break;
            }
            case 2: {
                int i = pop();
                if (i != -1) {
                    cout << "Popped element: " << i << endl;
                }
                break;
            }
            case 3: {
                if (isEmpty()) {
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Stack is not empty" << endl;
                }
                break;
            }
            case 4: {
                display();
                break;
            }
            case 5: {
                peek();
                break;
            }
            case 6: {
                ex = 1;
                break;
            }
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}