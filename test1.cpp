#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

int main() {
  set_io_files("input.txt", "output.txt");

  int n = 0;

  for (int i = 0; i < 3; i++) {
    n = n | (1 << i);
    bug(n);
  }

  bug(n);

  return 0;
}