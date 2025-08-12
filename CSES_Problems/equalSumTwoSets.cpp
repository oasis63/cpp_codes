#include <bits/stdc++.h>

// #include "UTILS/helper.h"
using namespace std;

typedef long long ll;

int main() {
  // freopen("input2.txt", "r", stdin);
  // freopen("output2.txt", "w", stdout);

  int n;
  cin >> n;

  vector<int> a, b;
  ll A = 0, B = 0;

  for (int x = n; x >= 1; x--) {
    if (B < A) {
      B += x;
      b.push_back(x);
    } else {
      A += x;
      a.push_back(x);
    }
  }

  if (A == B) {
    cout << "YES\n";
    cout << a.size() << endl;
    for (int i : a) {
      cout << i << " ";
    }
    cout << endl;
    cout << b.size() << endl;
    for (int i : b) {
      cout << i << " ";
    }
    cout << endl;
  } else {
    cout << "NO \n";
  }

  return 0;
}