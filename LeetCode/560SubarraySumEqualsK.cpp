#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

/*

maintain a hashmap of prefix sum counts seen so far, and as we iterate through the array,
 check how many times current_sum - k has occurred before.

*/

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;

    // sum frequency
    map<int, int> freq;

    freq[0] = 1;

    int current_sum = 0;

    for (int i = 0; i < n; i++) {
      current_sum += nums[i];

      if (freq.count(current_sum - k)) {
        ans += freq[current_sum - k];
      }

      freq[current_sum]++;
    }

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

  vector<int> nums = parseVector<int>(line);

  printVect(nums);

  cout << "Solution started ...." << endl;
  int ans = sol.subarraySum(nums);

  cout << "ans : " << ans << endl;

  return 0;
}