#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

// Determine if you are able to reach the last index.

class Solution {
 public:
  int canJump(vector<int> &A) {
    int n = A.size();
    int mxReach = 0;
    for (int i = 0; i < n; i++) {
      if (mxReach < i) {
        bug(mxReach, i);
        return 0;
      }
      mxReach = max(mxReach, i + A[i]);
    }
    return 1;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  string line;
  getline(cin, line);

  vector<int> nums = parseVector<int>(line);

  printVect(nums);

  cout << "Solution started ...." << endl;
  int ans = sol.canJump(nums);

  cout << "ans : " << ans << endl;

  return 0;
}