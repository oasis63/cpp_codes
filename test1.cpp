#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

vector<string> process(string str) {
  vector<string> vect;
  int n = str.length();

  string temp = "";

  for (int i = 0; i < n; i++) {
    if (str[i] == '/') {
      if (temp != "")
        vect.push_back(temp);
      temp = "";
      temp += str[i];
    } else {
      temp.push_back(str[i]);
    }
  }

  vect.push_back(temp);

  return vect;
}

int main() {
  string str = "/a";

  vector<string> vect = process(str);

  printVect(vect);

  return 0;
}