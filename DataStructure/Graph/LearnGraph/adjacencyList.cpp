#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(vector<int> &ans, vector<bool> &visited, vector<int> adj[],
             int curr) {
        visited[curr] = true;

        ans.push_back(curr);

        for (int elem : adj[curr]) {
            if (!visited[elem])
                dfs(ans, visited, adj, elem);
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<bool> visited(V, false);
        dfs(ans, visited, adj, 0);
        return ans;
    }
};

int main() {

    Solution sol;
    int v = 5;

    vector<int> adj[v] = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

    vector<int> ans = sol.dfsOfGraph(v, adj);

    for (int val : ans) {
        cout << val << " ";
    }

    return 0;
}