#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& A) {
    int n = A.size();
    vector<int> res(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= A[i])
            s.pop();

        if (!s.empty()) res[i] = s.top();
        s.push(A[i]);
    }
    return res;
}

int main() {
    vector<int> A = {4, 5, 2, 25};
    auto res = nextGreaterElement(A);
    for (int x : res) cout << x << " ";
}
