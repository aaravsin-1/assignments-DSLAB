#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<long long> s;
    long long minVal;
public:
    void push(int x) {
        if (s.empty()) {
            s.push(x);
            minVal = x;
        } else if (x < minVal) {
            s.push(2LL * x - minVal);
            minVal = x;
        } else s.push(x);
    }

    void pop() {
        if (s.empty()) return;
        long long t = s.top(); s.pop();
        if (t < minVal) minVal = 2 * minVal - t;
    }

    int top() {
        long long t = s.top();
        return (t < minVal) ? minVal : t;
    }

    int getMin() { return minVal; }
};

int main() {
    MinStack st;
    st.push(3); st.push(5);
    cout << st.getMin() << endl;
    st.push(2); st.push(1);
    cout << st.getMin() << endl;
    st.pop();
    cout << st.getMin() << endl;
}
