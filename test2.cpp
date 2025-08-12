#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  const int MOD = 1000000007;

  int modular_expo(int base, int exp) {
    long long res = 1;

    while (exp > 0) {
      if (exp % 2 == 1) {
        res = (res * base) % MOD;
      }
      base = (base * base) % MOD;
      exp /= 2;
    }

    return res;
  }

  unordered_set<string> paths;
  // int ans = 0;

  int find_ways(int amount, vector<long long>& coins, int ind, int n,
                vector<int>& dp, string path) {
    bug(amount, ind);
    if (amount == 0) {
      cout << path << endl;
      if (paths.insert(path).second) {
        // ans++;
        return 1;
      } else
        return 0;
    }
    if (ind >= n)
      return 0;
    if (amount < 0)
      return 0;

    if (dp[amount] != -1)
      return dp[amount];

    int take = find_ways(amount - coins[ind], coins, ind + 1, n, dp,
                         path + "/" + to_string(coins[ind]));

    int donot_take = find_ways(amount, coins, ind + 1, n, dp, path);

    return dp[amount] = (take + donot_take) % MOD;
  }

  int numberOfWays(int total, int x) {
    int amount = total;

    vector<long long> coins;

    for (int i = 1; i <= total; i++) {
      if (x == 1) {
        coins.push_back(i);
      } else {
        long long res = modular_expo(i, x);
        if (res <= total) {
          coins.push_back(res);
        } else {
          break;
        }
      }
    }

    int n = coins.size();

    printVector(coins);

    vector<int> dp(amount + 1, -1);
    dp[0] = 1;
    dp[1] = 1;

    int res = find_ways(amount, coins, 0, n, dp, "");

    printVectorWithIndices(dp);

    return res;
    // return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  int n, x;
  cin >> n >> x;

  cout << "Solution started ...." << endl;
  int ans = sol.numberOfWays(n, x);

  cout << "ans : " << ans << endl;

  return 0;
}