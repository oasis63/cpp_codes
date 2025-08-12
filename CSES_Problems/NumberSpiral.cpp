#include <bits/stdc++.h>

// #include "UTILS/helper.h"
using namespace std;

typedef long long ll;

// constructive problem
// beautiful permuations

void test_case(int row, int col) {
  int layer = max(row, col);
  if (layer % 2 == 1) {
    swap(row, col);
  }
  if (layer == col) {
    cout << (long long)(layer - 1) * (layer - 1) + 1 + (row - 1) << "\n";
  } else {
    assert(row == layer);
    cout << (long long)layer * layer - (col - 1) << "\n";
  }
}

int main() {
  // freopen("input2.txt", "r", stdin);
  // freopen("output2.txt", "w", stdout);

  int t, x, y;
  cin >> t;
  cin.ignore();

  while (t--) {
    cin >> y >> x;
    cin.ignore();
    test_case(y, x);
  }

  return 0;
}

/*
3
2 3
1 1
4 2

*/