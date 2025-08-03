#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  int rangeBitwiseAnd(int l, int r) {
    unsigned int left = static_cast<unsigned int>(l);
    unsigned int right = static_cast<unsigned int>(r);

    int res = left;
    left++;
    while (left <= right) {
      // bug(left);
      res &= left;
      if (res == 0)
        return 0;
      if (left >= 2147483646)
        break;
      left++;
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  // int left = 1073741824;  // 2147483647;  // 2147483646;  // 1;
  // int right = 2147483647;

  // int res = sol.rangeBitwiseAnd(left, right);
  // bug(left, right, res);

  for (int left = 0; left < 10; left++) {
    for (int right = left + 1; right <= 10; right++) {
      int res = sol.rangeBitwiseAnd(left, right);
      bug(left, right, res, (left & right));
    }
  }

  return 0;
}