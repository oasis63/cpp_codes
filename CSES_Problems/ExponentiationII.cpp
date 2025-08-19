#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

typedef long long ll;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 6;

/*
Your task is to efficiently calculate values a^{b^c} modulo 10^9+7.
Note that in this task we assume that 0^0=1.

*/

ll mod_exp(ll base, ll exp, ll MOD) {
  ll res = 1;

  while (exp > 0) {
    if (exp & 1) {
      res = (res * base) % MOD;
    }
    base = (base * base) % MOD;
    exp /= 2;
  }

  return res % MOD;
}

ll mod_exp2(int a, int b, int c) {
  ll d = mod_exp(b, c, MOD2);

  ll res = mod_exp(a, d, MOD1);

  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  int q;
  ll a, b, c;

  cin >> q;
  cin.ignore();
  while (q--) {
    cin >> a >> b >> c;
    cin.ignore();

    ll res = mod_exp2(a, b, c);
    cout << res << endl;
  }

  return 0;
}