#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  string baseNeg2(int n) {
    if (n == 0) return "0";

    string bin = "";
    int base = -2;

    /*
      dividend = divisor * quotient + remainder
    */

    while (n) {
      int rem = n % base;  // remainder
      n = n / base;        // quotient

      if (rem < 0) {
        // since we can add the negative to binary

        rem += 2;
        n += 1;  // adding 1 to the quotient

        /* even after adding +2 to remainder , and +1 to quotient
        satisfies this equation

        --> dividend = divisor * quotient + remainder
        n = base * ( quotient + 1 ) + (remainder + 2)

        */
      }
      bin = to_string(rem) + bin;
    }

    return bin;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;

  int n;
  cin >> n;

  string bin = sol.baseNeg2(n);

  cout << "bin : " << bin << endl;

  return 0;
}