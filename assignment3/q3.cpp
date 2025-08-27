
#include <iostream>
using namespace std;

int Balanced(const string &s)
{
    int n = s.length();
    char stack[n];
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c == '{' || c == '[' || c == '(')//pushing
        {
            top++;
            stack[top] = c;//push()
        }
        else if (c == '}' || c == ']' || c == ')')//popping
        {
            if (top == -1)
                return 0;
            char topChar = stack[top];
            if ((c == '}' && topChar != '{') || (c == ']' && topChar != '[') || (c == ')' && topChar != '('))
            {
                return 0;
            }
            top--;//pop()
        }
    }
    return (top == -1);
}

int main()
{
    string s;
    cout << "Enter expression: ";
    cin >> s;

    if (Balanced(s))
    {
        cout << "balanced" << endl;
    }
    else
    {
        cout << "Not balanced" << endl;
    }

    return 0;
}

