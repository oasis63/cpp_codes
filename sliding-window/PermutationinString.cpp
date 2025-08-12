#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  bool isEqualFreq(int *a, int *b) {
    for (int i = 0; i < 26; i++) {
      if (a[i] != b[i])
        return false;
    }
    return true;
  }

  bool checkInclusion(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();

    if (n1 > n2)
      return false;

    int freq1[26] = {0};
    int freq2[26] = {0};

    for (char &c : s1) {
      freq1[c - 'a']++;
    }

    int window1 = s1.length();

    for (int i = 0; i < window1; i++) {
      char c = freq2[i];
      freq2[c - 'a']++;
    }

    if (isEqualFreq(freq1, freq2)) {
      return true;
    }

    for (int i = window1; i < n2; i++) {
      freq2[s2[i - window1] - 'a']--;

      freq2[s2[i] - 'a']++;

      if (isEqualFreq(freq1, freq2)) {
        return true;
      }
    }

    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;

  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);

  cout << "Solution started ...." << endl;
  bool ans = sol.checkInclusion(s1, s2);

  cout << "ans : " << ans << endl;

  return 0;
}