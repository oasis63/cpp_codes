#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print2DVector(const vector<vector<T>> &matrix) {
  for (const auto &row : matrix) {
    for (const T &item : row) {
      cout << item << " ";
    }
    cout << endl;
  }
  cout << "--------------------" << endl;
}

class Solution {
 public:
  // states , node_value
  // this state contains the maximum path on
  vector<int> dp;

  int topDown(int vertice, unordered_map<int, vector<int>> &adj) {
    if (adj.count(vertice) == 0) {
      return 0;
    }

    if (dp[vertice] != -1) {
      return dp[vertice];
    }

    int result = 0;

    for (int node : adj[vertice]) {
      int res = topDown(node, adj);

      if (res >= 0)
        result = max(result, res + 1);
    }

    dp[vertice] = result;
    return dp[vertice];
  }

  int findLongestPath(int n, int m, vector<vector<int>> &edges) {
    int longest_path = 0;

    dp.resize(n + 1, -1);

    unordered_map<int, vector<int>> adj;

    for (auto edge : edges) {
      adj[edge[0]].push_back(edge[1]);
    }

    // start from one node and reach all the possible nodes if edges are present
    for (int i = 1; i <= n; i++) {
      if (adj.count(i)) {
        int res = topDown(i, adj);
        longest_path = max(res, longest_path);
      }
    }

    return longest_path;
  }
};

int main() {
  // n = nodes,
  // m = edges

  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges;
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    edges.push_back({u, v});
  }

  // int n = 4, m = 5;
  // vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 2}, {2, 4}, {3, 4}};

  Solution sol;

  int longest_path = sol.findLongestPath(n, m, edges);

  cout << longest_path << endl;

  // print the edges

  // for (int i = 0; i < sol.dp.size(); i++) {
  //   cout << i << "  -----> " << sol.dp[i] << endl;
  // }

  return 0;
}