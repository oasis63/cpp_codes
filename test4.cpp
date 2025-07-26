#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  int maximumUniqueSubarray(vector<int>& nums) {
    // element, index

    int n = nums.size();

    // vector<int> prefix(n + 1, 0);
    // for (int i = 1; i < n; i++) {
    //   prefix[i] = prefix[i - 1] + nums[i];
    // }

    vector<int> prefix(n, 0);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] + nums[i];
    }

    unordered_map<int, int> mp;
    mp[nums[0]] = 0;

    int max_sum = nums[0];
    int curr_sum = nums[0];

    int left = 0, right = 1;

    int prev_left = 0;

    while (left < right && right < n) {
      if (mp.count(nums[right])) {
        left = mp[nums[right]];

        int temp_sum = 0;
        for (int i = prev_left; i <= left; i++) {
          if (mp.count(nums[i])) {
            mp.erase(nums[i]);
            temp_sum += nums[i];
          }
        }

        curr_sum -= temp_sum;

        // bug(temp_sum, curr_sum);

        curr_sum += nums[right];

        mp[nums[right]] = right;
        left++;
        right++;

        prev_left = left;

      } else {
        mp[nums[right]] = right;

        curr_sum += nums[right];

        max_sum = max(max_sum, curr_sum);

        right++;
      }
    }

    return max_sum;
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
  int ans = sol.maximumUniqueSubarray(nums);

  cout << "ans : " << ans << endl;

  return 0;
}