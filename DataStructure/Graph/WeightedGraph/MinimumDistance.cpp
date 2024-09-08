#include <bits/stdc++.h>
using namespace std;

class Graph {
    int vertices;
    vector<pair<int, int>> *adj; // array of adjacency list with weight

  public:
    Graph(int v) {
        vertices = v;
        adj = new vector<pair<int, int>>[v];
    }

    void addEdge(int src, int dest, int weight);
    void printGraph();
    int pathLength(int src, int dest); // path length between two given nodes
};

void Graph::addEdge(int src, int dest, int weight) {
    adj[src].push_back(make_pair(dest, weight)); // directed graph
}

void Graph::printGraph() {
    for (int i = 0; i < vertices; i++) {
        cout << "Source Node is : " << i << endl;
        for (int j = 0; j < adj[i].size(); j++) {
            cout << "\tNext Node : " << adj[i][j].first
                 << "   Weight of the path :  " << adj[i][j].second << endl;
        }
    }
}

int Graph::pathLength(int src, int dest) {

    int len = INT_MAX;

    if (src == dest) // base condition for recursion call
        return 0;

    for (int i = 0; i < adj[src].size(); i++) {

        int tempLen = adj[src][i].second; // path length

        int retDist = pathLength(adj[src][i].first, dest);

        if (retDist == INT_MAX) // node has no child  .. element is not present
                                // in this side
            tempLen = INT_MAX;
        else
            tempLen += retDist;

        if (tempLen < len)
            len = tempLen;
    }

    return len;
}

int main() {

    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 1);
    // g.addEdge(4, 3,1);

    cout << g.pathLength(0, 4) << endl;
    cout << g.pathLength(0, 3) << endl;

    // int minDist = g.pathLength(0,34);

    int minDist = g.pathLength(2, 1);

    if (minDist == INT_MAX) {
        cout << "No route is availabe betweeen 0   and  34  nodes " << endl;
    } else {
        cout << minDist << endl;
    }
}