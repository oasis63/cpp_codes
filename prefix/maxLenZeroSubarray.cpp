#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int maxLenZeroSumSubarray(vector<int>& nums) {
  unordered_map<int, int> sumIndex;
  int maxLen = 0, sum = 0;

  for (int i = 0; i < nums.size(); ++i) {
    sum += nums[i];

    if (sum == 0) {
      maxLen = i + 1;
    }

    if (sumIndex.find(sum) != sumIndex.end()) {
      maxLen = max(maxLen, i - sumIndex[sum]);
    } else {
      sumIndex[sum] = i;
    }
  }

  return maxLen;
}

int main() {
  vector<int> nums = {15, -2, 2, -8, 1, 7, 10, 23};
  cout << "Maximum length of subarray with sum 0: " << maxLenZeroSumSubarray(nums) << endl;
  return 0;
}
