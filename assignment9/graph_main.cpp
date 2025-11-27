#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
    struct Edge
    {
        int node;
        float weight;
        Edge(int v,float w):node(v),weight(w){}
    };

    int V;
    vector<vector<Edge>> adj;

public:
    Graph(int N = 0): V(N), adj(N) {}

    void addEdge(int u,int v,float w)
    {
        if(u>=V || v>=V)
        {
            cout<<"index out of bounds"<<endl;
            return;
        }
        adj[u].push_back(Edge(v,w));
        adj[v].push_back(Edge(u,w));
    }

    void printGraph()
    {
        for(int u=0;u<V;u++)
        {
            cout << u << ": ";
            for(const auto &e: adj[u])
            {
                cout << "(" << e.node << "," << e.weight << ") ";
            }
            cout << endl;
        }
    }

    void bfs(int start=0)
    {
        vector<bool> visited(V,false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            cout<<u<<" ";

            for(const auto &e : adj[u])
            {
                int v = e.node;
                if(!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }

    void dfs(int start=0)
    {
        vector<bool> visited(V,false);
        stack<int> s;

        s.push(start);

        while(!s.empty())
        {
            int u = s.top();
            s.pop();

            if (!visited[u])
            {
                visited[u] = true;
                cout << u << " ";
            }

            for(auto it = adj[u].rbegin(); it != adj[u].rend(); ++it)
            {
                int v = it->node;
                if(!visited[v])
                {
                    s.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph myGraph(5);
    myGraph.addEdge(0,1,1.2);
    myGraph.addEdge(0,2,1.3);
    myGraph.addEdge(0,3,1.4);
    myGraph.addEdge(1,2,2.4);
    myGraph.addEdge(1,3,2.5);

    myGraph.printGraph();

    cout << "BFS: ";
    myGraph.bfs(0);

    cout << "DFS: ";
    myGraph.dfs(0);
}
