#include <iostream>
#include <vector>
#include <stack> 

using namespace std;

// Iterative DFS function
void dfsIterative(int startNode, int V, const vector<vector<int>>& adj) {

    vector<bool> visited(V, false);
    stack<int> s;
    s.push(startNode);

    cout << "Iterative DFS Traversal: ";

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (!visited[u]) {
            visited[u] = true;
            cout << u << " ";

            for (int v : adj[u]) {
                if (!visited[v]) {
                    s.push(v);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0].push_back(1); adj[1].push_back(0);
    adj[0].push_back(2); adj[2].push_back(0);
    adj[1].push_back(3); adj[3].push_back(1);
    adj[2].push_back(4); adj[4].push_back(2);
    dfsIterative(0, V, adj);

    return 0;
}