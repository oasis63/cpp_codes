#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  int solve(int A, int B) {
    int ans = 0;
    // left bottom corner
    int i = A, j = B;
    // bug(i, j);
    while (i > 1 && j > 1) {
      ans++;
      i--;
      j--;
    }

    // bug(ans);
    // right bottom corner
    i = A, j = B;
    while (i < 8 && j > 1) {
      ans++;
      i++;
      j--;
    }
    // bug(ans);

    // right top corner
    i = A, j = B;
    while (i < 8 && j < 8) {
      ans++;
      i++;
      j++;
    }
    // bug(ans);

    // left top corner
    i = A, j = B;
    while (i > 1 && j < 8) {
      ans++;
      i--;
      j++;
    }
    // bug(ans);

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;

  // int a = 4, b = 4;
  int a = 3, b = 1;

  int ans = sol.solve(a, b);

  bug(ans);

  return 0;
}