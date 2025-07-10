#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();

    // state contains the dp[i][j] .. max palindrome from index i to j ,

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
      // every character is a subsequence
      dp[i][i] = 1;
    }

    // if characters matches
    // include both the characters 2 + dp[i+1][j-1]
    // or
    // two conditions get the maximum value by excluding the characters at i
    // or j

    // since we have already calculated for len 1

    for (int len = 2; len <= n; len++) {
      cout << "len : " << len << endl;
      // left pointer   .. from the start of the string
      // right pointer .. from the end of the string
      for (int i = 0; i <= n - len; i++) {
        int j = i + len - 1;

        cout << "\ti: " << i << " j : " << j << endl;

        if (s[i] == s[j]) {
          // include both the characters
          dp[i][j] = 2 + dp[i + 1][j - 1];
          // storing the value and updating the
        } else {
          // get the maximum value by either excluding first or last char
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }

    // cout << "\n-- dp -----" << endl;
    // print2DVector(dp);

    return dp[0][n - 1];
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

  int ll = sol.longestPalindromeSubseq(line);

  cout << "Longest palindromic length : " << ll << endl;

  return 0;
}