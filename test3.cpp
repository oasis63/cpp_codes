#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

int main() {
  string b = "cdabcdab";
  string a = "abcdabcdabcd";  // "abcd";  // 3

  int ind = a.find(b);

  bug(ind);

  string str1 = "ab";
  string str2 = "cdaadab";

  int i = str2.find(str1);

  bug(i);

  bug(string::npos);

  return 0;
}