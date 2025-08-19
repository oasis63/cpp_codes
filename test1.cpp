#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

int divisors(int n) {
  int count = 0;

  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if ((n / i) == i) {
        cout << i << " ";
        count += 1;
      } else {
        cout << i << " " << (n / i) << " ";
        count += 2;
      }
    }
  }
  cout << "\n";
  return count;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  int tc;
  cin >> tc;

  while (tc--) {
    int n = 18;
    cin >> n;
    bug(n);
    int cnt = divisors(n);
    cout << cnt << "\n";
  }

  return 0;
}