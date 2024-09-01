
class Solution {
  public:
    int solve(vector<int> &nums, int currInd, int n, int steps) {
        if ((currInd + nums[currInd]) >= n - 1) { // base case
            return steps + 1;
        }

        int ans = INT_MAX;
        int maxValue = nums[currInd + 1], maxIndex = currInd + 1;

        for (int i = currInd + 1; i <= (currInd + nums[currInd]) && i < n;
             i++) {
            int temp_sum = nums[i] + i;
            int diff1 = n - 1 - temp_sum;
            int diff2 = n - 1 - (maxValue + maxIndex);
            if (diff1 < diff2) {
                maxValue = nums[i];
                maxIndex = i;
            }
        }
        ans = min(ans, solve(nums, maxIndex, n, steps + 1));
        return ans;
    }

    int jump(vector<int> &nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        return solve(nums, 0, n, 0);
    }
};