#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

// 1277. Count Square Submatrices with All Ones

class Solution {
 public:
  int countSquares(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int ans = 0;

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (mat[i][j]) {
          mat[i][j] = 1 + min({mat[i - 1][j], mat[i - 1][j - 1],
                               mat[i][j - 1]});
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans += mat[i][j];
      }
    }

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  string line;
  getline(cin, line);

  vector<vector<int>> mat = parse2DVector<int>(line);

  print2DVector(mat);

  cout << "Solution started ...." << endl;
  int ans = sol.countSquares(mat);

  cout << "ans : " << ans << endl;

  return 0;
}