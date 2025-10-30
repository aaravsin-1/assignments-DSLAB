#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkSorted(queue<int> q) {
    stack<int> s;
    int expected = 1;
    int n = q.size();
    
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        if (front == expected) {
            expected++;
        } else {
            if (!s.empty() && s.top() < front)
                return false;
            s.push(front);
        }

        while (!s.empty() && s.top() == expected) {
            s.pop();
            expected++;
        }
    }
    return (expected - 1 == n);
}

int main() {
    queue<int> q;
    q.push(5); q.push(1); q.push(2); q.push(3); q.push(4);
    cout << (checkSorted(q) ? "Yes" : "No");
    return 0;
}
