class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    // next_permutation(nums.begin(), nums.end());
    int n = nums.size();

    // find a pair from right of the array where nums[i] > nums[i-1]
    // ex: 1 , 2, 8 , 3 , 2
    //  .......(i).......   nums[i] > nums[i-1]
    int i = n - 2;
    while (i >= 0 && nums[i + 1] <= nums[i]) {
      i--;
    }
    if (i >= 0) {
      int j = n - 1;
      // find the first bigger element in the right side of i
      while (j >= 0 && nums[j] <= nums[i]) {
        j--;
      }
      swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
  }
};