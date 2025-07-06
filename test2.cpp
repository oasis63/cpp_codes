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

  string line;
  getline(cin, line);

  vector<int> nums = parseIntVector(line);

  printVect(nums);

  int ans = sol.solve(nums);

  cout << "ans : " << ans << endl;

  return 0;
}