#include <bits/stdc++.h>

// #include "UTILS/helper.h"
using namespace std;

// top down approach

typedef long long ll;

const int MOD = 1'000'000'007;

vector<ll> dp;

/*

 vector<int> dp(amount + 1, 0);

  dp[0] = 1;

  for (int i = 1; i <= amount; i++) {
    for (int &coin : coins) {
      int rem = i - coin;
      if (rem >= 0) {
        dp[i] = dp[i] + dp[i - coin];
      }
    }
  }


*/

int diceSumWays(int n) {
  if (n < 0)
    return 0;
  if (n <= 1)
    return 1;

  if (dp[n] != -1)
    return dp[n];

  ll ways = 0;
  for (int i = 1; i <= 6; i++) {
    ways = (ways + diceSumWays(n - i)) % MOD;
  }

  return dp[n] = ways % MOD;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int n;
  cin >> n;

  dp.resize(n + 1, -1);

  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;

  int res = diceSumWays(n);

  cout << res << endl;

  return 0;
}