class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    int n = nums.size();

    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int j = i + 1;
      int k = n - 1;

      int sum = 0;
      while (j < k) {
        sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          ans.push_back({nums[i], nums[j], nums[k]});
          j++;
          while (j < k && nums[j] == nums[j - 1]) {
            j++;
          }
        }

        if (sum < 0) {
          j++;
        } else {
          k--;
        }
      }
    }

    return ans;
  }
};