#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

class Solution {
 public:
  bool sameFreq(unordered_map<char, int> s, unordered_map<char, int> t) {
    for (auto& [u, v] : t) {
      // if (t[u] != s[u]) {
      //   return false;
      // }

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

    // bug(s, t);

    // transformToLower(s);
    // transformToLower(t);

    // bug(s, t);

    // int freqS[26] = {0};
    // int freqT[26] = {0};

    unordered_map<char, int> freqS;
    unordered_map<char, int> freqT;

    for (auto& c : t) {
      freqT[c]++;
    }

    int window2 = n2;

    // brute force
    string ans = "";

    for (int i = 0; i < n1; i++) {
      for (int j = i + n2 - 1; j < n1; j++) {
        string sub1 = s.substr(i, j - i + 1);
        // cout << sub1 << endl;

        unordered_map<char, int> freqSub;
        for (auto& c : sub1) {
          freqSub[c]++;
        }

        if (sameFreq(freqSub, freqT)) {
          if (ans == "" || sub1.length() < ans.length()) {
            ans = sub1;
          }
        }
      }
    }

    return ans;
  }
};

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;

  string s, t;
  getline(cin, s);
  getline(cin, t);

  string res = sol.minWindow(s, t);

  bug(res);

  return 0;
}