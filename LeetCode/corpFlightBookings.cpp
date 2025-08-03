#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> flights(n, 0);

    for (auto& b : bookings) {
      int first = b[0];
      int last = b[1];
      int seats = b[2];

      flights[first - 1] += seats;
      if (last < n) {
        flights[last] -= seats;
      }
    }

    for (int i = 1; i < n; i++) {
      flights[i] += flights[i - 1];
    }

    return flights;
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
  vector<int> ans = sol.corpFlightBookings(trips, capacity);

  printVect(ans);

  return 0;
}