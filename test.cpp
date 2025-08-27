#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

void recur(vector<string> &result, string temp, int k, vector<char> bits) {
  if ((int)temp.length() > k) {
    return;
  }

  // bug(temp, temp.length());

  if ((int)temp.length() == k) {
    result.push_back(temp);
  }

  for (int i = 0; i < 2; i++) {
    // add
    temp.push_back(bits[i]);
    // ignore
    recur(result, temp, k, bits);

    temp.pop_back();
  }
}

int main() {
  set_io_files("input.txt", "output.txt");

  int k = 3;
  vector<char> bits = {'0', '1'};
  vector<string> result;
  string temp;

  recur(result, temp, k, bits);

  cout << endl;
  for (string &st : result) {
    cout << st << endl;
  }

  return 0;
}