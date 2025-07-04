#include <bits/stdc++.h>

using namespace std;

int main() {
  string s = "axyb", t = "abyxb";

  cin >> s >> t;

  int n1 = s.length();
  int n2 = t.length();

  vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;

      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  // trace_back

  string temp = "";

  // reach 0,0 from n1,n2
  int m = n1, n = n2;
  while (n > 0 && m > 0) {
    if (s[m - 1] == t[n - 1]) {
      temp.push_back(s[m - 1]);
      // it has come from daigonal
      m--;
      n--;
    } else if (dp[m - 1][n] >
               dp[m][n - 1]) {  // since we are taking max value from corners
      // here checking which has mx value
      m--;
    } else {
      n--;
    }
  }

  reverse(temp.begin(), temp.end());

  cout << temp << endl;
  return 0;
}