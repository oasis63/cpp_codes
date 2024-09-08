// task is to find the number of ways to reach from start to destination

class Solution {
  public:
    int solveUtil(vector<vector<int>> &adj, int curr, int src, int dest,
                  vector<bool> &visited) {

        if (curr == dest) {
            return 1;
        }

        int nCurr = curr == -1 ? src : curr;

        visited[nCurr] = true;
        int ans = 0;

        for (int val : adj[nCurr]) {
            if (!visited[val]) {
                ans += solveUtil(adj, val, src, dest, visited);
            }
        }

        visited[nCurr] = false;
        return ans;
    }

    int possible_paths(vector<vector<int>> edges, int n, int src, int dest) {
        vector<vector<int>> adj(n);

        for (const auto pr : edges) {
            adj[pr[0]].push_back(pr[1]);
        }

        vector<bool> visited(n, false);

        return solveUtil(adj, src, src, dest, visited);
        ;
    }
};