#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

/*
Kid1 :
  (i + 1, j + 1), (i + 1, j), and (i, j + 1)

Kid2 :
  (i + 1, j - 1), (i + 1, j), and (i + 1, j + 1)

Kid3:
   (i - 1, j + 1), (i, j + 1), and (i + 1, j + 1)

*/

class Solution {
 public:
  int maxCollectedFruits(vector<vector<int>>& fruits) {
    int n = fruits.size();
    int mx_fruits = 0;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    dp[0][0] = fruits[0][0];

    int corner1 = fruits[0][0];
    int corner2 = fruits[0][n - 1];
    int corner3 = fruits[n - 1][0];

    fruits[0][0] = INT_MIN;
    fruits[0][n - 1] = INT_MIN;
    fruits[n - 1][0] = INT_MIN;

    // testing the flow for now

    fruits[1][2] = INT_MAX;
    fruits[2][1] = INT_MAX;
    fruits[2][3] = INT_MAX;
    fruits[3][2] = INT_MAX;

    // first row
    for (int j = 1; j < n; j++) {
      dp[0][j] = dp[0][j - 1] + fruits[0][j];
    }

    // first column
    for (int i = 1; i < n; i++) {
      dp[i][0] = dp[i - 1][0] + fruits[i][0];
    }

    dp[0][1] = dp[0][0] + fruits[0][1];
    dp[1][0] = dp[0][0] + fruits[1][0];

    dp[1][1] = dp[0][0] + fruits[1][1];

    print2DVector(dp);

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < n; j++) {
        // room is not accessible

        // skipping the first 3 corners

        if ((i == 1 && j == 1) || (i == 0 && j == 1) || (i == 1 && j == 0)) {
          continue;
        }

        if (fruits[i][j] != INT_MIN) {
          dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + fruits[i][j];
        }
      }
    }

    print2DVector(dp);

    return mx_fruits;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  vector<vector<int>> fruits;
  int n = 4;

  while (n--) {
    string line;
    getline(cin, line);

    vector<int> nums = parseVector<int>(line);
    fruits.push_back(nums);
  }

  print2DVector(fruits);

  cout << "Solution started ...." << endl;
  int ans = sol.maxCollectedFruits(fruits);

  cout << "ans : " << ans << endl;

  return 0;
}