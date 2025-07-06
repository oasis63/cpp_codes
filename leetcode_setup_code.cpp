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
  int maxProfit(vector<int>& prices) {
    // brute force
    vector<int> profits;
    int n = prices.size();

    for (int i = 0; i < n; i++) {
      int mx_pro = 0;
      for (int j = i + 1; j < n; j++) {
        if (prices[j] > prices[i]) {
          mx_pro = max(mx_pro, prices[j] - prices[i]);
        }
      }
      profits.push_back(mx_pro);
    }

    sort(profits.rbegin(), profits.rend());

    return profits[0] + profits[1];
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

  vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

  int res = sol.maxProfit(prices);

  cout << "MaxProfit : " << res << endl;

  //   int n, k;
  //   cin >> n >> k;
  //   vector<int> vect(n, 0);
  //   for (int i = 0; i < n; i++) {
  //     cin >> vect[i];
  //   }

  // cost of reaching ith index
  //   vector<int> dp(n, INT_MAX);
  //   dp[0] = 0;

  //   int res = sol.solve(n, k, vect, dp, n - 1);

  //   cout << res << endl;

  return 0;
}