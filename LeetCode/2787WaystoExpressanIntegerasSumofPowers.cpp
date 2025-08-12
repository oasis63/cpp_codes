#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

struct pair_hash {
  size_t operator()(const pair<int, int>& p) const {
    return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
  }
};

class Solution1 {
 public:
  const int MOD = 1000000007;

  // auto makeKey = [&](int a, int b) {
  //     return ((long long)a << 32) | (unsigned int)b;
  // };

  long long makeKey(int a, int b) {
    return ((long long)a << 32) | (unsigned int)b;
  }

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

  // unordered_map<pair<int, int>, int, pair_hash> mp_dp;
  // unordered_map<long long, int> mp_dp;

  // amount , index  --> number of ways

  int find_ways(int amount, vector<long long>& coins, int ind, int n,
                vector<vector<int>>& dp) {
    if (amount == 0) {
      return 1;
    }
    if (ind >= n)
      return 0;
    if (amount < 0)
      return 0;

    // if (mp_dp.count({amount, ind})) {
    //     return mp_dp[{amount, ind}];
    // }

    // if (mp_dp.count(makeKey(amount, ind))) {
    //   return mp_dp[makeKey(amount, ind)];
    // }

    if (dp[amount][ind] != -1) {
      return dp[amount][ind];
    }

    int take = find_ways(amount - coins[ind], coins, ind + 1, n, dp);
    int donot_take = find_ways(amount, coins, ind + 1, n, dp);

    int total_ways = (take + donot_take) % MOD;

    dp[amount][ind] = total_ways;
    // mp_dp[makeKey(amount, ind)] = total_ways;

    return total_ways;
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

    vector<vector<int>> dp(amount + 1, vector<int>(n + 1, -1));
    // dp[0] = 1;

    int res = find_ways(amount, coins, 0, n, dp);

    return res;
  }
};

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

  int find_ways(int amount, vector<long long>& coins, int ind, int n,
                vector<vector<int>>& dp) {
    if (amount == 0) {
      return 1;
    }
    if (ind >= n)
      return 0;
    if (amount < 0)
      return 0;

    if (dp[amount][ind] != -1) {
      return dp[amount][ind];
    }

    int take = find_ways(amount - coins[ind], coins, ind + 1, n, dp);
    int donot_take = find_ways(amount, coins, ind + 1, n, dp);

    int total_ways = (take + donot_take) % MOD;

    dp[amount][ind] = total_ways;

    return total_ways;
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

    vector<vector<int>> dp(amount + 1, vector<int>(n + 1, -1));

    int res = find_ways(amount, coins, 0, n, dp);

    return res;
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