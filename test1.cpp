#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  bool point = false;
  int zeroAdded = 0;
  string ans;

  int counter = 15;

  void solve(int num, int deno) {
    counter--;
    if (counter < 0) {
      return;
    }

    if (num == 0) {
      return;
    }

    bug(ans);

    if (num < deno) {
      if (!point) {
        if (ans.length() == 0) {
          ans += "0.";
        } else {
          ans.push_back('.');
        }
        point = true;
      }

      if (zeroAdded > 0) {
        ans.push_back('0');
      }

      num *= 10;
      zeroAdded++;
    } else {
      int rem = num % deno;
      int q = num / deno;
      ans += to_string(q);

      zeroAdded = 0;
      num = rem;
    }

    solve(num, deno);
  }

  string fractionToDecimal(int num, int deno) {
    ans = "";
    solve(num, deno);
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  int num, deno;
  cin >> num >> deno;

  bug(num, deno);

  cout << "Solution started ...." << endl;
  string ans = sol.fractionToDecimal(num, deno);

  cout << "ans : " << ans << endl;

  return 0;
}