#include <iostream>
using namespace std;

char stack[100];
int si = 0;
int top = -1;

char pop() {
    if (top == -1) {
        cout << "Stack Underflow Error" << endl;
        return '\0';
    } else {
        char val = stack[top];
        top--;
        return val;
    }
}

int push(char n) {
    if (top == si - 1) {
        cout << "Stack Overflow" << endl;
        return 1;
    } else {
        top++;
        stack[top] = n;
        return 0;
    }
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    si = s.length();

    for(int i = 0; i < si; i++) {
        push(s[i]);
    }

    string rev_s = "";  

    for(int i = 0; i < si; i++) {
        rev_s += pop();
    }

    cout << "Reversed String: " << rev_s << endl;

    return 0;
}
