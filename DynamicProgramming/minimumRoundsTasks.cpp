#include <bits/stdc++.h>

#include <chrono>

using namespace std;
using namespace chrono;

class Solution {
 public:
  vector<int> dp;

  Solution(int n) { dp.resize(n + 1, 0); }

  int solve(int n) {
    if (n == 0)
      return dp[n] = 0;
    else if (n == 1)
      return dp[n] = INT_MAX;
    else if (n == 2 || n == 3)
      return dp[n] = 1;

    if (dp[n] != 0) {
      return dp[n];
    }

    return dp[n] = 1 + min(solve(n - 3), solve(n - 2));

    // int s3 = solve(n - 3);
    // int s2 = solve(n - 2);
    // int result = INT_MAX;

    // if (s3 != INT_MAX && s2 != INT_MAX) {
    //   result = 1 + min(s2, s3);
    // } else {
    //   if (s2 != INT_MAX) {
    //     result = 1 + s2;
    //   } else if (s3 != INT_MAX) {
    //     result = 1 + s3;
    //   } else {
    //     result = INT_MAX;
    //   }
    // }
    // return dp[n] = result;
  }

  //   int minimumRounds(vector<int>& tasks) {
  //     int n = tasks.size();

  //     unordered_map<int, int> freq;

  //     int mx_val = 0;

  //     for (int t : tasks) {
  //       freq[t]++;

  //       mx_val = max(mx_val, freq[t]);
  //     }

  //     dp.resize(mx_val + 1, 0);

  //     int ans = 0;
  //     for (pair<int, int> pr : freq) {
  //       int res = solve(pr.second);
  //       if (res == INT_MAX) return -1;
  //       ans += res;
  //     }

  //     return ans;
  //   }
};

int main() {
  auto start = high_resolution_clock::now();

  int n = 11;

  Solution sol(n);

  for (int i = 0; i < n; i++) {
    cout << " i : " << i << " --->  " << sol.solve(i) << endl;
  }

  auto end = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(end - start);
  auto milli_duration = duration_cast<milliseconds>(end - start);

  cout << "Execution time: " << duration.count() << " microseconds" << "  ---  "
       << milli_duration.count() << " milliseconds" << endl;

  return 0;
}

/*

Execution time: 311031 microseconds
Execution time: 332011 microseconds




*/