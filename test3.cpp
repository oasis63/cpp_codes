#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

class Solution {
 public:
  bool sameFreq(unordered_map<char, int> s, unordered_map<char, int> t) {
    for (auto& [u, v] : t) {
      if (s[u] < t[u]) {
        return false;
      }
    }
    return true;
  }

  string minWindow(string s, string t) {
    int n1 = s.length();
    int n2 = t.length();

    if (n1 < n2)
      return "";

    // int freqS[26] = {0};
    // int freqT[26] = {0};

    unordered_map<char, int> freqS;
    unordered_map<char, int> freqT;

    for (auto& c : t) {
      freqT[c]++;
    }

    for (int i = 0; i < n2; i++) {
      freqS[s[i]]++;
    }

    string ans = "";

    if (sameFreq(freqS, freqT)) {
      ans = t;
      return ans;
    }

    cout << "print freqS " << endl;
    printMap(freqS);

    cout << "print freqT " << endl;
    printMap(freqT);

    int left = 0, right = n2;

    bug(n1, n2);

    while (left < right && left <= n1 && right <= n1) {
      bug(left, right);

      if (sameFreq(freqS, freqT)) {
        // bug(ansLength, subLength);
        if (ans == "" || (right - left) < (int)ans.length()) {
          ans = s.substr(left, right - left + 1);
          bug(ans);
        }
        // if (left < n1)
        freqS[s[left]]--;

        left++;
        // if (left < n1)
        // freqS[s[left]]++;

      } else {
        // no same frequency move the right pointer
        // cout << "Different Frequency " << endl;

        // if (right < n1) {
        freqS[s[right]]++;
        // }
        right++;
      }

      // if (right == 20) {
      //   printMap(freqS);
      // }
    }

    return ans;
  }
};

// abbbbbcdd

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;

  string s, t;
  getline(cin, s);
  getline(cin, t);

  string res = sol.minWindow(s, t);

  bug(res);
  cout << res << endl;

  return 0;
}