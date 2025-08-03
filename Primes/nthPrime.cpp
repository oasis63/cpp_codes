#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

/*

Use the Prime Number Theorem to estimate the upper bound:

n-th prime≈n⋅logn+n⋅loglogn

*/

// Sieve of eratosthene

int nthPrime(int n) {
  if (n == 1)
    return 2;
  int limit = (int)(n * log(n) + n * log(log(n))) + 10;

  vector<bool> isPrime(limit + 1, true);
  isPrime[0] = false;
  isPrime[1] = false;

  for (int i = 2; i <= sqrt(limit); i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= limit; j += i) {
        isPrime[j] = false;
      }
    }
  }
  int cnt = 0;
  for (int i = 2; i <= limit; i++) {
    if (isPrime[i]) {
      cnt++;
      if (cnt == n)
        return i;
    }
  }
  return -1;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n = 10001;

  int res = nthPrime(n);

  cout << res << endl;

  return 0;
}