class Solution {
public:
    // using kadane's algorithm
    int maxProduct(vector<int> nums) {
        int n = nums.size();
        int mx = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                swap(currMax, currMin);
            }
            currMax = max(currMax * nums[i], nums[i]);
            currMin = min(currMin * nums[i], nums[i]);
            mx = max(mx, currMax);
        }
        return mx;
    }
};