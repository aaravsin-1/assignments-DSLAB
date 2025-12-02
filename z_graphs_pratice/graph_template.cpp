#include <iostream>
using namespace std;

#define MAXV 5   // number of vertices

struct node {
    int v;
    int w;
    node *next;
} *head[MAXV];

// void initGraph() {
//     for (int i = 0; i < MAXV; i++)
//         head[i] = nullptr;
// }

void addEdge(int u, int v, int w) {
    // u -> v
    node *t1 = new node;
    t1->v = v;
    t1->w = w;
    t1->next = head[u];
    head[u] = t1;

    // v -> u (undirected)
    node *t2 = new node;
    t2->v = u;
    t2->w = w;
    t2->next = head[v];
    head[v] = t2;
}

void printGraph() {
    for (int i = 0; i < MAXV; i++) {
        cout << "Adj[" << i << "] -> ";
        node *cur = head[i];
        while (cur != nullptr) {
            cout << "(" << cur->v << ", w=" << cur->w << ") -> ";
            cur = cur->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    // initGraph();

    addEdge(0, 1, 5);
    addEdge(0, 2, 3);
    addEdge(1, 3, 7);
    addEdge(2, 4, 2);

    printGraph();

    return 0;
}
