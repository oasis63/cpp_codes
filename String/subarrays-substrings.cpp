#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

int main() {
  set_io_files("input.txt", "output.txt");

  string str = "abcde";

  vector<string> subarrays1;
  vector<string> subarrays2;

  int n = str.length();

  // from left to right
  for (int i = 0; i < n; i++) {
    string tmp;
    for (int j = i; j < n; j++) {
      tmp.push_back(str[j]);

      subarrays1.push_back(tmp);
    }
  }

  cout << "--------------left to right subarrays ---------------: \n";
  printVect(subarrays1);

  sort(subarrays1.begin(), subarrays1.end());
  printVect(subarrays1);

  // from right to left

  for (int i = n - 1; i >= 0; i--) {
    string tmp;
    for (int j = i; j < n; j++) {
      tmp.push_back(str[j]);
      subarrays2.push_back(tmp);
    }
  }

  cout << "\n--------------right to left subarrays ---------------: \n";
  printVect(subarrays2);

  sort(subarrays2.begin(), subarrays2.end());
  printVect(subarrays2);

  return 0;
}