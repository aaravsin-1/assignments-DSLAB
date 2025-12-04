#include <iostream>
using namespace std;

class Graph
{
public:
    int V;

    struct node
    {
        int val;        // neighbor
        double weight;  // edge weight
        node *next;     // next adjacency node
    };

    node **head;

    Graph(int V = 0)
    {
        this->V = V;
        head = new node *[V];
        for (int i = 0; i < V; i++)
            head[i] = nullptr;
    }

    void addEdge(int u, int v, double w)
    {
        node *t1 = new node{v, w, head[u]};
        head[u] = t1;

        node *t2 = new node{u, w, head[v]};
        head[v] = t2;
    }

    // -------------------- DIJKSTRA --------------------
    void dijkstra(int start)
    {
        double dist[V];
        int parent[V];
        int visited[V];

        // Initialize all arrays
        for (int i = 0; i < V; i++)
        {
            dist[i] = 1e9;   // infinity
            parent[i] = -1;  // NIL
            visited[i] = 0;  // not visited
        }

        dist[start] = 0;

        // Dijkstra main loop
        for (int c = 0; c < V - 1; c++)
        {
            // Extract-Min (find unvisited vertex with minimum dist[])
            int u = -1;
            double best = 1e9;

            for (int i = 0; i < V; i++)
            {
                if (!visited[i] && dist[i] < best)
                {
                    best = dist[i];
                    u = i;
                }
            }

            if (u == -1)
                break;

            visited[u] = 1;

            // Relax all edges from u
            node *t = head[u];

            while (t != nullptr)
            {
                int v = t->val;
                double w = t->weight;

                // Relax operation
                if (!visited[v] && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                }

                t = t->next;
            }
        }

        // -------- OUTPUT --------
        cout << "\nShortest distances from " << start << ":" << endl;
        for (int i = 0; i < V; i++)
            cout << "dist[" << i << "] = " << dist[i] << endl;

        cout << "\nShortest-path tree (parent array):" << endl;
        for (int i = 0; i < V; i++)
            cout << "parent[" << i << "] = " << parent[i] << endl;

        cout << endl;
    }
};

// -------------------- MAIN --------------------
int main()
{
    Graph G(4);

    G.addEdge(0, 1, 0.2);
    G.addEdge(0, 2, 1.5);
    G.addEdge(1, 3, 2.3);

    G.dijkstra(0);

    return 0;
}
