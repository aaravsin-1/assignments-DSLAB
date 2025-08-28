#include <iostream>
using namespace std;

#define MAX 100


struct Stack {
    int arr[MAX];
    int top;
    
    Stack() { top = -1; }

    void push(int val) {
        if (top >= MAX - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = val;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int evaluatePostfix(char exp[]) {
    Stack s;
    int i = 0;

    while (exp[i] != '\0') {
        char ch = exp[i];

        // Skip spaces
        if (ch == ' ') {
            i++;
            continue;
        }

        // If digit, convert to number and push to stack
        if (ch >= '0' && ch <= '9') {
            int num = 0;
            while (exp[i] >= '0' && exp[i] <= '9') {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            s.push(num);
        }
        // If operator, pop two operands and apply operation
        else if (isOperator(ch)) {
            int b = s.pop();
            int a = s.pop();
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
            i++;
        } else {
            cout << "Invalid character: " << ch << endl;
            return -1;
        }
    }

    return s.pop();
}

int main() {
    char postfixExp[MAX];
    cout << "Enter postfix expression (space separated): ";
    cin.getline(postfixExp, MAX);
    int result = evaluatePostfix(postfixExp);
    cout << "Result: " << result << endl;

    return 0;
}