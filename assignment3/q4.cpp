#include <iostream>
using namespace std;

bool isOperand(char c) {
    return ( (c >= 'a' && c <= 'z') ||
             (c >= 'A' && c <= 'Z') ||
             (c >= '0' && c <= '9') );
}

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

void infixToPostfix(const string &s) {
    int n = s.length();
    char stack[n];  // stack implemented with array
    int top = -1;
    string post = "";

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == ' ') {
            // skip spaces
            continue;
        }
        else if (isOperand(c)) {
            post += c;
        }
        else if (c == '(') {
            stack[++top] = c;
        }
        else if (c == ')') {
            // pop until '('
            while (top >= 0 && stack[top] != '(') {
                post += stack[top--];
            }
            if (top >= 0 && stack[top] == '(')
                top--;  // pop '('
            else {
                cout << "Error: Mismatched parentheses\n";
                return;
            }
        }
        else {
            // operator
            while (top >= 0 && precedence(stack[top]) >= precedence(c) && stack[top] != '(') {
                post += stack[top--];
            }
            stack[++top] = c;
        }
    }

    // pop remaining operators
    while (top >= 0) {
        if (stack[top] == '(') {
            cout << "Error: Mismatched parentheses\n";
            return;
        }
        post += stack[top--];
    }

    cout << "Postfix expression: " << post << endl;
}

int main() {
    string s;
    cout << "Enter expression: ";
    getline(cin, s);

    infixToPostfix(s);

    return 0;
}