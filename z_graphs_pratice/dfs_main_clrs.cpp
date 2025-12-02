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

    int *Color;   // DFS color
    int *Parent;  // DFS/BFS Tree
    int *D;       // DFS discovery time
    int *F;       // DFS finish time
    int Time;     // DFS timer

    Graph(int V = 0)
    {
        this->V = V;
        head = new node *[V];

        for (int i = 0; i < V; i++)
            head[i] = nullptr;

        Color  = new int[V];
        Parent = new int[V];
        D      = new int[V];
        F      = new int[V];
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

    // ------------------ BFS ------------------
    void bfs(int start)
    {
        int Q[V];
        int front = 0, rear = 0;

        int visited[V] = {0};
        int dist[V];

        for (int i = 0; i < V; i++)
        {
            Parent[i] = -1;
            dist[i] = -1;
        }

        visited[start] = 1;
        dist[start] = 0;
        Parent[start] = -1;

        Q[rear++] = start;

        cout << "BFS Order: ";

        while (front != rear)
        {
            int u = Q[front++];
            cout << u << ",";

            node *t = head[u];
            while (t != nullptr)
            {
                int v = t->val;

                if (!visited[v])
                {
                    visited[v] = 1;
                    Parent[v] = u;
                    dist[v] = dist[u] + 1;
                    Q[rear++] = v;
                }
                t = t->next;
            }
        }

        cout << "\nParent array (BFS tree):\n";
        for (int i = 0; i < V; i++)
            cout << "parent[" << i << "] = " << Parent[i] << endl;

        cout << "\nDistance:\n";
        for (int i = 0; i < V; i++)
            cout << "dist[" << i << "] = " << dist[i] << endl;
    }

    // ------------------ DFS (CLRS) ------------------
    void DFSVisit(int u)
    {
        Time++;
        D[u] = Time;
        Color[u] = 1;  // GRAY

        cout << u << ",";

        node *t = head[u];
        while (t != nullptr)
        {
            int v = t->val;
            if (Color[v] == 0)
            {
                Parent[v] = u;
                DFSVisit(v);
            }
            t = t->next;
        }

        Color[u] = 2;  // BLACK
        Time++;
        F[u] = Time;
    }

    void dfs()
    {
        for (int i = 0; i < V; i++)
        {
            Color[i] = 0;
            Parent[i] = -1;
        }

        Time = 0;

        cout << "DFS Order: ";

        for (int u = 0; u < V; u++)
        {
            if (Color[u] == 0)
                DFSVisit(u);
        }

        cout << "\n\nDFS Parent array:\n";
        for (int i = 0; i < V; i++)
            cout << "parent[" << i << "] = " << Parent[i] << endl;

        cout << "\nDiscovery times:\n";
        for (int i = 0; i < V; i++)
            cout << "d[" << i << "] = " << D[i] << endl;

        cout << "\nFinish times:\n";
        for (int i = 0; i < V; i++)
            cout << "f[" << i << "] = " << F[i] << endl;
    }
};

int main()
{
    Graph G1(4);
    G1.addEdge(0, 1, 0.2);
    G1.addEdge(0, 2, 1.5);
    G1.addEdge(1, 3, 2.3);

    G1.bfs(0);
    G1.dfs();
}
