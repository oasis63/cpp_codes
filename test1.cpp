#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minSwaps(vector<int> &nums) {
        int n = nums.size();
        int l = 0;
        while (l < n && nums[l] == 0) {
            l++;
        }
        int r = l;
        while (l < n && nums[r] == 1) {
            r++;
        }
    }
};

int main() {

    Solution sol;
    vector<int> nums{0, 1, 1, 1, 0, 0, 1, 1, 0};
    cout << sol.minSwaps(nums) << endl;

    return 0;
}