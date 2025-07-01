class Solution {
 public:
  //  top down approach
  int min_jumps(vector<int>& nums, int n, vector<int>& dp, int index) {
    // already at the end of the aray
    if (index == n - 1) return 0;
    if (index >= n) return INT_MAX;

    if (dp[index] != 0) return dp[index];

    int steps = INT_MAX;
    int max_jump = nums[index];

    for (int jump = 1; jump <= max_jump; jump++) {
      int next_cell = index + jump;

      int subprob = min_jumps(nums, n, dp, next_cell);

      if (subprob != INT_MAX) {
        steps = min(subprob + 1, steps);
      }
    }
    return dp[index] = steps;
  }

  int jump(vector<int>& nums) {
    // Top-Down Approach
    // int n = nums.size();
    // vector<int> dp(n, 0);
    // return min_jumps(nums, n, dp, 0);

    // Bottom-Up Approach
    int n = nums.size();

    // reaching index is the state here
    vector<int> dp(n + 1, INT_MAX);

    // starting point is 0 , so 0 jumps needed to reach 0
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
      for (int jump = 1; jump <= nums[i]; jump++) {
        int next_cell = i + jump;
        if (next_cell < n && dp[i] != INT_MAX)
          dp[next_cell] = min(dp[next_cell], dp[i] + 1);
      }
    }

    return dp[n - 1];
  }
};

/*

nums =
[2,3,1,1,4]
Output
2
Expected
2

*/