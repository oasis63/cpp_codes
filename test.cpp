#include <bits/stdc++.h>

// #include "UTILS/helper.h"

using namespace std;

const int MOD = 1'000'000'007;

class Solution {
 public:
  int solve(vector<int> &coins, vector<int> &dp, int n, int amount) {
    if (amount < 0) {
      return 0;
    }

    // amount is 0,, can be got by not selecting any coins
    if (amount == 0) {
      return 1;
    }

    if (dp[amount] != -1) {
      return dp[amount];
    }

    int ways = 0;

    for (int coin : coins) {
      ways = (ways + solve(coins, dp, n, amount - coin)) % MOD;
    }

    return dp[amount] = ways;
  }

  int countCoins(vector<int> &coins, int n, int amount) {
    vector<int> dp(amount + 1, -1);

    int ans = solve(coins, dp, n, amount);

    return ans == INT_MAX ? -1 : ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  Solution sol;

  int n, x;
  cin >> n >> x;
  cin.ignore();

  vector<int> coins(n);

  for (auto &elem : coins) {
    cin >> elem;
  }

  int ans = sol.countCoins(coins, n, x);

  cout << ans << endl;
  return 0;
}