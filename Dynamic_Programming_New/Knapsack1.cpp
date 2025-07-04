#include <bits/stdc++.h>

// #include "UTILS/helper.h"

using namespace std;

const int N = 100;

long memo[N][100001];

long knapsack(int n, int w, vector<pair<int, int>> &items, int index) {
  // bug(w, index);

  if (index >= n) return 0;

  if (memo[index][w] != -1) {
    return memo[index][w];
  }

  // do not take the item
  long ans = knapsack(n, w, items, index + 1);

  // take the item
  if ((w - items[index].first) >= 0) {
    ans = max(ans, items[index].second +
                       knapsack(n, w - items[index].first, items, index + 1));
  }

  return memo[index][w] = ans;
}

long solve(int n, int w, vector<pair<int, int>> &items) {
  memset(memo, -1, sizeof(memo));

  long total = knapsack(n, w, items, 0);
  return total;
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

  vector<pair<int, int>> items;  // weight, value
  int t1, t2;
  for (int i = 0; i < n; i++) {
    cin >> t1 >> t2;
    cin.ignore();
    items.push_back({t1, t2});
  }

  long res = solve(n, w, items);

  cout << res << endl;

  return 0;
}