#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  //  max should be at most k times min
  //  max <= min*k

  int binarySearch(vector<int>& nums, int start, int end, int key) {
    int mid;

    while (start <= end) {
      mid = start + (end - start) / 2;

      if (nums[mid] == key)
        return mid;
      else if (nums[mid] > key)
        end = mid - 1;
      else
        start = mid + 1;
    }

    return -1;
  }

  int minRemoval(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int prev_i = -1;
    int prev_j = -1;

    for (int i = 0; i < n - 1; i++) {
      // auto ptr1 = upper_bound(nums.begin(), nums.end(), nums[i] * k) - nums.begin();
      auto ptr1 = lower_bound(nums.begin(), nums.end(), nums[i] * k);

      if (ptr1 == nums.end()) {
        break;
      } else {
        prev_i = i;
        prev_j = ptr1 - nums.begin();
      }
      int tmp = ptr1 - nums.begin();
      bug(nums[i] * k, tmp, nums[tmp]);
    }

    bug(prev_i, prev_j);

    if (prev_i == -1)
      return 0;

    return (n - prev_j - 1 + prev_i);

    // for (int i = 0; i < n - 1; i++) {
    //   int ind = binarySearch(nums, i + 1, n - 1, nums[i] * k);

    //   if (ind != -1) {
    //     return (n - ind - 1 + i);
    //   }
    // }

    return n - 1;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  string line;
  getline(cin, line);

  vector<int> nums = parseVector<int>(line);

  int k;
  cin >> k;

  printVect(nums);

  cout << "Solution started ...." << endl;
  int ans = sol.minRemoval(nums, k);

  cout << "ans : " << ans << endl;

  return 0;
}