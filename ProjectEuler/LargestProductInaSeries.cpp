#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

// 	Largest Product in a Series

ll products(string str) {
  ll prod = 1;
  int n = str.length();
  for (int i = 0; i < n; i++) {
    if (str[i] == '0')
      return 0;
    int d = str[i] - '0';
    prod *= d;
  }
  return prod;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  string line;
  getline(cin, line);

  string str{};

  int n = line.size();

  for (int i = 0; i < 13; i++) {
    str.push_back(line[i]);
  }

  ll prod = products(str);

  for (int i = 13; i < n; i++) {
    str.erase(0, 1);
    str.push_back(line[i]);

    prod = max(prod, products(str));
  }

  bug(prod);

  return 0;
}