#include <bits/stdc++.h>
using namespace std;

class Solution1 {
  public:
    void dfs(vector<int> &ans, vector<bool> &visited, vector<int> adj[],
             int curr) {
        visited[curr] = true;

        // ans.push_back(curr);

        cout << curr << " ";

        for (int elem : adj[curr]) {
            if (!visited[elem])
                dfs(ans, visited, adj, elem);
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    void dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<bool> visited(V, false);
        dfs(ans, visited, adj, 0);
    }
};

class Solution {
  public:
    // Function to find a Mother Vertex in the Graph.

    void dfs(int src, vector<int> adj[], vector<bool> &visited,
             int &countNodes) {

        visited[src] = true;
        // cout << src << " ";
        countNodes++;

        for (int elem : adj[src]) {
            if (!visited[elem])
                dfs(elem, adj, visited, countNodes);
        }
    }

    int findMotherVertex(int V, vector<int> adj[]) {
        // Code here

        int ans = -1;

        for (int i = 0; i < V; i++) {
            int countNodes = 0;
            vector<bool> visited(V, false);
            dfs(i, adj, visited, countNodes);
            visited.clear();
            cout << " V  : " << V << " i : " << i
                 << " countNodes : " << countNodes << endl;

            if (countNodes == V) {
                cout << " return i : " << i << endl;
                ans = i;
            }
        }

        return ans;
    }
};

int main() {

    Solution sol;
    // int v = 5;
    // vector<int> adj[v] = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

    // 6 12
    // 4 2
    // 1 4
    // 0 3
    // 2 3
    // 5 4
    // 1 5
    // 3 0
    // 5 3
    // 4 3
    // 2 0
    // 4 1
    // 5 2

    int v = 6;
    vector<int> adj[v] = {
        {4, 2}, {1, 4}, {0, 3}, {2, 3}, {5, 4}, {1, 5},
        {3, 0}, {5, 3}, {4, 3}, {2, 0}, {4, 1}, {5, 2},
    };

    cout << "Solution " << endl;

    int ans = sol.findMotherVertex(v, adj);

    cout << "\nans : " << ans << endl;

    // cout << "Solution1 " << endl;
    // Solution1 sol1;

    // sol1.dfsOfGraph(v, adj);

    // cout << endl;

    return 0;
}