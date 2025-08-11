#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

typedef long long ll;

ll findDivisors(ll n) {
  ll cnt = 0;
  for (ll i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      cnt++;
      if (n / i == i) {
        // cout << i << " ";
      } else {
        // cout << i << " ";
        // cout << n / i << " ";
        cnt++;
      }
    }
  }
  // cout << endl;
  return cnt;
}

int main() {
  set_io_files("input.txt", "output.txt");

  ll start = 12370;
  ll end = 12380;

  ll ans = 0;
  ll count = 0;

  for (ll i = start; i <= end; i++) {
    ll num = (ll)(i * (ll)(i + 1)) / 2;

    count = findDivisors(num);

    if (count > 500) {
      cout << "FOUND > 500 : num : " << num << " i : " << i << endl;
      ans = num;
      break;
    }

    // bug(num, count);
  }

  bug(ans, count);

  return 0;
}