#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

template <typename T>
void printVector(const vector<T> &vect) {
  for (const auto &element : vect) {
    cout << element << " ";
  }
  cout << endl;
}
// Minimum Jumps required to reach end from begining of an array

int min_jumps(vector<int> &arr, int n, vector<int> &dp, int index) {
  if (index == n - 1) {
    return 0;
  }
  if (index >= n) {
    return INT_MAX;
  }

  if (dp[index] != 0) return dp[index];

  // count the steps to reach to the end from the given index
  int steps = INT_MAX;
  int max_jumps = arr[index];

  for (int jump = 1; jump <= max_jumps; jump++) {
    int next_cell = index + jump;
    // subproblem 
    int subproblem = min_jumps(arr, n, dp, next_cell);
    if(subproblem != INT_MAX){
      steps = min(steps, subproblem + 1);
    }
  }
  
  return dp[index] = steps;
}

int main() {
  vector<int> arr{3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 2, 5};
  int n = arr.size();

  vector<int> dp(n, 0);

  int result = min_jumps(arr, n, dp, 0);

  cout << "Minimum Jumps required to reach end from begining : " << result
       << endl;

  return 0;
}