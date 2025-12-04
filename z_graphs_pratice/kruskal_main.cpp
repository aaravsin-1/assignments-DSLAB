#include <iostream>
using namespace std;

struct EdgeInfo
{
    int u, v;
    double w;
};

class Graph
{
public:
    int V;

    struct node
    {
        int val;
        double weight;
        node *next;
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

    // --------------------- Union-Find ------------------------
    int findSet(int parent[], int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findSet(parent, parent[x]);
    }

    void unionSet(int parent[], int rank[], int a, int b)
    {
        a = findSet(parent, a);
        b = findSet(parent, b);

        if (a == b)
            return;

        if (rank[a] < rank[b])
            parent[a] = b;
        else if (rank[b] < rank[a])
            parent[b] = a;
        else
        {
            parent[b] = a;
            rank[a]++;
        }
    }

    // --------------------- KRUSKAL ---------------------------
    void kruskal()
    {
        // Step 1: Put all edges in array (avoid duplicates)
        EdgeInfo edges[200];
        int ecount = 0;

        for (int u = 0; u < V; u++)
        {
            node *t = head[u];
            while (t != nullptr)
            {
                int v = t->val;

                if (u < v) // avoid duplicates in undirected graph
                {
                    edges[ecount].u = u;
                    edges[ecount].v = v;
                    edges[ecount].w = t->weight;
                    ecount++;
                }

                t = t->next;
            }
        }

        // Step 2: Bubble sort edges by weight
        for (int i = 0; i < ecount - 1; i++)
        {
            for (int j = 0; j < ecount - i - 1; j++)
            {
                if (edges[j].w > edges[j + 1].w)
                {
                    EdgeInfo temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }

        // Step 3: Union-Find to build MST
        int parent[V];
        int rank[V];

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }

        cout << "\nMST by Kruskal’s Algorithm:\n";

        for (int i = 0; i < ecount; i++)
        {
            int u = edges[i].u;
            int v = edges[i].v;

            if (findSet(parent, u) != findSet(parent, v))
            {
                cout << u << " -- " << v << "  weight=" << edges[i].w << endl;
                unionSet(parent, rank, u, v);
            }
        }
    }
};

// -------------------------------------------------------

int main()
{
    Graph G(5);

    G.addEdge(0, 1, 2);
    G.addEdge(0, 3, 6);
    G.addEdge(1, 2, 3);
    G.addEdge(1, 3, 8);
    G.addEdge(1, 4, 5);
    G.addEdge(2, 4, 7);
    G.addEdge(3, 4, 9);

    G.kruskal();

    return 0;
}
