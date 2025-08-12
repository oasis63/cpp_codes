#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

string decToBinBitMask(int n, int q) {
  if (n == 0)
    return "0";

  string bin = "";

  unsigned int mask = 1 << 31;

  bitset<32> bs(mask);

  bool started = false;

  for (int i = 31; i >= 0; i--) {
    if ((n & mask) != 0) {
      bin += "1";
      started = true;
    } else if (started) {
      bin += "0";
    }
    mask >>= 1;
  }

  return bin;
}

string toBinary(int n, int width) {
  string result;
  for (int i = width - 1; i >= 0; i--) {
    result += ((n >> i) & 1) ? '1' : '0';
  }
  return result;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < (1 << n); i++) {
    cout << toBinary(i ^ (i >> 1), n) << endl;
  }

  return 0;
}