#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

vector<string> str_split(string str, char delim) {
  vector<string> tokens;
  stringstream ss(str);
  string token;

  while (getline(ss, token, delim)) {
    tokens.push_back(token);
  }

  return tokens;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  string str = "Data Science is funs";
  // cin >> str;

  vector<string> tokens = str_split(str, ' ');

  for (string st : tokens) {
    cout << "st : " << st << endl;
  }

  cout << str << endl;

  int n = (int)tokens.size();

  for (int i = 0; i < n / 2; i++) {
    swap(tokens[i], tokens[n - i - 1]);
  }

  // cout << "Final string : " << str << endl;

  // reverse(tokens.begin(), tokens.end());

  string ans;

  for (int i = 0; i < n; i++) {
    ans += tokens[i];
    if (i != n - 1) {
      ans += " ";
    }
  }

  // for (string& st : tokens) {
  //   cout << st << " ";
  // }

  cout << ans << endl;

  return 0;
}