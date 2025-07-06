#include <bits/stdc++.h>

// #include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  // using 0-index vector
  bool solve(vector<vector<int>> &mat, int curr_i, int curr_j, int n, int m) {
    if (curr_i >= n || curr_j >= m || curr_i < 0 || curr_j < 0) {
      return false;
    }

    // we have reached to the bottom-right corner
    if (curr_i == n - 1 && curr_j == m - 1) {
      return true;
    }

    // we have either visited this cell or it has a obstacle
    if (mat[curr_i][curr_j] != 0) {
      return false;
    }
    // mark this cell as visited
    mat[curr_i][curr_j] = 1;

    // for this current cell we can go in 4-directions

    bool res_top = solve(mat, curr_i - 1, curr_j, n, m);

    if (res_top) return true;

    bool res_bottom = solve(mat, curr_i + 1, curr_j, n, m);

    if (res_bottom) return true;

    bool res_left = solve(mat, curr_i, curr_j - 1, n, m);

    if (res_left) return true;

    bool res_right = solve(mat, curr_i, curr_j + 1, n, m);

    if (res_right) return true;

    return false;

    /*  TODO:
    check if we have to do backtracking,
    by resetting the current  cell

    */
  }

  // possible to reach to  bottom-right corner from top-left corner
  bool isPossible(vector<vector<int>> &mat, int n, int m) {
    bool res = solve(mat, 0, 0, n, m);

    // bug(res);

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n, m, k, oi, oj;
  cin >> n >> m >> k;
  cin.ignore();

  // it will act as visited
  vector<vector<int>> mat(n, vector<int>(m, 0));

  // obstacle == -1

  Solution sol;

  for (int i = 0; i < k; i++) {
    cin >> oi >> oj;
    cin.ignore();
    mat[oi - 1][oj - 1] = -1;
  }

  // print2DVector(mat);

  int res = sol.isPossible(mat, n, m);
  cout << res << endl;

  return 0;
}