#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

void solve(int src, vector<int> temp) {
  printVect(temp);

  if (src == 10) {
    return;
  }

  // for (int i = 0; i < 10; i++) {
  temp.push_back(src);

  solve(src + 1, temp);
  // }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  vector<int> vect;
  vect.push_back(1);

  solve(1, vect);

  return 0;
}