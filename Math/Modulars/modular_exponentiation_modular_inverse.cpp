#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

// this is prime
const int MOD = 1'000'000'007;

int modular_expo(int base, int exp) {
  long long res = 1;

  base = base % MOD;

  while (exp) {
    if (exp % 2 == 1) {
      res = (res * base) % MOD;
    }
    base = (base * base) % MOD;
    exp /= 2;
  }

  return static_cast<int>(res);
}

/*
✅ Conditions:

MOD must be prime.
a must be coprime with MOD (i.e., gcd(a, MOD) = 1).

💡 If MOD were not prime, we couldn’t use FLT — we’d instead use the Extended Euclidean Algorithm to find the inverse.

*/

int modularInverse(int a) {
  return modular_expo(a, MOD - 2);
}

int main() {
  set_io_files("input.txt", "output.txt");

  int base = 2;
  int exp = 5;

  int res = modular_expo(base, exp);

  cout << "res : " << res << "\n";

  int numerator = 14;
  int denominator = 5;

  // to find :    numerator/denominator
  // we can do :   numerator * modularInverse(denominator)

  int modInverse = modularInverse(denominator);

  int result = (numerator * modInverse) % MOD;

  cout << "result : " << result << "\n";

  return 0;
}