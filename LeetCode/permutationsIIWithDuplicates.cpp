#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  void solve(vector<vector<int>>& ans, vector<int>& res, vector<bool> used,
             vector<int>& nums, int n) {
    if ((int)res.size() == n) {
      ans.push_back(res);
      return;
    }

    for (int i = 0; i < n; i++) {
      if (used[i])
        continue;

      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
        continue;

      used[i] = true;

      res.push_back(nums[i]);

      solve(ans, res, used, nums, n);

      res.pop_back();

      used[i] = false;
    }
  }
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> res;

    int n = nums.size();
    vector<bool> used(n, false);

    string params = "";
    unordered_set<string> tracker;

    sort(nums.begin(), nums.end());
    solve(ans, res, used, nums, n);
    return ans;
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
  vector<vector<int>> ans = sol.permuteUnique(nums);

  print2DVector(ans);

  return 0;
}