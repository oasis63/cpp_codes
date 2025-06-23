#include <bits/stdc++.h>
using namespace std;

/*
This solution is partially correct for lower input ranges ,
but for upper input ranges, it's not working

here we are using 2D DP 

we are considering two states here : 

1) index 
2) isBack

*/

class Solution {
 public:
  unordered_map<int, int> forbidMap;
  int dp_len = 6001;

  int solve(int a, int b, int x, vector<vector<int>>& dp, int index,
            bool isBack) {
    // base cases
    if (index == x) {
      return 0;  // no more jumps needed
    }

    // forbidden and negative indices
    // for now index's right bound is  2000, but we have to find a proper
    // value for this
    // cout << "index : " << index << endl;

    if (index < 0 || index > 6000 || isBack >= 2) {
      return INT_MAX;
    }

    // cout << "index : " << index << endl;
    // already visited the current index
    // if (dp[index] != 0)
    //     return dp[index];

    if (dp[index][isBack] != -1) return dp[index][isBack];

    // at any index we can perform two steps
    // 1) +a  or 2) -b

    int forward = solve(a, b, x, dp, index + a, false);

    int backward = INT_MAX;

    if (!isBack) {
      backward = solve(a, b, x, dp, index - b, true);
    }

    // return dp[index][isBack] = min(forward, backward) + 1;

    // cout << " index : " << index << " forward : " << forward
    //      << " backward : " << backward << endl;

    int res = INT_MAX;
    if (forward != INT_MAX) res = min(res, forward + 1);
    if (backward != INT_MAX) res = min(res, backward + 1);

    return dp[index][isBack] = res;
  }

  int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    // dp_len = 2000 + a + b
    // cout << "dp_len : " << dp_len << endl;

    // vector<int> dp(dp_len, 0);
    int max_len = 0;

    for (int i : forbidden) {
      forbidMap[i] = 1;
      max_len = max(max_len, i);
    }

    // dp_len = max_len + a + x + b + 1;

    // dp_len = max(x, max_len) + a + b;

    // dp_len = max(max_len + a + b, x + b);

    // dp_len = max(max_len, x) + a + b + 2000;

    cout << "dp_len : " << dp_len << endl;

    // vector<int> dp(dp_len + 1, 0);

    vector<vector<int>> dp(dp_len + 1, vector<int>(2, -1));

    int index = 0;
    int result = solve(a, b, x, dp, index, false);
    return result >= INT_MAX ? -1 : result;
  }
};

int main() {
  Solution sol;

  vector<int> forbidden = {14, 4, 18, 1, 15};
  int a = 3, b = 15 ,x = 9;

  // vector<int> forbidden = {8, 3, 16, 6, 12, 20};
  // int a = 15, b = 13, x = 11;

  // vector<int> forbidden = {1, 6, 2, 14, 5, 17, 4};
  // int a = 16, b = 9, x = 7;

  // 121 jumps
  // vector<int> forbidden = {
  //     162, 118, 178, 152, 167, 100, 40,  74,  199, 186, 26, 73,  200, 127,
  //     30,  124, 193, 84,  184, 36,  103, 149, 153, 9,   54, 154, 133, 95,
  //     45,  198, 79,  157, 64,  122, 59,  71,  48,  177, 82, 35,  14,  176,
  //     16,  108, 111, 6,   168, 31,  134, 164, 136, 72,  98};

  // int a = 29, b = 98, x = 80;

  int result = sol.minimumJumps(forbidden, a, b, x);

  cout << "result : " << result << endl;

  return 0;
}