#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class NextNode {
 public:
  int node_value;
  int start_time;
  int end_time;
};

class Solution {
 public:
  int reachTime(int curr_node, int time, int n,
                unordered_map<int, vector<NextNode>>& mp, vector<int>& dp) {
    // final case
    if (curr_node == n - 1) {
      return time;
    }

    // return memoized value at the curr_node
    // like already visited node
    // if (dp[curr_node] != INT_MAX) {
    //   cout << "hiiiit" << endl;
    //   return dp[curr_node];
    // }

    int result = INT_MAX;

    vector<NextNode> vn = mp[curr_node];

    for (NextNode nn : vn) {
      int node_value = nn.node_value;
      int edge_start_time = nn.start_time;
      int edge_end_time = nn.end_time;

      if (time <= edge_end_time) {
        int start_time = edge_start_time;
        if (time > edge_start_time) {
          start_time = time;
        }

        int res = reachTime(node_value, start_time + 1, n, mp, dp);

        result = min(result, res);
      }
    }
    // bug(curr_node, result);
    return dp[curr_node] = result;
  }

  int minTime(int n, vector<vector<int>>& edges) {
    if (n == 1)
      return 0;

    unordered_map<int, vector<NextNode>> mp;

    vector<int> dp(n, INT_MAX);
    // dp[0] = 0;

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

    int ans = reachTime(0, 0, n, mp, dp);

    // printVect(dp);

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