#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

// 1094. Car Pooling

class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    map<int, int> mp;

    for (vector<int>& t : trips) {
      int pass = t[0];
      int start = t[1];
      int end = t[2];

      mp[start] += pass;
      mp[end] += pass * -1;
    }

    int total = 0;
    for (auto& [u, v] : mp) {
      cout << u << "    " << v << endl;
      total += v;

      if (total > capacity)
        return false;
    }

    return true;
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

  vector<vector<int>> trips = parse2DVector<int>(line);

  print2DVector(trips);

  int capacity;
  cin >> capacity;

  cout << "Solution started ...." << endl;
  bool isPossible = sol.carPooling(trips, capacity);

  cout << "isPossible : " << isPossible << endl;

  return 0;
}