#include <bits/stdc++.h>
// #include "UTILS/helper.h"
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define ll long long

int main() {
  fast;
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int n, k;
  cin >> n >> k;
  cin.ignore();

  vector<int> weights(n);

  for (int &r : weights) {
    cin >> r;
  }

  sort(weights.begin(), weights.end());
  // printVect(weights);

  int ans = 0;

  int sz = weights.size();
  int left = 0, right = sz - 1;

  while (left <= right) {
    int sum = weights[left] + weights[right];

    if (sum <= k) {
      left++;
      right--;
      ans++;
    } else if (sum > k) {
      right--;
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}