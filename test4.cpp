#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void printVect(vector<int> &vect) {
    for (int i : vect) {
      cout << i << " ";
    }
    cout << endl;
  }

  void solve(int total, int &curr, int count, int &ans, vector<int> &ps,
             int ind) {
    if (ind >= ps.size()) {
      return;
    }
    if (curr == total) {
      ans = min(count, ans);
    }

    for (int i = ind; i < ps.size(); i++) {
      if (curr + ps[i] > total) continue;

      // add the element
      curr += ps[i];
      // backtrack
      solve(total, curr, count + 1, ans, ps, i);
      // remove the elem

      curr -= ps[i];
    }
  }

  int numSquares(int n) {
    // generate all the perfect squares to the given number
    vector<int> ps;
    int num = 1;
    while (true) {
      int tp = num * num;
      if (tp > n) break;
      ps.push_back(tp);
      num++;
    }

    // put it in decreasing order
    sort(ps.rbegin(), ps.rend());
    printVect(ps);

    int curr = 0;
    int count = 0;
    int ans = INT_MAX;

    solve(n, curr, count, ans, ps, 0);

    cout << " ans : " << ans << endl;

    return 0;
  }
};

int main() {
  Solution sol;

  int n = 13;  //13,  12 , 292 
  int res = sol.numSquares(n);

  cout << " res : " << res << endl;

  return 0;
}