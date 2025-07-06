#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

#define ll long long

class Solution {
 public:
  long long minCost(int m, int n, vector<vector<int>>& waitCost) {
    long long ans = 0L;

    vector<vector<ll>> mat(m, vector<ll>(n, 0));

    // fill the matrix with their entry fees

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        mat[i][j] = (i + 1) * (j + 1);
      }
    }

    print2DVector(mat);

    int seconds = 1;

    // first row
    // 1s lapsed since we have already moved out of 0,0 cell
    for (int j = 1; j < n; j++) {
      int cost = mat[0][j - 1];
      // wait time , as we are moving to mat[i][j] cell at even seconds

      if (j != 1) {
        cost += waitCost[0][j - 1];
      }

      // if (seconds % 2 == 0) {
      //   cost += waitCost[0][j - 1];
      // }

      mat[0][j] += cost;
      seconds++;
    }

    // reset the column for vertical direction
    seconds = 1;
    // first column
    // 1s lapsed since we have already moved out of 0,0 cell
    for (int i = 1; i < m; i++) {
      int cost = mat[i - 1][0];
      // wait time , as we are moving to mat[i][j] cell at even seconds

      if (i != 1) {
        cost += waitCost[i - 1][0];
      }

      // if (seconds % 2 == 0) {
      //   cost += waitCost[i - 1][0];
      // }

      mat[i][0] += cost;
      seconds++;
    }

    cout << "\nMat after updating first row and first column fees : " << endl;
    print2DVector(mat);

    // now start at the third cell with time as 3s

    seconds = 2;

    for (int i = 1; i < m; i++) {
      int prev_seconds = seconds;
      for (int j = 1; j < n; j++) {
        // if ((seconds & 1) == 0) {
        // if (seconds % 2 == 0) {
        //   mat[i][j] += min(mat[i - 1][j] + waitCost[i - 1][j], mat[i][j - 1] + waitCost[i][j - 1]);
        // } else {
        //   mat[i][j] += min(mat[i - 1][j], mat[i][j - 1]);
        // }

        mat[i][j] += min(mat[i - 1][j] + waitCost[i - 1][j], mat[i][j - 1] + waitCost[i][j - 1]);

        seconds++;
      }
      seconds = prev_seconds + 1;
    }

    cout << "\nMat after updating all the values fees : " << endl;
    print2DVector(mat);

    return mat[m - 1][n - 1];
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;
  int m, n;
  cin >> m >> n;
  cin.ignore();

  // bug(m, n);

  vector<vector<int>> waitCost;

  for (int i = 0; i < m; i++) {
    cin.ignore();

    string line;
    getline(cin, line);

    // bug(line);

    vector<int> nums = parseIntVector(line);
    waitCost.push_back(nums);
  }

  // cout << "WaitCost " << endl;
  // print2DVector(waitCost);

  long long ans = sol.minCost(m, n, waitCost);

  cout << "ans : " << ans << endl;

  return 0;
}