#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

class Solution {
 public:
  int mp[50] = {0};

  unordered_map<string, bool> paths;

  int ans = 0;

  int solve(int n, int k, int jump, bool goBack, string curr) {
    cout << "current n : " << n << endl;
    curr += to_string(n);

    if (n < 0 || n > k + 1) return 0;

    // reached the destination and the path has not taken yet
    if (n == k && paths.find(curr) == paths.end()) {
      // curr += to_string(n);

      paths[curr] = true;
      cout << " inside n==k n : " << n << " k : " << k << "  ";
      cout << " curr path : " << curr << endl;
      ans++;
    }

    // if (mp[n] != 0) {
    //   return mp[n];
    // }

    int ways = 0;
    if (n == 0) {
      // return 2;
      ways = 2;
    }
    // if (n == 1) return 4;

    //  if (n == k) {
    //   ways = 1;
    // }

    if (!goBack && n != 0) {
      // curr += to_string(n);
      ways += solve(n - 1, k, jump, true, curr);
    }

    ways += solve(n + pow(2, jump), k, jump + 1, false, curr);

    return ways;
    // cout << " ways : " << ways << endl;
    // return mp[n] = ways;
  }

  int waysToReachStair(int k) {
    int jump = 0;
    ans = 0;
    // int res = solve(1, k, jump, false) + solve(0, k, jump, true);
    int res = solve(1, k, jump, false, "");

    cout << " res " << res << endl;

    cout << " ans11 : " << ans << endl;
    // return res;
    return ans;
  }
};

int main() {
  Solution sol;
  int k = 8;  // 1
  int res = sol.waysToReachStair(k);

  cout << " final result : " << res << endl;

  return 0;
}