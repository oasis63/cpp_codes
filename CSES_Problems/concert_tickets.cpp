#include <bits/stdc++.h>

// #include "UTILS/helper.h"
using namespace std;

// O(n*m)
void solution1(int n, int m) {
  int b;
  vector<int> prices(n, 0);

  for (int &p : prices) {
    cin >> p;
  }

  sort(prices.begin(), prices.end());
  // printVect(prices);

  while (m--) {
    cin >> b;

    auto it = upper_bound(prices.begin(), prices.end(), b);

    if (it == prices.begin()) {
      cout << -1 << "\n";
    } else {
      --it;
      cout << *it << "\n";
      prices.erase(it);
    }
  }
}

// O((n + m) log n)
void solution2(int n, int m) {
  int b, t;

  multiset<int> tickets;

  for (int i = 0; i < n; i++) {
    cin >> t;
    tickets.insert(t);
  }

  while (m--) {
    cin >> b;

    auto it = tickets.upper_bound(b);
    if (it == tickets.begin()) {
      cout << -1 << "\n";
    } else {
      --it;
      cout << *it << "\n";
      tickets.erase(it);  // logN
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int n, m;
  cin >> n >> m;
  cin.ignore();

  // solution1(n, m);

  solution2(n, m);

  return 0;
}