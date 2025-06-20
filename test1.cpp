#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<int> dp;

 public:
    Solution(int n){
        dp.resize(n+1, -1);
    }
  int solve(int n) {
    if (n <= 0) return 0;
    if (n == 1) return INT_MAX;
    if (n == 3 || n == 2) return 1;

    if (dp[n] != -1) return dp[n];
    return dp[n] = min(n / 2 + solve(n % 2), n / 3 + solve(n % 3));
  }

  //   int minCostClimbingStairs(vector<int>& cost) {
  //     int n = cost.size();
  //     dp.resize(n, -1);

  //     return min(solve(cost, n - 1), solve(cost, n - 2));
  //   }
};

int main() {
    //   int res = min(sol.solve());
    int n = 4;

    Solution sol(n);


  int res = sol.solve(n);

  cout << " res : " << res << endl;

  return 0;
}