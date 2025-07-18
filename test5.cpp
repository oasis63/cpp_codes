#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

void test_case() {
  int n, k;
  cin >> n >> k;

  vector<pair<pair<int, int>, int>> vect;
  int a, b, c;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    vect.push_back({{a, b}, c});
  }

  sort(vect.begin(), vect.end());

  for (const auto &[P, t] : vect) {
    cout << P.first << "  " << P.second << "  " << t << endl;
  }

  int ans = k;
  for (int i = 0; i < n; i++) {
    pair<pair<int, int>, int> pr = vect[i];
    int l = pr.first.first;
    int r = pr.first.second;
    int t = pr.second;

    if (l <= ans && ans <= r) {
      ans = max(ans, t);
    }
  }
  cout << ans << endl;
  cout << "--------------------------------" << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t;
  cin >> t;
  while (t--) test_case();
  return 0;
}
