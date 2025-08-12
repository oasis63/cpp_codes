#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

// permutations of a string

void solve(vector<string> &vect, string &str, string &curr, int n) {
  if (curr.length() == n) {
    if (find(vect.begin(), vect.end(), curr) == vect.end())
      vect.push_back(curr);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (curr.find(str[i]) != string::npos)
      continue;

    curr.push_back(str[i]);
    solve(vect, str, curr, n);
    curr.pop_back();
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  // aabac
  string str = "abcdef";

  getline(cin, str);

  vector<string> vect;
  string curr = "";
  int n = str.length();

  solve(vect, str, curr, n);

  cout << "\nPermutations of string" << endl;
  cout << "size of vector : " << vect.size() << endl;

  for (string s : vect) {
    cout << s << endl;
  }

  return 0;
}