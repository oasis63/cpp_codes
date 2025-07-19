#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

class Solution {
 public:
  void transformToLower(string& s) {
    for (char& c : s) {
      if (c >= 'A' && c <= 'Z') {
        c = (char)(c + 32);
      }
    }
  }

  bool sameFreq(int* a, int* b) {
    for (int i = 0; i < 26; i++) {
      if (a[i] != b[i]) {
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

    bug(s, t);

    transformToLower(s);
    transformToLower(t);

    bug(s, t);

    int freqS[26] = {0};
    int freqT[26] = {0}

    for (auto& c : t) {
      freqT[c]++;
    }

    int window2 = n2;

    for (int i = 0; i < window2; i++) {
      freqS[s[i] - 'a']++;
    }

    if (sameFreq(freqS, freqT)) {
      return t;
    }

    string ans;

    for (int i = window2; i < n2; i++) {
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