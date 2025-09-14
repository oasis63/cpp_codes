#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    vector<string> result;

    unordered_map<string, string> mp;

    for (string& word : wordlist) {
      mp[word] = true;
    }

    for (string& q : queries) {
    }

    result;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  string line;
  getline(cin, line);

  vector<vector<int>> points = parse2DVector<int>(line);

  print2DVector(points);

  double mx_area = sol.largestTriangleArea(points);

  bug(mx_area);

  return 0;
}