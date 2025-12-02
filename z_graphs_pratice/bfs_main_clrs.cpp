#include <iostream>
using namespace std;

class Graph
{
public:
    int V;
    struct node
    {
        int val = 0;
        double weight = 0;
        node *next = nullptr;
    };

    node **head;
    Graph(int V = 0)
    {
        this->V = V;
        head = new node *[V];

        for (int i = 0; i < V; i++) // to prevent garbage values
            head[i] = nullptr;
    }

    void addEdge(int u, int v, double w)
    {
        node *t1 = new node;
        t1->val = v;
        t1->weight = w;
        t1->next = head[u];
        head[u] = t1;

        node *t2 = new node;
        t2->val = u;
        t2->weight = w;
        t2->next = head[v];
        head[v] = t2;
    }

    void bfs(int start)
    {
        int Q[V];
        int front = 0;
        int rear = 0;

        int visited[V] = {0};
        int parent[V];
        int dist[V];

        // Initialize parent and distance
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1; // NIL
            dist[i] = -1;   // infinity-like
        }

        visited[start] = 1;
        parent[start] = -1; // root of BFS tree
        dist[start] = 0;

        Q[rear++] = start;

        cout << "BFS Order: ";

        while (front != rear)
        {
            int u = Q[front++]; // pop front
            cout << u << ",";

            node *t = head[u];
            while (t != nullptr)
            {
                int v = t->val;

                if (!visited[v])
                {
                    visited[v] = 1;
                    parent[v] = u;         // BFS tree parent
                    dist[v] = dist[u] + 1; // distance
                    Q[rear++] = v;         // enqueue
                }

                t = t->next;
            }
        }

        cout << "\n\nBFS Tree (parent array):\n";
        for (int i = 0; i < V; i++)
            cout << "parent[" << i << "] = " << parent[i] << endl;

        cout << "\nDistance from " << start << ":\n";
        for (int i = 0; i < V; i++)
            cout << "dist[" << i << "] = " << dist[i] << endl;

        cout << endl;
    }
};

int main()
{
    Graph G1(4);
    G1.addEdge(0, 1, 0.2);
    G1.addEdge(0, 2, 1.5);
    G1.addEdge(1, 3, 2.3);

    G1.bfs(0);
}