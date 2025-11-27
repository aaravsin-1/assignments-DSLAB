#include <iostream>
#include <algorithm>
using namespace std;


class disjSet {
    int *parent, *rank;
    int n;
public:
    disjSet(int n) {
        this->n = n;
        parent = new int[n+1];
        rank = new int[n+1];
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (rank[x] > rank[y])
            parent[y] = x;
        else
            parent[x] = y;
        if (rank[x] == rank[y])
            rank[y]++;
    }
};

struct Edge {
    int src, dest, weight;
};

class Graph {
public:
    int V, E;
    Edge* edge;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        edge = new Edge[E];
    }

    void KruskalMST() {
        Edge result[V];
        int e = 0; 
        int i = 0;

        sort(edge, edge + E, [](Edge a, Edge b){
            return a.weight < b.weight;
        });

        disjSet ds(V);

        while (e < V - 1 && i < E) {
            Edge next_edge = edge[i++];

            int x = ds.find(next_edge.src);
            int y = ds.find(next_edge.dest);

            if (x != y) {
                result[e++] = next_edge;
                ds.merge(x, y);
            }
        }

        cout << "Following are the edges in the constructed MST\n";
        int minimumCost = 0;
        for (i = 0; i < e; ++i) {
            cout << result[i].src << " -- " << result[i].dest
                 << " == " << result[i].weight << endl;
            minimumCost += result[i].weight;
        }
        cout << "Minimum Cost Spanning tree : " << minimumCost;
    }
};
int main() {
    int V = 9;   // number of vertices
    int E = 14;  // number of edges

    Graph g(V, E);

    g.edge[0]  = {0, 7, 1};   
    g.edge[1]  = {5, 6, 2};   
    g.edge[2]  = {2, 8, 2};   
    g.edge[3]  = {0, 1, 4};   
    g.edge[4]  = {2, 5, 4};  
    g.edge[5]  = {6, 8, 6};  
    g.edge[6]  = {2, 3, 7};  
    g.edge[7]  = {7, 8, 7};   
    g.edge[8]  = {0, 7, 8}; 
    g.edge[9]  = {1, 2, 8};   
    g.edge[10] = {3, 4, 9};  
    g.edge[11] = {4, 5, 10};  
    g.edge[12] = {1, 7, 11};  
    g.edge[13] = {3, 5, 14};  

    g.KruskalMST();
    cout<<endl;
    return 0;
}
