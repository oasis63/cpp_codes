#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/dp/tasks/dp_a

#define printVect(a)                 \
  for (auto x : a) cout << x << " "; \
  cout << endl
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}

class Solution {
 public:
  int solve(int n, vector<int>& cost, vector<int>& dp, int ind) {
    if (ind == 0) {
      return dp[0] = 0;
    } else if (ind == 1) {
      return dp[1] = abs(cost[0] - cost[1]);
    }

    if (dp[ind] != -1) return dp[ind];

    return dp[ind] = min(
               solve(n, cost, dp, ind - 1) + abs(cost[ind] - cost[ind - 1]),
               solve(n, cost, dp, ind - 2) + abs(cost[ind] - cost[ind - 2]));
  }
};

int main() {
  Solution sol;

  // int n = 2;
  // vector<int> cost = {10, 30, 40, 20};
  // vector<int> cost = {10, 10};
  vector<int> cost = {30, 10, 60, 10, 60, 50};
  int n = cost.size();
  vector<int> dp(n, -1);

  dp[0] = 0;

  // bottom-up approach
  // dp[1] = abs(cost[1] - cost[0]);

  // for (int i = 2; i < n; i++) {
  //   dp[i] = min(dp[i - 1] + abs(cost[i - 1] - cost[i]),
  //               dp[i - 2] + abs(cost[i - 2] - cost[i]));
  // }

  // top-down approach
  int res = sol.solve(n, cost, dp, n - 1);
  cout << "result : " << res << endl;

  printVect(dp);

  cout << dp[n - 1] << endl;

  return 0;
}