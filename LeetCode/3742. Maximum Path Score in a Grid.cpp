#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxPathScore(vector<vector<int>>& grid, int k) {
    unordered_map<int, int> cost_mp = {{0, 0}, {1, 1}, {2, 1}};

    int m = grid.size();
    int n = grid[0].size();

    // dp[i][j][c] = max score reaching (i,j) with cost c
    vector<vector<vector<int>>> dp(
        m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

    int start_cost = cost_mp[grid[0][0]];
    if (start_cost <= k) {
      dp[0][0][start_cost] = grid[0][0];
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int c = 0; c <= k; c++) {
          if (dp[i][j][c] == -1)
            continue;

          int curr_score = dp[i][j][c];

          // move right
          if (j + 1 < n) {
            int val = grid[i][j + 1];
            int new_cost = c + cost_mp[val];
            if (new_cost <= k) {
              dp[i][j + 1][new_cost] =
                  max(dp[i][j + 1][new_cost], curr_score + val);
            }
          }

          // move down
          if (i + 1 < m) {
            int val = grid[i + 1][j];
            int new_cost = c + cost_mp[val];
            if (new_cost <= k) {
              dp[i + 1][j][new_cost] =
                  max(dp[i + 1][j][new_cost], curr_score + val);
            }
          }
        }
      }
    }

    int ans = -1;
    for (int c = 0; c <= k; c++) {
      ans = max(ans, dp[m - 1][n - 1][c]);
    }

    return ans;
  }
};