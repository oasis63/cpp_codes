#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

int countSetBits(int n) {
  int setBits = 0;

  while (n) {
    int last_bit = (n & 1);
    setBits += last_bit;
    n = n >> 1;
  }

  return setBits;
}

int main() {
  int n = 7;
  cout << "Number of set bits : " << countSetBits(n) << endl;
  return 0;
}