// A union-find algorithm to detect
//  cycle in a graph
#include <bits/stdc++.h>
using namespace std;

class Edge {
  public:
    int src, dest;
};

class Graph {
  public:
    int v, e;   // vertices and edges
    Edge *edge; // Array of Edges
    Graph(int v, int e) {
        this->v = v;
        this->e = e;
        edge = new Edge[e];
    }

    int isCycle();
};

// A utility function to find the subset
// of an element i

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// function to do union of two subsets

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);

    parent[xset] = yset;
}

// cycle detector

int Graph::isCycle() {
    int *parent = new int[v]; // all the elemenets  are parent to itself so
                              // setting -1 to it

    memset(parent, -1, sizeof(int) * v);

    for (int i = 0; i < e; i++) {
        int x = find(parent, edge[i].src);
        int y = find(parent, edge[i].dest);

        if (x == y)
            return 1;
        Union(parent, x, y);
    }

    return 0;
}

int main() {
    int v = 3, e = 3;
    Graph graph(v, e);

    graph.edge[0].src = 0;
    graph.edge[0].dest = 1;

    graph.edge[1].src = 1;
    graph.edge[1].dest = 2;

    graph.edge[2].src = 0;
    graph.edge[2].dest = 2;

    if (graph.isCycle())
        cout << "Graph contains cycle" << endl;
    else
        cout << "Graph does not contain  cycle" << endl;
}
