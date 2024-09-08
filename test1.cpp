#include <bits/stdc++.h>
using namespace std;

class Util {
  public:
    template <typename T> void print2DVector(const vector<vector<T>> &vec) {
        for (const auto &row : vec) {
            for (const auto &element : row) {
                cout << element << " ";
            }
            cout << endl;
        }
    }
};

Util util;

class Graph {

    int v;
    // adjacency matrix  // adjacency list
    vector<int> *adj;

  public:
    Graph(int v) {
        this->v = v;
        adj = new vector<int>[v];
    }

    void printGraph() {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    // directed graph
    void addEdge(int src, int dest) {
        adj[src].push_back(dest);
        // adj[dest].push_back(src);
    }

    void bfs(int src) {
        // similar to queue in tree
        queue<int> q;
        q.push(src);

        vector<bool> visited(v, false); // initialize with false

        visited[src] = true;

        while (!q.empty()) {
            int elem = q.front();
            q.pop();
            cout << elem << "  ";

            for (int val : adj[elem]) {
                if (!visited[val]) {
                    q.push(val);
                    visited[val] = true;
                }
            }
        }
    }

    void createGraph(vector<pair<int, int>> &edges) {
        for (const auto &pr : edges) {
            addEdge(pr.first, pr.second);
        }
    }

    void dfsUtil(int src, vector<bool> &visited) {
        visited[src] = true;
        cout << src << " ";
        for (int val : adj[src]) {
            if (!visited[val]) {
                dfsUtil(val, visited);
            }
        }
    }

    void dfs(int src) {
        vector<bool> visited(v, false);
        dfsUtil(src, visited);
    }

    void solveUtil(int curr, int src, int dest, vector<bool> &visited,
                   int &ans) {

        if (curr == dest) {
            ans++;
            return;
        }

        int nCurr = curr == -1 ? src : curr;

        visited[nCurr] = true;

        for (int val : adj[nCurr]) {
            if (!visited[val]) {
                solveUtil(val, src, dest, visited, ans);
            }
        }
        visited[nCurr] = false;
    }

    void solve(int src, int dest, int &ans) {
        vector<bool> visited(v, false);
        visited[src] = true;
        // solveUtil(-1, src, dest, visited, ans);

        cout << " src : " << src << endl;

        for (int val : adj[src]) {
            if (!visited[val]) {
                cout << "val : " << val << endl;

                solveUtil(val, src, dest, visited, ans);
            }
        }
    }

    int possible_paths(int src, int dest) {
        // solve using dfs
        int ans = 0;

        solve(src, dest, ans);

        return ans;
    }
};

int main() {

    vector<pair<int, int>> edges = {{0, 1}, {0, 3}, {0, 2},
                                    {2, 0}, {2, 1}, {1, 3}};
    int n = 4;
    int start = 0;
    int destination = 3;

    Graph graph(n);
    graph.createGraph(edges);

    graph.printGraph();

    int ans = graph.possible_paths(start, destination);
    cout << "\nPossible Paths : " << ans << endl;

    // graph.addEdge(0, 1);
    // graph.addEdge(0, 2);
    // graph.addEdge(0, 3);
    // graph.addEdge(0, 4);
    // graph.addEdge(3, 1);
    // graph.addEdge(1, 2);
    // graph.addEdge(4, 2);
    // graph.addEdge(1, 3);

    // graph.printGraph();
    // cout << "BFS Traversal : " << endl;
    // for (int i = 0; i < n; i++) {
    //     // cout << "i : " << i << endl;
    //     graph.bfs(i);
    //     cout << endl;
    // }

    // cout << "DFS Traversal : " << endl;
    // for (int i = 0; i < n; i++) {
    //     // cout << "i : " << i << endl;
    //     graph.dfs(i);
    //     cout << endl;
    // }

    return 0;
}