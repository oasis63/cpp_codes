#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size())
      return intersect(nums2, nums1);

    vector<int> ans;
    unordered_map<int, int> count;

    for (const int num : nums1)
      ++count[num];

    for (const int num : nums2)
      if (const auto it = count.find(num); it != count.cend() && it->second-- > 0)
        ans.push_back(num);

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
  int ans = sol.solve(nums);

  cout << "ans : " << ans << endl;

  return 0;
}