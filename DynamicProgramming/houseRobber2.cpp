#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;
class Solution {
 public:
  int helper(int n, int start, int end, vector<int>& nums) {
    vector<int> dp(n, 0);

    // bottom-up approach
    dp[start] = nums[start];
    dp[start + 1] = max(dp[start], nums[start + 1]);

    for (int i = start + 2; i <= end; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    bug(start, end);
    printVect(dp);

    return dp[end];
  }
  int rob(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

    int res1 = helper(n, 0, n - 2, nums);
    int res2 = helper(n, 1, n - 1, nums);

    return max(res1, res2);
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;

  int tc;
  cin >> tc;
  cin.ignore();

  while (tc--) {
    string line;
    getline(cin, line);

    vector<int> nums = parseIntVector(line);

    cout << "Input : ";
    printVect(nums);

    int ans = sol.rob(nums);

    cout << "ans : " << ans << "\n\n";
  }

  return 0;
}