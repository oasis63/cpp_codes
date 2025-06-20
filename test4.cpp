#include <bits/stdc++.h>

#include <chrono>
using namespace std;
using namespace chrono;

int dp[100005] = {0};

int hits = 0;

// top down approach
// recursion + memoization

int solve(int n) {
//   cout << " n : " << n << endl;
  if (n == 0)
    return dp[n] = 0;
  else if (n == 1)
    return dp[n] = INT_MAX;
  else if (n == 2 || n == 3)
    return dp[n] = 1;

  if (dp[n] != 0) {
    hits++;
    return dp[n];
  }

  int s3 = solve(n % 3);
  int s2 = solve(n % 2);
  int result = INT_MAX;

  if (s3 != INT_MAX && s2 != INT_MAX) {
    result = min(n / 2 + s2, n / 3 + s3);
  } else {
    if (s2 != INT_MAX) {
      result = n / 2 + s2;
    } else if (s3 != INT_MAX) {
      result = n / 3 + s3;
    } else {
      result = INT_MAX;
    }
  }
  return dp[n] = result;
  // return result;
}

int main() {
  auto start = high_resolution_clock::now();

  int n = 11;

  for (int i = 0; i < n; i++) {
    cout << " i : " << i << " --->  " << solve(i) << endl;
  }

  // cout << solve(5) << endl;

  //   cout << "\n -------------final dp -----------" << endl;

  //   for (int i = 0; i < 20; i++) {
  //     cout << " i : " << i << " -------> " << dp[i] << endl;
  //   }

  auto end = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(end - start);
  auto milli_duration = duration_cast<milliseconds>(end - start);

  cout << " hits : " << hits << endl;

  cout << "Execution time: " << duration.count() << " microseconds" << "  ---  "
       << milli_duration.count() << " milliseconds" << endl;

  return 0;
}

/*

Execution time: 311031 microseconds
Execution time: 332011 microseconds




*/