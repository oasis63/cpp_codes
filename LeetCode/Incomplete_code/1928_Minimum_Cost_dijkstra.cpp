#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

// dijkstra
class Solution {
 public:
  int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
    // node and edge time

    int n = passingFees.size();

    bug(n);

    // dp --> cost to reach the node n
    // minimizing the cost , second value will contain the min time to reach there
    vector<pair<int, int>> dp(n, {INT_MAX, INT_MAX});

    // staring from 0

    dp[0] = {passingFees[0], 0};

    map<int, vector<tuple<int, int>>> adj;

    int ans = 0;

    for (auto e : edges) {
      int start_node = e[0];
      int end_node = e[1];
      int edge_time = e[2];

      adj[start_node].push_back({end_node, edge_time});
    }

    cout << "Adjacency List : " << endl;
    int node_value, edge_time;

    for (const auto& [u, v] : adj) {
      cout << "u : " << u << " : ";
      cout << v.size() << endl;
      for (const auto& t : v) {
        tie(node_value, edge_time) = t;
        cout << "node_value : " << node_value << " edge_time : " << edge_time << endl;
      }
    }

    // keeping less cost in the top
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        minHeap;

    // reach_time, node_value
    minHeap.push({0, 0});

    while (!minHeap.empty()) {
      auto [time, curr_node] = minHeap.top();
      bug(time, curr_node);
      minHeap.pop();

      vector<tuple<int, int>> vn = adj[curr_node];

      for (auto& nn : vn) {
        // we are trying to reach node_value from curr_node

        tie(node_value, edge_time) = nn;

        int new_node_reach_time = dp[curr_node].second + edge_time;
        int new_node_reach_cost = dp[curr_node].first + passingFees[node_value];

        bug(new_node_reach_cost, new_node_reach_time);

        if (new_node_reach_time <= maxTime) {
          // if cost is less to reach the node
          // then update
          if (new_node_reach_cost < dp[node_value].first) {
            dp[node_value] = {new_node_reach_cost, new_node_reach_time};
          }

          // if the cost is same
          // then update only if the reach time is lesser
          if (new_node_reach_cost == dp[node_value].first) {
            if (new_node_reach_time < dp[node_value].second) {
              dp[node_value] = {new_node_reach_cost, new_node_reach_time};
            }
          }

          minHeap.push({dp[node_value].second, node_value});
        }

        // if ((start_time + 1) < dp[node_value]) {
        //   dp[node_value] = start_time + 1;
        //   minHeap.push({dp[node_value], node_value});
        // }
      }
    }

    cout << "printing the final dp" << endl;

    for (const auto& p : dp) {
      cout << p.first << "  " << p.second << endl;
    }

    return dp[n - 1].second <= maxTime ? dp[n - 1].first : -1;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  Solution sol;

  int maxTime;
  cin >> maxTime;
  cin.ignore();

  bug(maxTime);

  string line;
  getline(cin, line);

  bug(line);

  vector<vector<int>> edges = parse2DVector<int>(line);

  print2DVector(edges);

  getline(cin, line);
  bug(line);
  vector<int> passingFees = parseVector<int>(line);

  printVect(passingFees);

  cout << "Solution started ...." << endl;
  int ans = sol.minCost(maxTime, edges, passingFees);

  cout << "ans : " << ans << endl;

  return 0;
}
