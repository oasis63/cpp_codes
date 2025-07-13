#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

class Solution {
 public:
  int solve(vector<vector<int>> &vect) {
    int ans = 0;

    int n = vect.size();
    int m = vect[0].size();

    vvi dp(n, vi(m, INT_MIN));

    dp[0][0] = 1;

    // fill first row
    for (int j = 1; j < m; j++) {
      if (vect[0][j] > vect[0][j - 1]) {
        dp[0][j] = dp[0][j - 1] + 1;
      } else {
        break;
      }
    }

    // fill first column
    for (int i = 1; i < n; i++) {
      if (vect[i][0] > vect[i - 1][0]) {
        dp[i][0] = dp[i - 1][0] + 1;
      } else {
        break;
      }
    }

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        int temp = INT_MIN;

        if (dp[i - 1][j] != INT_MIN && vect[i][j] > vect[i - 1][j]) {
          temp = dp[i - 1][j] + 1;
        }

        if (dp[i][j - 1] != INT_MIN && vect[i][j] > vect[i][j - 1]) {
          temp = max(dp[i][j - 1] + 1, temp);
        }
        dp[i][j] = temp;
      }
    }

    print2DVector(dp);

    return dp[n - 1][m - 1] == INT_MIN ? -1 : dp[n - 1][m - 1];
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;

  vector<vector<int>> vect = {{1, 2, 3, 4}, {2, 2, 3, 4}, {3, 2, 3, 4}, {4, 5, 6, 7}};

  print2DVector(vect);

  int ans = sol.solve(vect);

  cout << "ans : " << ans << endl;

  return 0;
}