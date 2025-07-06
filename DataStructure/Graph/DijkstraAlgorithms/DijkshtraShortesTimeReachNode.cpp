#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  // Dijkstra Algorithm
  int minTime(int n, vector<vector<int>>& edges) {
    if (n == 1)
      return 0;

    map<int, vector<tuple<int, int, int>>> mp;
    for (vector<int> edge : edges) {
      int start_node = edge[0];
      int end_node = edge[1];
      int edge_start_time = edge[2];
      int edge_end_time = edge[3];

      mp[start_node].push_back(
          {end_node, edge_start_time, edge_end_time});
    }

    if (mp.count(0) == 0)
      return -1;

    // dp is the reaching time
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;  // time to reach node 0 , is 0

    // keeping less time in the top
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        minHeap;

    // reach_time, node_value
    minHeap.push({0, 0});

    while (!minHeap.empty()) {
      auto [time, curr_node] = minHeap.top();
      minHeap.pop();

      vector<tuple<int, int, int>> vn = mp[curr_node];

      for (auto& nn : vn) {
        // we are trying to reach node_value from curr_node

        int node_value, edge_start_time, edge_end_time;

        tie(node_value, edge_start_time, edge_end_time) = nn;

        if (time <= edge_end_time) {
          int start_time = edge_start_time;
          if (time > edge_start_time) {
            start_time = time;
          }

          if ((start_time + 1) < dp[node_value]) {
            dp[node_value] = start_time + 1;
            minHeap.push({dp[node_value], node_value});
          }
        }
      }

      // for (auto& [weight, v] : adj[u]) {
      //   if (dist[v] > currDist + weight) {
      //     dist[v] = currDist + weight;
      //     minHeap.push({dist[v], v});
      //   }
      // }
    }
    int ans = dp[n - 1];
    return ans == INT_MAX ? -1 : ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;

  // int n = 3;
  // vector<vector<int>> edges = {{0, 1, 0, 1}, {1, 2, 2, 5}};

  int n;

  cin >> n;
  cin.ignore();

  string line;
  getline(cin, line);
  cin.ignore();

  vector<vector<int>> edges = parse2dVectorInput(line);

  // print2DVector(edges);

  int ans = sol.minTime(n, edges);

  cout << "ans : " << ans << endl;

  return 0;
}