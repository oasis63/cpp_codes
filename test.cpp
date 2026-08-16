#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  // process a sub-grid of dimension kxk

  int subGrid(vector<vector<int>>& grid, int s_i, int s_j, int& k, int& row,
              int& col) {
    vector<int> elems;

    set<int> seen;

    for (int i = s_i; i < (s_i + k) && i < row; i++) {
      for (int j = s_j; j < (s_j + k) && j < col; j++) {
        int elem = grid[i][j];

        // not seen
        if (seen.find(elem) == seen.end()) {
          seen.insert(elem);
          elems.push_back(elem);
        }
      }
    }

    int sz = elems.size();

    // sort elements
    sort(elems.begin(), elems.end());

    int min_diff = INT_MAX;

    // check adjacent differences
    for (int i = 1; i < sz; i++) {
      min_diff = min(min_diff, elems[i] - elems[i - 1]);
    }

    return min_diff == INT_MAX ? 0 : min_diff;
  }

  vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>> ans(row - k + 1);

    // create sub-grids of size ( k x k)
    // for every cell int the grid, create a sub-grid

    for (int i = 0; i <= (row - k); i++) {
      for (int j = 0; j <= (col - k); j++) {
        int diff = subGrid(grid, i, j, k, row, col);
        ans[i].push_back(diff);
      }
    }

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cout << "\nSolution started ---- " << endl;

  vector<int> vect;

  // set_io_files("input.txt", "output.txt");

  // Solution sol;

  // string line;
  // getline(cin, line);

  // vector<vector<int>> nums = parse2DVector<int>(line);

  // print2DVector(nums);

  // getline(cin, line);

  // int k = stoi(line);

  // bug(k);

  // cout << "\nSolution started ---- " << endl;
  // vector<vector<int>> ans = sol.minAbsDiff(nums, k);

  // bug("ans");
  // print2DVector(ans);

  return 0;
}
