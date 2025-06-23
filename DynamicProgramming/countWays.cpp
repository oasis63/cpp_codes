#include <bits/stdc++.h>
using namespace std;

int rec(int n, int k) {
  if (n < 0) return 0;
  if (n == 0) return 1;

  // return rec(n - 1,k) + rec(n - 2,k) + rec(n - 3,k);

  int ans = 0;
  for (int i = 1; i <= k; i++) {
    ans += rec(n - i, k);
  }
  return ans;
}

// top-down
int tDp[1000] = {0};

int recTopDown(int n, int k) {
  if (n < 0) return 0;
  if (n <= 1) return 1;

  if (tDp[n] != 0) return tDp[n];

  int ans = 0;
  for (int i = 1; i <= k; i++) {
    ans += recTopDown(n - i, k);
  }
  return tDp[n] = ans;
}

int countWaysOpt(int n, int k) {
  vector<int> dp(n + 1, 0);
  dp[0] = dp[1] = 1;

  // filling the windows value
  for (int i = 2; i <= k; i++) {
    dp[i] = 2 * dp[i - 1];
  }

  for (int i = k + 1; i <= n; i++) {
    dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
  }

  return dp[n];
}

int main() {
  int n = 4, k = 3;
  // int n = 6, k = 3;

  cout << rec(n, k) << endl;

  cout << recTopDown(n, k) << endl;

  cout << countWaysOpt(n, k) << endl;

  return 0;
}
