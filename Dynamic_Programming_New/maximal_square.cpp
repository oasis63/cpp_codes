#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    int mx_side = 0;

    for (int i = 0; i < n; i++) {
      if (matrix[i][0] == '1') {
        dp[i][0] = 1;
        mx_side = 1;
      }
    }

    for (int j = 0; j < m; j++) {
      if (matrix[0][j] == '1') {
        dp[0][j] = 1;
        mx_side = 1;
      }
    }

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (matrix[i][j] == '1') {
          dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
        }
        mx_side = max(mx_side, dp[i][j]);
      }
    }

    bug(mx_side);
    print2DVector(dp);

    return mx_side * mx_side;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;

  string line;
  getline(cin, line);

  bug(line);

  vector<vector<char>> mat = parse2DVector<char>(line);

  bug(mat.size());
  bug(mat[0].size());

  print2DVector(mat);

  int ans = sol.maximalSquare(mat);

  cout << "ans : " << ans << endl;

  return 0;
}