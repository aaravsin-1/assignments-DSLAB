#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

void primMST(int V, vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0}); 

    vector<bool> inMST(V, false);
    int mstCost = 0;

    cout << "Prim's Algorithm Processing..." << endl;

    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        mstCost += weight;
        
        if (weight != 0) 
            cout << "Included Node " << u << " with cost " << weight << endl;
        for (auto neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            
            if (!inMST[v]) {
                pq.push({w, v});
            }
        }
    }

    cout << "Total MST Cost: " << mstCost << endl;
}

int main() {
    int V = 4;
    vector<vector<pii>> adj(V);
    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    addEdge(0, 1, 10);
    addEdge(0, 2, 6);
    addEdge(0, 3, 5);
    addEdge(1, 3, 15);
    addEdge(2, 3, 4);

    primMST(V, adj);
    return 0;
}