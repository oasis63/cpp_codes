#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

void generateSubsetsOfStrings(string str, string temp, int n, int ind) {
  if (ind == n) {
    cout << temp << endl;
    return;
  }

  // exclude the current index
  generateSubsetsOfStrings(str, temp, n, ind + 1);

  temp.push_back(str[ind]);

  generateSubsetsOfStrings(str, temp, n, ind + 1);
  temp.pop_back();
}

int main() {
  freopen64("output.txt", "w", stdout);

  string str = "abc";
  int n = str.length();

  generateSubsetsOfStrings(str, "", n, 0);

  return 0;
}