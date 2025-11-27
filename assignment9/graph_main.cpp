#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    struct Edge
    {
        int val;
        float weight;
        Edge(int v,int w):val(v),weight(w){}
    };
    int V;
    vector<vector<Edge>> adj;
    public:
        Graph(int N = 0): V(N),adj(N){};
        void addEdge(int u,int v,int w);
        void printGraph();
        void bfs();
        void dfs();
};
void Graph::addEdge(int u,int v,int w)
{
    if(u>=V || v>=V)
    {
        cout<<"index out of bounds"<<endl;
        return;
    }
    adj[u].push_back(Edge(v,w));
    adj[v].push_back(Edge(u,w));//undirected graph
}
void Graph::printGraph()
{
    for(int u = 0;u<V;u++)
    {
        cout<<u<<":";
        for(auto &e:adj[u])
        {
            cout<<"("<<e.val<<","<<e.weight<<")"<<",";
        }
        cout<<endl;
    }
}
void Graph::bfs
int main()
{
    Graph myGraph(5);
    myGraph.addEdge(0,1,1.2);
    myGraph.addEdge(0,2,1.3);
    myGraph.addEdge(0,3,1.4);
    myGraph.addEdge(1,2,2.4);
    myGraph.addEdge(1,3,2.5);
    myGraph.printGraph();
}