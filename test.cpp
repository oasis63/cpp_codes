#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  int solve(vector<int> &vect) {
    int ans = 0;

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;
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

  cout << "Weights : " << "Values " << endl;

  for (pair<int, int> pr : items) {
    cout << pr.first << " " << pr.second << endl;
  }

  return 0;
}