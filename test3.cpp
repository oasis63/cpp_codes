#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isPossible(string str, int k) {
    int count1 = 0;
    for (char& c : str) {
      if (c == '1')
        count1++;
    }
    return count1 == k;
  }

  string shortestBeautifulSubstring(string s, int k) {
    string ans = "";

    int n = s.length();

    // for (int i = 0; i < n; i++) {
    //     for (int j = i; j < n; j++) {
    //         string sub = s.substr(i, j - i + 1); // Correct
    //         if (isPossible(sub, k)) {
    //             if (ans == "")
    //                 ans = sub;

    //             if (sub.length() < ans.length()) {
    //                 ans = sub;
    //             } else if (sub.length() == ans.length()) {
    //                 ans = min(ans, sub);
    //             }
    //         }
    //     }
    // }

    // try using sliding window

    // string window = "";
    int cnt1 = 0;

    int l = 0, r = 0;

    while (l <= r && l < n && r < n) {
      cout << " r : " << r << endl;

      if (s[r] == '1') {
        cnt1++;
      }

      while (cnt1 > k && l < r) {
        if (s[l] == '1')
          cnt1--;
        l++;
      }

      if (cnt1 == k) {
        string sub = s.substr(l, r - l + 1);
        cout << "sub : " << sub << endl;
        if (ans == "") {
          ans = sub;
        }
        if (sub.length() < ans.length()) {
          ans = sub;
        } else if (sub.length() == ans.length()) {
          ans = min(ans, sub);
        }
      }
      r++;
    }

    return ans;
  }
};

int main() {
  Solution sol;

  string str = "100011001";
  int k = 3;

  string res = sol.shortestBeautifulSubstring(str, k);

  cout << "res : " << res << endl;

  return 0;
}
