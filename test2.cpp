#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  void generateSubs(string s1, string curr, vector<string> &vect, vector<pair<char, int>> &prRes) {
    if (curr.size() == s1.size()) {
      if (find(vect.begin(), vect.end(), curr) == vect.end())
        vect.push_back(curr);
      return;
    }

    for (int i = 0; i < (int)s1.length(); i++) {
      if (find(prRes.begin(), prRes.end(), make_pair(s1[i], i)) != prRes.end()) {
        continue;
      }

      curr.push_back(s1[i]);
      prRes.push_back({s1[i], i});

      generateSubs(s1, curr, vect, prRes);

      curr.pop_back();
      prRes.pop_back();
    }
  }
  bool checkInclusion(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();

    unordered_map<char, int> mp1;
    for (char &c : s1) {
      mp1[c]++;
    }

    int i = 0, j = 0;

    // while (i < n1 && j < n2) {
    //   int k = i;
    //   if (s1[k] == s2[j]) {
    //   }

    //   j++;
    // }

    unordered_map<char, int> mp2;

    int cnt = 0;
    while (j < n2) {
      if (mp1.count(s2[j])) {
        mp2[s2[j]]++;

        // bug(s2[j]);
        // bug(mp2.count(s2[j]), mp1.count(s2[j]));
        // bug(mp2[s2[j]], mp1[s2[j]]);
        // cout << "-------------------------" << endl;

        if (mp2[s2[j]] > mp1[s2[j]]) {
          mp2.clear();
          mp2[s2[j]]++;

          cnt = 1;
        } else {
          cnt++;
          if (cnt == n1) {
            return true;
          }
        }

      } else {
        cnt = 0;
        mp2.clear();
      }
      j++;
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