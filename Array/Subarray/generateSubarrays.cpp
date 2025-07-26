#include <bits/stdc++.h>
// #include "UTILS/helper.h"
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  vector<int> nums = {1, 2, 3, 4};
  int n = 4;
  cout << "Generate all subarrays : " << endl;

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = i; k <= j; k++) {
        cout << nums[k] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}