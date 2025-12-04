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

    // -------------------- Priority Queue Item --------------------
    struct PQItem
    {
        double dist;
        int v;
    };

    struct ComparePQ
    {
        bool operator()(const PQItem &a, const PQItem &b) const
        {
            return a.dist > b.dist; // min-heap behavior
        }
    };

    // -------------------- DIJKSTRA (NO PAIR, NO VECTOR) --------------------
    void dijkstra(int start)
    {
        double dist[1000];
        int parent[1000];
        int visited[1000];

        // initialize
        for (int i = 0; i < V; i++)
        {
            dist[i] = 1e9;
            parent[i] = -1;
            visited[i] = 0;
        }

        dist[start] = 0;

        priority_queue<PQItem, std::vector<PQItem>, ComparePQ> pq;
        pq.push({0, start});

        while (!pq.empty())
        {
            PQItem curr = pq.top();
            pq.pop();

            int u = curr.v;

            if (visited[u])
                continue;
            visited[u] = 1;

            node *t = head[u];
            while (t != nullptr)
            {
                int v = t->val;
                double w = t->weight;

                if (!visited[v] && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u;

                    pq.push({dist[v], v});
                }

                t = t->next;
            }
        }

        // ---------- OUTPUT ----------
        cout << "\nShortest distances from " << start << ":\n";
        for (int i = 0; i < V; i++)
            cout << "dist[" << i << "] = " << dist[i] << endl;

        cout << "\nShortest-path tree (parent array):\n";
        for (int i = 0; i < V; i++)
            cout << "parent[" << i << "] = " << parent[i] << endl;

        cout << endl;
    }
};

int main()
{
    Graph G(4);

    G.addEdge(0, 1, 0.2);
    G.addEdge(0, 2, 1.5);
    G.addEdge(1, 3, 2.3);

    G.dijkstra(0);

    return 0;
}
