#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e9; 
typedef pair<int, int> pii;

void dijkstra(int startNode, int V, vector<vector<pii>>& adj) {
    vector<int> dist(V, INF);
    
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    
    dist[startNode] = 0;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        
        if (d > dist[u]) continue;

        
        for (auto neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    
    cout << "Shortest distances from Node " << startNode << ":" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": " << (dist[i] == INF ? -1 : dist[i]) << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    addEdge(0, 1, 4);
    addEdge(0, 2, 1);
    addEdge(2, 1, 2);
    addEdge(1, 3, 1);
    addEdge(2, 3, 5);
    addEdge(3, 4, 3);

    dijkstra(0, V, adj);

    return 0;
}