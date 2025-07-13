#include <bits/stdc++.h>

// #include "UTILS/helper.h"
using namespace std;

typedef long long ll;

// constructive problem
// beautiful permuations

int main() {
  // freopen("input2.txt", "r", stdin);
  // freopen("output2.txt", "w", stdout);

  int n;
  cin >> n;
  cin.ignore();

  vector<int> vect;

  // odd numbers
  for (int i = 1; i <= n; i += 2) {
    vect.push_back(i);
  }

  // even numbers
  for (int i = 2; i <= n; i += 2) {
    vect.push_back(i);
  }

  if (n == 4) {
    vect = {3, 1, 4, 2};
  }

  // now check the generated permutation is beautiful or not

  for (int i = 0; i < n - 1; i++) {
    if (abs(vect[i] - vect[i + 1]) == 1) {
      cout << "NO SOLUTION" << endl;
      return 0;
    }
  }

  for (int i : vect) {
    cout << i << " ";
  }
  cout << "\n";

  return 0;
}