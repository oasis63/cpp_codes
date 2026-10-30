#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

class Solution {
 public:
  int countZeros(vector<int>& nums) {
    int cnt = 0;
    for (int& i : nums) {
      cnt += i == 0 ? 1 : 0;
    }
    return cnt;
  }

  int solve(vector<int>& nums, int n, int curr, bool isRight) {
    cout << "curr : " << curr << endl;
    if (curr < 0 || curr >= n) {
      if (countZeros(nums) == n) {
        return 1;
      }
      return 0;
    }

    for (int i = 0; i < n; i++) {
      cout << nums[i] << " ";
    }
    cout << "------------------------\n";

    // if (nums[curr] == 0) {
    if (isRight) {
      curr++;
    } else {
      curr--;
    }
    // }
    // else if (nums[curr] > 0) {
    //     nums[curr]--;
    //     isRight = !isRight;
    //     if (isRight) {
    //         curr++;
    //     } else {
    //         curr--;
    //     }
    // }
    return 1;
    // return solve(nums, n, curr, isRight);
  }

  int countValidSelections(vector<int>& nums) {
    int ans = 0;
    int n = (int)nums.size();

    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        vector<int> temp1(nums);
        ans += solve(temp1, n, i, true);
        vector<int> temp2(nums);
        // ans += solve(temp2, n, i, false);
      }
    }

    return ans;
  }
};

int main() {
  Solution sol;

  vector<int> nums = {1, 0, 2, 0, 3};

  int ans = sol.countValidSelections(nums);

  cout << "ans : " << ans << endl;

  return 0;
}