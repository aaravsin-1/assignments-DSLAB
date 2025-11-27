#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int startNode, int V, const vector<vector<int>>& adj) {
    
    vector<bool> visited(V, false);
    
    
    queue<int> q;

    
    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        
        int u = q.front();
        q.pop();
        cout << u << " ";

        
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
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

    bfs(0, V, adj);

    return 0;
}