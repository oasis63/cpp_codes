#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define uli unsigned long int

class Util {
 public:
  template <typename T>
  void printSet(const set<T> &s) {
    for (const auto &element : s) {
      cout << element << " ";
    }
    cout << endl;
  }
  template <typename T>
  void printVector(const vector<T> &v) {
    for (const auto &element : v) {
      cout << element << " ";
    }
    cout << endl;
  }
  template <typename T>
  void print2DVector(const vector<vector<T>> &vec) {
    for (const auto &row : vec) {
      for (const auto &element : row) {
        cout << element << " ";
      }
      cout << endl;
    }
  }
};

Util util;

class Solution {
 public:
  int solve(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;

    return ans;
  }
};

Solution sol;

int main() {
  int n = 10;

  vector<int> dp(n, 0);

  // previous 3 steps
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i < n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  }

  Util util;

  util.printVector(dp);

  vector<int> dp1(n, 0);

  // previous 3 steps
  dp1[0] = 1;
  dp1[1] = 1;
  dp1[2] = 2;

  int k = 3;
  // n = i

  // dp[i] = dp[i-1] - dp[i-(k+1)] + dp[i-1]

  // k step ladder problem
  // using window concepts along with dynamic programming 
  
  for (int i = 3; i < n; i++) {
    dp1[i] = 2 * dp1[i - 1] - dp1[i - (k + 1)];
  }

  util.printVector(dp1);

  return 0;
}
