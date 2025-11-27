#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
PSEUDO-CODE:
Graph Traversal Count (Connected Components) This uses BFS to count how many disconnected parts exist in the graph.
1. Initialize `visited` array of size V to false.
2. Initialize `components` counter to 0.
3. Iterate through every node `i` from 0 to V-1:
    a. If `visited[i]` is false (we found a new unvisited component):
        i. Increment `components` by 1.
        ii. Call BFS(i) to traverse and mark the entire connected component.
           - Create a Queue and push `i`.
           - While Queue is not empty:
             - Pop node `u`.
             - For every neighbor `v` of `u`:
               - If `v` is not visited, mark `visited[v] = true` and push `v`.
4. Output `components`.
*/

void bfs(int startNode, int V, vector<bool>& visited, const vector<vector<int>>& adj) {
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int components = 0;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            components++;
            bfs(i, V, visited, adj);
        }
    }

    cout << components << endl;

    return 0;
}