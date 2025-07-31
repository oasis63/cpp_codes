#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  void divideInGroups(vector<int>& nums, int ind, int n, int k, vector<vector<int>>& groups, vector<int> vect) {
    if (ind >= n) {
      groups.push_back(vect);
      return;
    }

    for (int grp_count = 0; grp_count < k; grp_count++) {
      // exclude
      divideInGroups(nums, ind + 1, n, k, groups, vect);

      // include
      vect.push_back(nums[ind]);
      divideInGroups(nums, ind + 1, n, k, groups, vect);
      vect.pop_back();
    }
  }

  double largestSumOfAverages(vector<int>& nums, int k) {
    double mx_sum = 0.0;

    // divide into k groups

    vector<vector<int>> groups;
    vector<int> vect;

    int n = nums.size();

    divideInGroups(nums, 0, n, k, groups, vect);

    print2DVector<int>(groups);

    cout << fixed;
    cout << setprecision(6);
    return mx_sum;
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

  int k;
  cin >> k;

  printVect(nums);
  bug(k);

  cout << "Solution started ...." << endl;
  double ans = sol.largestSumOfAverages(nums, k);

  cout << "ans : " << ans << endl;

  return 0;
}