#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int ans = 0;

    int n = matrix.size();
    int m = matrix[0].size();

    vvi dp(n, vi(m, 0));

    int mx_size = min(n, m);

    // for (int side = 1; side <= mx_size; side++) {
    //   for (int i = 0; i <= (i + side - 1) && i < n; i++) {
    //     for (int j = 0; j <= (j + side - 1) && j < m; j++) {
    //     }
    //   }
    // }

    for (int side = 1; side <= mx_size; side++) {
      cout << "\tside : " << side << endl;
      for (int i = 0; i < (n - side); i++) {
        for (int j = 0; j < (m - side); j++) {
          bug(i, j);
        }
      }
    }

    return ans;
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

  print2DVector(mat);

  // bug(mat.size());
  // bug(mat[0].size());

  // int ans = sol.maximalSquare(mat);

  // cout << "ans : " << ans << endl;

  return 0;
}