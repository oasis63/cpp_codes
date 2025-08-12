#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n = 2'000'000;

  // int n = 10;

  // nlogn + nloglogn;

  vector<bool> isPrime(n + 1, true);
  isPrime[0] = false;
  isPrime[1] = false;

  for (int i = 2; i <= sqrt(n); i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }

  ll sum = 0;

  for (int i = 2; i <= n; i++) {
    sum += isPrime[i] ? (ll)i : 0;
  }

  bug(sum);

  return 0;
}