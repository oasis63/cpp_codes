/*
"ॐ नमः पार्वती पतये, हर हर महादेव।" 🔱🙏
*/

#include <bits/stdc++.h>
using namespace std;

/*
Coin change problem using dp
and this is similar to minimum jumps to reach to the end
*/

// using top down approach ( recursion + memoization )

int solve(vector<int> &coins, vector<int> &dp, int amount) {
  // 0 ways to gather amount 0
  if (amount == 0) {
    return 0;
  }

  if (amount < 0) return INT_MAX;

  // memoized value
  if (dp[amount] != -1) return dp[amount];

  // now calculate the recursive

  int minCoins = INT_MAX;

  for (int coin : coins) {
    int subproblem = solve(coins, dp, amount - coin);
    if (subproblem != INT_MAX) {
      minCoins = min(minCoins, subproblem + 1);
    }
  }

  return dp[amount] = minCoins;
}

int coinChange(vector<int> &coins, int amount) {
  vector<int> dp(amount + 1, -1);

  return solve(coins, dp, amount);
}

int main() {
  vector<int> coins = {1, 2, 5};
  int amount = 11;
  cout << "Minimum coins required: " << coinChange(coins, amount) << endl;

  return 0;
}