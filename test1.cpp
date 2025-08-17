#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  int gainPnts(int mxPnts) {
    return (rand() % mxPnts) + 1;
  }

  double new21Game(int n, int k, int maxPts) {
    srand(time(0));

    // int pnts = gainPnts(maxPts);
    // bug(pnts);

    // total points gained
    int total_pnts = 0;

    // probability
    double prob = 0.0;

    int draws = 0;

    // draws  total_points < k
    while (total_pnts < k) {
      total_pnts += gainPnts(maxPts);

      draws++;
    }

    bug(draws);
    bug(total_pnts);

    double tmp = (double)n / (double)maxPts;
    tmp = round(tmp * 1e5) / 1e5;

    cout << fixed << setprecision(5);
    bug(tmp);

    double res = (double)tmp / (double)draws;
    res = round(res * 1e5) / 1e5;

    bug(res);

    bug(prob);

    return prob;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  // int n = 6, k = 1, maxPts = 10;
  // int n = 10, k = 1, maxPts = 10;
  int n = 21, k = 17, maxPts = 10;

  cout << "Solution started ...." << endl;

  double ans = sol.new21Game(n, k, maxPts);

  cout << "ans : " << ans << endl;

  return 0;
}