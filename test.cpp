#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

void findPermutations(int depth, string permutation, vector<bool>& used, string& original, vector<int>& res) {
  int len = original.length();

  if (depth == len) {
    res.push_back(permutation);
  } else {
    for (int i = 0; i < len; i++) {
      if (!used[i]) {
        used[i] = true;
        permutation[depth] = original[i];
        findPermutations(depth + 1, permutation, used, original);
        used[i] = false;
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;

  vector<string> permutes1;
  vector<string> permutes2;

  vector<int> used()

      findPermutations(depth, permutation, used, orig, permutes1);

  bug(n, a, b);
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int tc;
  cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}