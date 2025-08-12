#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

#define MOD 1000000007

class Solution {
 public:
  //  number of ways to reach from top-corner to bottom corner
  // with cells having obstacle

  int countOfPathsInGrid(int n, int m, vector<vector<char>> &mat) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      if (mat[i][0] == '#') break;
      dp[i][0] = 1;
    }
    for (int j = 0; j < m; j++) {
      if (mat[0][j] == '#') break;
      dp[0][j] = 1;
    }

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (mat[i][j] != '#') {
          dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
      }
    }

    // bug(dp.size());
    // bug(dp[0].size());
    // print2DVector(dp);

    return dp[n - 1][m - 1];
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;

  int n, m;
  cin >> n >> m;
  cin.ignore();

  vector<vector<char>> mat;

  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);

    vector<char> row = parseCharVector(line);

    mat.push_back(row);
  }

  // print2DVector(mat);

  // bug(mat.size());
  // bug(mat[0].size());

  int ans = sol.countOfPathsInGrid(n, m, mat);
  cout << ans << endl;

  return 0;
}

/*

3 4
...#
.#..
....


ans : 3


*/