#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

// Solution 1
class Solution1 {
 public:
  bool solve(string& res, unordered_set<string>& unique_params,
             vector<bool>& used, string& nums, int n) {
    if ((int)res.size() == n && unique_params.insert(res).second) {
      if (res[0] == '0')
        return false;
      int n1 = stoi(res);
      if ((n1 & (n1 - 1)) == 0) {
        return true;
      }
      return false;
    }

    for (int i = 0; i < n; i++) {
      if (used[i])
        continue;

      used[i] = true;

      res.push_back(nums[i]);

      bool result = solve(res, unique_params, used, nums, n);

      if (result)
        return true;

      res.pop_back();

      used[i] = false;
    }

    return false;
  }
  bool permuteUnique(string num) {
    // vector<string> ans;
    string res;
    // vector<pair<char, int>> prRes;

    int n = num.size();

    unordered_set<string> unique_params;
    vector<bool> used(n, false);

    return solve(res, unique_params, used, num, num.size());

    // for (string& str : ans) {
    //     // cout << str << endl;

    //     // skipping the strings containing
    //     // leading zeros
    //     if (str[0] == '0')
    //         continue;

    //     int n1 = stoi(str);
    //     if ((n1 & (n1 - 1)) == 0) {
    //         return true;
    //     }
    // }

    // return false;
  }
  bool reorderedPowerOf2(int n) {
    if (n == 1)
      return true;
    if (n % 10 == n) {
      return n & (n - 1);
    }

    string num = to_string(n);
    return permuteUnique(num);
  }
};

// solution2

class Solution {
 public:
  string sortStr(int n) {
    string str = to_string(n);
    sort(str.begin(), str.end());
    return str;
  }

  bool reorderedPowerOf2(int n) {
    string num1 = sortStr(n);

    // all the powers of 2
    for (int i = 0; i < 32; i++) {
      int p1 = 1 << i;
      string ps = sortStr(p1);
      if (ps == num1)
        return true;
    }
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  int n;
  cin >> n;

  cout << "Solution started ...." << endl;
  int ans = sol.reorderedPowerOf2(n);

  cout << "ans : " << ans << endl;

  return 0;
}