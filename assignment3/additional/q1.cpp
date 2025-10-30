#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nearestSmallerToLeft(const vector<int>& A) {
    stack<int> s;
    vector<int> ans;

    for (int x : A) {
        while (!s.empty() && s.top() >= x)
            s.pop();

        if (s.empty()) ans.push_back(-1);
        else ans.push_back(s.top());

        s.push(x);
    }
    return ans;
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    auto res = nearestSmallerToLeft(A);
    for (int x : res) cout << x << " ";
}
