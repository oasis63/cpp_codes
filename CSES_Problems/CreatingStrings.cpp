#include <bits/stdc++.h>

// #include "UTILS/helper.h"
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

// permutations of a string

unordered_map<string, bool> mp;

void solve(vector<string> &vect, string &str, string &curr, int n, vector<pair<char, int>> &prRes) {
  if ((int)curr.length() == n) {
    // if (find(vect.begin(), vect.end(), curr) == vect.end())
    if (mp.count(curr) == 0) {
      vect.push_back(curr);
      mp[curr] = true;
    }
    return;
  }

  for (int i = 0; i < n; i++) {
    if (find(prRes.begin(), prRes.end(), make_pair(str[i], i)) != prRes.end()) {
      continue;
    }

    curr.push_back(str[i]);
    prRes.push_back({str[i], i});

    solve(vect, str, curr, n, prRes);

    curr.pop_back();
    prRes.pop_back();
  }
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  // aabac
  string str;

  getline(cin, str);

  vector<string> vect;
  string curr = "";
  int n = str.length();

  // to keep track of used char of the current character at index i
  vector<pair<char, int>> prRes;

  solve(vect, str, curr, n, prRes);

  cout << vect.size() << endl;

  sort(vect.begin(), vect.end());

  for (string s : vect) {
    cout << s << endl;
  }

  return 0;
}