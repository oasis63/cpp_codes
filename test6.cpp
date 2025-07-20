#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

int main() {
  // str1.compare(pos1, len1, str2);

  string str1 = "dddd";
  string str2 = "ccd";

  int res = str1.compare(0, 2, str2);

  bug(res);

  return 0;
}