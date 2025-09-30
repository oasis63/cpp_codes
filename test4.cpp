#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  bool check(int i, int j, int m, int n) {
    if (i < 0 || i >= m)
      return false;
    if (j < 0 || j >= n)
      return false;

    return true;
  }

  int countNeighbours(vector<vector<int>>& board, int x, int y) {
    int m = board.size();
    int n = board[0].size();

    int count = 0;

    vector<vector<int>> steps = {{-1, -1}, {+1, +1}, {-1, 1}, {1, -1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (vector<int>& step : steps) {
      int i = x + step[0];
      int j = y + step[1];

      if (check(i, j, m, n) && board[i][j]) {
        count++;
      }
    }

    return count;
  }

  void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int neighbours = countNeighbours(board, i, j);

        // cout << neighbours << "  ";

        if (board[i][j]) {
          if (neighbours < 2 || neighbours > 3) {
            board[i][j] = 0;
          } else {
            board[i][j] = 1;
          }

        } else if (neighbours == 3) {
          board[i][j] = 1;
        }
      }
      // cout << endl;
    }
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

  vector<vector<int>> nums = parse2DVector<int>(line);

  print2DVector(nums);

  cout << "Solution started ...." << endl;
  sol.gameOfLife(nums);

  cout << "\n updated nums " << endl;

  print2DVector(nums);

  return 0;
}