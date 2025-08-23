#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

int main() {
  set_io_files("input.txt", "output.txt");

  // string str = "abcdefghi";
  string str = "abcde";

  cout << "Printing out all the suffixes of the string " << endl;

  for (int i = 0; i < (int)str.length(); i++) {
    string sub = str.substr(i);
    bug(i, sub);
  }

  return 0;
}