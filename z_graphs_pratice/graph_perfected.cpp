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

    void printaddlist()
    {
        for (int i = 0; i < V; i++)
        {
            node *t1 = head[i];
            cout << i << ":";
            while (t1 != nullptr)
            {
                cout << "(" << t1->val << "," << t1->weight << ")" << ",";
                t1 = t1->next;
            }
            cout << endl;
        }
    }

    void bfs(int start)
    {
        int Q[V];
        int front = 0;
        int rear = 0;

        int visited[V] = {0};

        visited[start] = 1;
        Q[rear++] = start;

        while (!(front == rear))
        {
            int v = Q[front++];
            cout << v << ",";
            node *t = head[v];
            while (t != nullptr)
            {
                if (!visited[t->val])
                {
                    Q[rear++] = t->val;
                    visited[t->val] = 1;
                }
                t = t->next;
            }
        }
        cout<<endl;
    }

    void dfs(int start)
    {
        int Gstack[V];
        int visited[V] = {0};
        int top = 0;

        Gstack[top++] = start;
        visited[start] = 1;
        
        while(top!=0)
        {
            int v = Gstack[--top];
            cout<<v<<",";

            node *t = head[v];
            while(t!=nullptr)
            {
                int v = t->val;
                if(!visited[v])
                {
                    Gstack[top++] = v;
                    visited[v] = 1;
                }
                t = t->next;
            }
        }
        cout<<endl;
    }
};

int main()
{
    Graph G1(4);
    G1.addEdge(0, 1, 0.2);
    G1.addEdge(0, 2, 1.5);
    G1.addEdge(1, 3, 2.3);
    G1.printaddlist();
    G1.bfs(0);
    G1.dfs(0);
}