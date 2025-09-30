#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

int main() {
  vector<vector<int>> steps = {
      {-1, -1}, {+1, +1}, {-1, 1}, {1, -1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  int x = 0, y = 1;

  for (vector<int> &step : steps) {
    int i = step[0];
    int j = step[1];

    cout << (x + i) << "  " << (y + j) << endl;
  }

  return 0;
}