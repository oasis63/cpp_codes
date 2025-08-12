// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> mp;  // sum, startingInde

    int sum = 0;
    int n = nums.size();
    int mxLen = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i] == 1 ? 1 : -1;

      if (sum == 0) {
        mxLen = i + 1;
      }

      if (mp.count(sum)) {
        mxLen = max(mxLen, i - mp[sum]);
      } else {
        mp[sum] = i;
      }
    }

    return mxLen;
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

  vector<int> nums = parseVector<int>(line);

  printVect(nums);

  cout << "Solution started ...." << endl;
  int ans = sol.findMaxLength(nums);

  cout << "ans : " << ans << endl;

  return 0;
}

/*

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Example 3:

Input: nums = [0,1,1,1,1,1,0,0,0]
Output: 6
Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.





*/