#include <bits/stdc++.h>

// #include "UTILS/helper.h"

using namespace std;

long knapsack2(vector<pair<int, int>> &items, int n, int w, int ind,
               vector<vector<long>> &dp) {
  if (ind >= n) return 0;

  if (dp[ind][w] != -1) return dp[ind][w];

  // leave the current index
  long ans = knapsack2(items, n, w, ind + 1, dp);

  // take it
  if ((w - items[ind].first) >= 0) {
    ans = max(ans, items[ind].second +
                       knapsack2(items, n, w - items[ind].first, ind + 1, dp));
  }

  return dp[ind][w] = ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  // Solution sol;

  int n, w;
  cin >> n >> w;
  cin.ignore();

  vector<vector<long>> dp(n + 1, vector<long>(w + 1, -1));

  // weight/ values
  vector<pair<int, int>> items;
  long vi, wi;

  for (int i = 0; i < n; i++) {
    cin >> wi >> vi;
    cin.ignore();
    items.push_back({wi, vi});
  }

  long res = knapsack2(items, n, w, 0, dp);

  cout << res << endl;

  return 0;
}