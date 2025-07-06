#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

// recursive solution

/*

int solve(string s, int index, unordered_map<int, int>& mp) {
    if (s.length() == index)
        return 1;
    if (s[index] == '0')
        return 0;
    if (mp.count(index))
        return mp[index];

    int count = solve(s, index + 1, mp);

    if ((index + 1) < s.length()) {
        int num = stoi(s.substr(index, 2));
        if (num >= 10 && num <= 26) {
            count += solve(s, index + 2, mp);
        }
    }
    return mp[index] = count;
}

int numDecodings(string s) {
    unordered_map<int, int> mp;
    return solve(s, 0, mp);
}


*/

class Solution {
 public:
  int numDecodings(string s) {
    int n = s.length();
    if (n == 0 || s[0] == '0') return 0;

    vector<int> dp(n + 1, 0);

    // number of ways to decode first i characters
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
      // last one digit and last 2 digits
      int onedigit = stoi(s.substr(i - 1, 1));
      int twodigit = stoi(s.substr(i - 2, 2));

      if (onedigit >= 1 && onedigit <= 9) {
        dp[i] += dp[i - 1];
      }

      if (twodigit >= 10 && twodigit <= 26) {
        dp[i] += dp[i - 2];
      }
    }

    return dp[n];
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;

  string str;
  cin >> str;

  int ans = sol.numDecodings(str);

  cout << "ans : " << ans << endl;

  // for (int i = 1; i <= 26; i++) {
  //   cout << i << "   " << sol.getChar(i) << endl;
  // }

  // char c = sol.getChar(28);

  // if (c == '\0') {
  //   cout << "empty char" << endl;
  // } else {
  //   cout << "non empty char" << endl;
  // }

  return 0;
}