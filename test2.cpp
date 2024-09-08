#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void printGraph(vector<vector<int>> &adj, int v) {
        for (int i = 0; i < adj.size(); i++) {
            cout << i << ": "; // Print the vertex
            for (int j : adj[i]) {
                cout << j << " "; // Print its adjacent
            }
            cout << endl;
        }
    }

    void solveUtil(vector<vector<int>> &adj, int curr, int src, int dest,
                   vector<bool> &visited, int &ans) {

        if (curr == dest) {
            cout << "updated " << endl;
            ans++;
            return;
        }

        int nCurr = curr == -1 ? src : curr;

        visited[nCurr] = true;

        for (int val : adj[nCurr]) {
            if (!visited[val]) {
                solveUtil(adj, val, src, dest, visited, ans);
            }
        }

        // for (int i = 0; i < adj[src].size(); i++) {
        //     if (adj[src][i] && !visited[i]) {
        //         cout << "i : " << i << endl;
        //         solveUtil(adj, i, src, dest, visited, ans);
        //     }
        // }

        visited[nCurr] = false;
    }

    void solve(vector<vector<int>> &adj, int src, int dest, int &ans) {
        int v = adj.size();
        vector<bool> visited(v, false);
        visited[src] = true;

        cout << " src : " << src << endl;

        for (int val : adj[src]) {
            if (!visited[val]) {
                cout << "val : " << val << endl;
                solveUtil(adj, val, src, dest, visited, ans);
            }
        }

        // for (int i = 0; i < adj[src].size(); i++) {
        //     if (adj[src][i] && !visited[i]) {
        //         cout << "i : " << i << endl;
        //         solveUtil(adj, i, src, dest, visited, ans);
        //     }
        // }

        //  for (int val : adj[src]) {
        //     if (!visited[val]) {
        //         cout << "val : " << val << endl;
        //         solveUtil(adj, val, src, dest, visited, ans);
        //     }
        // }
    }

    int possible_paths(vector<vector<int>> edges, int n, int src, int dest) {
        // Code here
        // adj matrix
        // vector<vector<int>> adj(n, vector<int>(n, 0));

        // adj list

        vector<vector<int>> adj(n);

        for (const auto pr : edges) {
            // adj[pr[0]][pr[1]] = 1;
            adj[pr[0]].push_back(pr[1]);
        }

        printGraph(adj, n);

        int ans = 0;

        solve(adj, src, dest, ans);

        return ans;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> edges = {{0, 1}, {0, 3}, {0, 2},
                                 {2, 0}, {2, 1}, {1, 3}};
    int n = 4;
    int start = 0;
    int destination = 3;

    int res = sol.possible_paths(edges, n, start, destination);

    cout << "\n res : " << res << endl;

    return 0;
}