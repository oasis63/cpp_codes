#include <bits/stdc++.h>

#include <chrono>
using namespace std;
using namespace chrono;

int dp[100001] = {-1};

// top down approach

int solve(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return INT_MAX;
  else if (n == 2 || n == 3)
    return 1;
  // return min(n / 2 + solve(n % 2), n / 3 + solve(n % 3));

  if (dp[n] != -1) {
    cout << " used the memoized value " << endl;
    return dp[n];
  }

  int s3 = solve(n % 3);
  int s2 = solve(n % 2);

  if (s3 != INT_MAX && s2 != INT_MAX) {
    // cout<< " s22 : " << s2 << "  s33 : " << s3 << endl;
    return dp[n] = min(n / 2 + s2, n / 3 + s3);
  } else {
    if (s2 == INT_MAX) {
      return dp[n] = n / 3 + s3;
    }
    // cout<<" s2 : " << s2 << endl;
    return dp[n] = n / 2 + s2;
  }
}

int main() {
  int n = 11;

  auto start = high_resolution_clock::now();

  for (int i = 0; i < n; i++) {
    cout << " i : " << i << " --->  " << solve(i) << endl;
  }

  auto end = high_resolution_clock::now();

  //   auto duration = duration_cast<milliseconds>(end - start);

  auto duration = duration_cast<microseconds>(end - start);

  cout << "Execution time: " << duration.count() << " microseconds" << endl;

  // cout << solve(5) << endl;

  return 0;
}