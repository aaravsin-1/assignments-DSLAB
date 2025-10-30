#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    vector<int> res(n, 0);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && T[i] > T[s.top()]) {
            int j = s.top(); s.pop();
            res[j] = i - j;
        }
        s.push(i);
    }
    return res;
}

int main() {
    vector<int> T = {73,74,75,71,69,72,76,73};
    auto res = dailyTemperatures(T);
    for (int x : res) cout << x << " ";
}
