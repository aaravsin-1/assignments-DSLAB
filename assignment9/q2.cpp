#include <iostream>
#include <vector>
using namespace std;

struct EdgeInfo {
    int vertex;   // the connected vertex
    int weight;   // edge weight
};

class Graph {
public:
    int V;  
    vector<vector<EdgeInfo>> adj;   // adjacency list

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        EdgeInfo e1;
        e1.vertex = v;
        e1.weight = w;

        EdgeInfo e2;
        e2.vertex = u;
        e2.weight = w;

        adj[u].push_back(e1);
        adj[v].push_back(e2);    // remove for directed graph
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (auto &edge : adj[i]) {
                cout << "(" << edge.vertex << ", weight=" << edge.weight << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 7);

    g.printGraph();

    return 0;
}
