#include <bits/stdc++.h>
using namespace std;

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
  int solve(int n, int k, vector<int>& cost, vector<int>& dp, int ind) {
    if (ind < 0) return INT_MAX;

    if (ind == 0) {
      return dp[0] = 0;
    }

    if (dp[ind] != INT_MAX) return dp[ind];

    int total = INT_MAX;
    // total jumps

    for (int jump = 1; jump <= k; jump++) {
      int next_cell = ind - jump;
      int res = solve(n, k, cost, dp, next_cell);
      if (res != INT_MAX) {
        total = min(total, dp[next_cell] + abs(cost[ind] - cost[next_cell]));
      }
    }
    return dp[ind] = total;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  Solution sol;

  int n, k;
  cin >> n >> k;
  vector<int> vect(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> vect[i];
  }

  // int n = 4;
  // vector<int> vect = {10, 30, 40, 20};

  // cost of reaching ith index
  vector<int> dp(n, INT_MAX);
  dp[0] = 0;

  // bottom - up approach
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      int next_cell = i + j;
      // no need to go beyond
      if (next_cell >= n) break;

      dp[next_cell] =
          min(dp[next_cell], dp[i] + abs(vect[next_cell] - vect[i]));
    }
  }

  // top-down approach
  // int res = sol.solve(n, k, vect, dp, n - 1);

  // cout << res << endl;

  cout << dp[n - 1] << endl;

  // printVect(dp);

  return 0;
}

/*

10 4
40 10 20 70 80 10 20 70 80 60



*/