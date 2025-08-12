#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t;
  cin >> n;

  vector<int> vect;

  while (n--) {
    cin >> t;
    vect.push_back(t);
  }

  sort(vect.begin(), vect.end());

  int prev = -1;
  int ans = 0;

  for (int &elem : vect) {
    if (prev != elem) {
      prev = elem;
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}