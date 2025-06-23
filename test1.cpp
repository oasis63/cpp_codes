#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

class Solution {
 public:
  // int mp[50] = {0};

  // vector<int> dp;

  // unique key

  unordered_map<string, int> dp;  // visited path , so return the number of ways
  unordered_map<string, bool> paths;

  int ans = 0;

  // recursion with memoization --> top-down approach

  int solve(int n, int k, int jump, bool goBack, string curr) {
    // cout << "current n : " << n << "  dp[" << n << "] : " << dp[n] << endl;

    curr += to_string(n);

    if (n < 0 || n > k + 1) {
      // dp[n] = 0;
      cout << "out of bound; returning" << endl;
      return 0;
    }

    int ways = 0;

    // check value in cache/memory
    // if (dp[n] != -1) return dp[n];
    if (dp.find(curr) != dp.end()) return dp[curr];

    // calculations
    // int ways = 0;

    // reached the destination and the path has not taken yet
    if (n == k && paths.find(curr) == paths.end()) {
      paths[curr] = true;

      cout << " inside n==k n : " << n << " k : " << k << "  ";
      cout << " curr path : " << curr << endl;

      ans++;

      ways = 1;
    }

    // if (mp[n] != 0) {
    //   return mp[n];
    // }

    if (!goBack && n != 0) {
      ways += solve(n - 1, k, jump, true, curr);
    }

    ways += solve(n + pow(2, jump), k, jump + 1, false, curr);

    return dp[curr] = ways;
    // cout << " ways : " << ways << endl;
    // return mp[n] = ways;
  }

  int waysToReachStair(int k) {
    int jump = 0;
    ans = 0;

    // number of ways of reaching k from nth place
    // k = 0 , n = 1, starting point --> 2 ways
    // k = 1 , n = 1 , starting point --> 4 ways
    // dp.resize(k + 2, -1);

    int n = 1;

    // dp[0]=2;
    // dp[1]=4;

    // int res = solve(1, k, jump, false) + solve(0, k, jump, true);
    int res = solve(n, k, jump, false, "");

    // cout << " res " << res << endl;

    // cout << "================ Print the dp vector ======================="
    //      << endl;
    // for (int i = 0; i < dp.size(); i++) {
    //   cout << "i : " << i << "  dp[i] : " << dp[i] << endl;
    // }

    cout << " res : " << res << endl;
    cout << " ans : " << ans << endl;
    // return dp[n];
    return res;
    // return ans;
  }
};

int main() {
  Solution sol;
  int k = 15;  // 0, 1, 15 ( 5 )  237, 32753
  int res = sol.waysToReachStair(k);

  cout << " final result : " << res << endl;

  return 0;
}