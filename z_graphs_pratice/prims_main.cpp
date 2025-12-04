#include <iostream>
#include <queue>
using namespace std;

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

    // -------------------------------------------------------
    // PRIM’S ALGORITHM (NO STL)
    // -------------------------------------------------------
    struct PQItem
    {
        double key;
        int v;
    };

    struct ComparePQ
    {
        bool operator()(const PQItem &a, const PQItem &b) const
        {
            return a.key > b.key; // min-heap
        }
    };

    void prims(int start)
    {
        double key[V];
        int parent[V];
        int inMST[V];

        for (int i = 0; i < V; i++)
        {
            key[i] = 1e9;
            parent[i] = -1;
            inMST[i] = 0;
        }

        key[start] = 0;

        priority_queue<PQItem, vector<PQItem>, ComparePQ> pq;
        pq.push({0, start});

        while (!pq.empty())
        {
            PQItem curr = pq.top();
            pq.pop();

            int u = curr.v;

            if (inMST[u])
                continue;

            inMST[u] = 1;

            node *t = head[u];
            while (t != nullptr)
            {
                int v = t->val;
                double w = t->weight;

                // Relaxation rule for Prim's:
                // take the smallest edge that connects the tree to a new vertex
                if (!inMST[v] && w < key[v])
                {
                    key[v] = w;
                    parent[v] = u;
                    pq.push({key[v], v});
                }

                t = t->next;
            }
        }

        cout << "\nMST using Prim’s Algorithm (priority queue):\n";
        for (int i = 0; i < V; i++)
        {
            if (parent[i] != -1)
                cout << parent[i] << " -- " << i << "   weight = " << key[i] << endl;
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

    G.prims(0);

    return 0;
}
