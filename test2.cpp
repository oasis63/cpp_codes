#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

int main() {
  set_io_files("input.txt", "output.txt");

  int n = 12;

  for (int i = 0; i < 32; i++) {
    int isBit = ((n >> i) & 1) == 1;
    bug(i, isBit);
  }

  return 0;
}