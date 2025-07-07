#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

// bitmask

string decToBinBitMask(int n) {
  if (n == 0) return "0";

  string bin = "";

  unsigned int mask = 1 << 31;

  bitset<32> bs(mask);

  bug(bs);
  int len = bs.size();
  bug(len);

  bool started = false;

  for (int i = 31; i >= 0; i--) {
    int and_res = (n & mask);

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

string decToBin(int n) {
  string bin = "";

  while (n) {
    int rem = n % 2;
    n = n / 2;

    bin = to_string(rem) + bin;
  }

  return bin;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n;
  cin >> n;

  string bin = decToBin(n);
  string bitWiseBin = decToBinBitMask(n);

  bug(bin, bitWiseBin);

  return 0;
}