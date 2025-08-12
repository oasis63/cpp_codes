#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    // floyd's tortoise and hare's algorithms
    int slow = nums[0];
    int fast = nums[0];
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;

    // using bit manipulation
    // int len = nums.size();
    // int n = len-1;

    // int mx_bits = 0;

    // while ((1 << mx_bits) <= n) {
    //     mx_bits++;
    // }

    // int duplicate = 0;

    // for (int i = 0; i <= mx_bits; i++) {
    //     int mask = (1 << i);

    //     int original_bits = 0;
    //     int nums_bits = 0;

    //     for (int j = 1; j <= n; j++) {
    //         if ((mask & j)) {
    //             original_bits++;
    //         }
    //     }

    //     for (int& num : nums) {
    //         if ((mask & num)) {
    //             nums_bits++;
    //         }
    //     }

    //     if (nums_bits > original_bits) {
    //         duplicate |= mask;
    //     }
    // }

    // return duplicate;
  }
};

int main() {
  set_io_files("input.txt", "output.txt");

  string line;
  getline(cin, line);

  vector<int> nums = parseVector<int>(line);

  Solution sol;

  int res = sol.findDuplicate(nums);

  bug(res);

  return 0;
}