#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

// 2^n-1

void towerOfHanoi(int n, int source, int helper, int destination, vector<tuple<int, int>> &vect) {
  if (n == 1) {
    // cout << source << " " << destination << endl;
    vect.push_back({source, destination});
    return;
  }
  towerOfHanoi(n - 1, source, destination, helper, vect);
  // cout << source << " " << destination << endl;
  vect.push_back({source, destination});

  towerOfHanoi(n - 1, helper, source, destination, vect);
}

int main() {
  int n;
  cin >> n;

  vector<tuple<int, int>> vect;

  towerOfHanoi(n, 1, 2, 3, vect);

  cout << vect.size() << endl;

  for (const auto &tpl : vect) {
    cout << get<0>(tpl) << " " << get<1>(tpl) << endl;
  }

  return 0;
}