#include <bits/stdc++.h>
using namespace std;

// Use Sieve of Eratosthenes. to find all the primes in upto n

vector<int> listOfPrimesUptoN(int n) {
  // lets consider all the numbers are prime
  vector<bool> is_prime(n + 1, 1);
  is_prime[0] = 0;
  is_prime[1] = 0;

  for (int i = 2; i <= sqrt(n); i++) {
    if (is_prime[i]) {
      // if i is prime then all of it's multiples are not primes
      for (int j = i * i; j < n; j += i) {
        is_prime[j] = 0;
      }
    }
  }

  vector<int> primes_list;
  for (int i = 0; i <= n; i++) {
    if (is_prime[i]) {
      primes_list.push_back(i);
    }
  }
  return primes_list;
}

int main() {
  int n = 100;

  vector<int> primes = listOfPrimesUptoN(n);

  for (int i : primes) {
    cout << i << endl;
  }

  return 0;
}