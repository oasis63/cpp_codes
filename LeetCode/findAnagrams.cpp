#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  bool sameFreq(int *a, int *b) {
    for (int i = 0; i < 26; i++) {
      if (a[i] != b[i]) {
        return false;
      }
    }
    return true;
  }

  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    int n1 = s.length();
    int n2 = p.length();

    if (n1 < n2)
      return {};

    int freq1[26] = {0};
    int freq2[26] = {0};

    for (auto &c : p) {
      freq2[c - 'a']++;
    }

    int window2 = n2;

    for (int i = 0; i < window2; i++) {
      freq1[s[i] - 'a']++;
    }

    if (sameFreq(freq1, freq2)) {
      ans.push_back(0);
    }

    for (int i = window2; i < n1; i++) {
      freq1[s[i - window2] - 'a']--;

      freq1[s[i] - 'a']++;

      if (sameFreq(freq1, freq2)) {
        ans.push_back(i - window2 + 1);
      }
    }

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

  string s, p;
  getline(cin, s);
  getline(cin, p);

  cout << "Solution started ...." << endl;
  vector<int> ans = sol.findAnagrams(s, p);

  cout << "ans : " << endl;
  printVect(ans);

  return 0;
}