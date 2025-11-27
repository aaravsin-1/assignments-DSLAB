#include <iostream>
#include <vector>
using namespace std;

#define V 5
class Edge
{
    public:
    int val;
    int weight;
    Edge(int v = 0,int w = 0)
    {
        this->val = v;
        this->weight = w;
    }
};

vector<vector<Edge>> adj(V);

void addEdge(int u,int v,int w)
{
    adj[u].push_back(Edge(v,w));
    adj[v].push_back(Edge(u,w));
}

void bfs()
{

}

int main()
{
    int u = 0;
    addEdge(0,1,0.1);
    addEdge(0,2,0.1);
    addEdge(0,3,0.1);

    for(const auto &i:adj[u])
    {
        cout<<i.val<<", "<<i.weight<<endl;
    }
}