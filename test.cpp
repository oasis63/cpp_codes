#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

// 401. Binary Watch

class Solution {
 public:
  vector<string> readBinaryWatch(int turnedOn) {
    vector<string> ans;
    string minutes = "";
    string hours = "";

    vector<int> hoursBit = {32, 16, 8, 4, 2, 1};
    vector<int> minutesBit = {8, 4, 2, 1};

    return ans;
  }
};

// write a test

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  int turnedOn;
  cin >> turnedOn;

  cout << "Solution started ...." << endl;
  vector<string> ans = sol.readBinaryWatch(turnedOn);

  cout << "ans : " << endl;
  printVector<string>(ans);

  return 0;
}
