#include <bits/stdc++.h>

// #include "UTILS/helper.h"

using namespace std;

const int MOD = 1'000'000'007;

/*

Type	Outer Loop	Inner Loop
Permutations	Amount	Coins
Combinations	Coins	Amount

*/

class Solution {
 public:
  //  order  matter
  int countCoinsPermutations(vector<int> &coins, int n, int amount) {
    vector<int> dp(amount + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= amount; i++) {
      for (int &coin : coins) {
        int rem = i - coin;
        if (rem >= 0) {
          dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
      }
    }

    return dp[amount];
  }
  //  order does not matter
  int countCoinsCombinations(vector<int> &coins, int n, int amount) {
    vector<int> dp(amount + 1, 0);

    dp[0] = 1;

    for (int &coin : coins) {
      for (int i = coin; i <= amount; i++) {
        dp[i] = (dp[i] + dp[i - coin]) % MOD;
      }
    }

    return dp[amount];
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

  // int ans = sol.countCoinsPermutations(coins, n, x);
  // cout << ans << endl;

  int ans1 = sol.countCoinsCombinations(coins, n, x);

  cout << ans1 << endl;
  return 0;
}