#include <iostream>
using namespace std;

#define INF 999999
#define MAX 100   // Maximum number of vertices allowed

void dijkstra(int G[MAX][MAX], int V, int src)
{
    int dist[MAX];      // shortest distances
    int visited[MAX];   // visited array
    int parent[MAX];    // predecessor array

    // --- Initialize ---
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[src] = 0;

    // --- Dijkstra main loop ---
    for (int count = 0; count < V - 1; count++)
    {
        // Step 1: pick the UNVISITED vertex with the smallest dist[]
        int u = -1;
        int minDist = INF;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = 1; // Mark as processed

        // Step 2: Relax all neighbors v of u
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && G[u][v] != 0 && dist[u] + G[u][v] < dist[v])
            {
                dist[v] = dist[u] + G[u][v];
                parent[v] = u;
            }
        }
    }

    // --- Print results ---
    cout << "\nShortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << "To " << i << " = " << dist[i] << endl;
    }

    cout << "\nShortest Paths (parent array):\n";
    for (int i = 0; i < V; i++)
    {
        cout << "Parent of " << i << " = " << parent[i] << endl;
    }
}
