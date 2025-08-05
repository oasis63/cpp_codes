#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  //  max should be at most k times min
  //  max <= min*k

  // element <= key
  // key >= element
  //  key = nums[i]*factor
  // element <= nums[i]* factor
  // element/factor <= nums[i]

  int binarySearch(vector<int>& nums, int start, int end, int key, int factor) {
    int mid;
    int index = -1;

    while (start <= end) {
      mid = start + (end - start) / 2;

      int mx_elem = nums[mid];

      if ((double)(mx_elem / (double)factor) <= (double)key) {
        index = mid;
        // end = mid - 1;
        start = mid + 1;
      } else {
        // start = mid + 1;
        end = mid - 1;
      }
      // if (nums[mid] == key)
      //   return mid;
      // else if (nums[mid] > key)
      //   end = mid - 1;
      // else
      //   start = mid + 1;
    }
    return index;
  }

  int minRemoval1(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    printVect(nums);

    int n = nums.size();
    if (n <= 1)
      return 0;

    int ans = INT_MAX;

    //  answer = n - (j - i + 1).

    for (int i = 0; i < n - 1; i++) {
      // int key = nums[i] * k;
      int key = nums[i];
      int ind = binarySearch(nums, i + 1, n - 1, key, k);

      bug(key, i, ind);

      if (ind != -1) {
        // return (n - ind - 1 + i);
        ans = min(ans, n - ind - 1 + i);
        bug(ans);
      }
    }
    return ans != INT_MAX ? ans : n - 1;
  }

  // using sliding window
  int minRemoval(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    printVect(nums);

    int n = nums.size();
    if (n <= 1)
      return 0;

    int ans = INT_MAX;

    int left = 0, right = 0;

    while (left <= right && left < n && right < n) {
      while (right < n && (double)nums[left] >= (double)((double)nums[right] / (double)k)) {
        right++;
      }
      ans = min(ans, n - right + left);
      left++;
    }

    return ans;
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