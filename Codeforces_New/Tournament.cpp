// B. Tournament

#include <bits/stdc++.h>

// #include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  bool solve(int n, int j, int k, vector<int> &players) {
    bool ans = false;

    priority_queue<int> mxHeap;

    int targetStrength = players[j - 1];

    // cout << "targetStrength : " << targetStrength << endl;

    for (int i = 0; i < n; i++) {
      if (i == (j - 1)) continue;
      mxHeap.push(players[i]);
    }

    // vector<int> vect;  // hold top k values

    // cout << "Pq size : " << mxHeap.size() << endl;

    while (!mxHeap.empty() && mxHeap.size() > (k - 1) && mxHeap.size() >= 2) {
      int top1 = mxHeap.top();
      mxHeap.pop();
      int top2 = mxHeap.top();
      mxHeap.pop();
      mxHeap.push((top1 > top2 ? top1 : top2));
      // cout << "inside while loop " << endl;
    }

    // cout << "mxHeap size : " << mxHeap.size() << endl;
    // cout << "top " << k << " elements " << endl;
    // for (int v : vect) {
    //   cout << v << endl;
    // }

    int rem_size = mxHeap.size();

    if (rem_size < k) {
      return true;
    }

    return mxHeap.top() > targetStrength ? false : true;
    // return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  Solution sol;

  int tc;
  cin >> tc;
  cin.ignore();

  int n, j, k;

  while (tc--) {
    cin >> n >> j >> k;
    cin.ignore();

    // bug(n, j, k);

    vector<int> players(n, 0);

    for (int i = 0; i < n; i++) {
      cin >> players[i];
    }
    cin.ignore();

    bool res = sol.solve(n, j, k, players);

    // bool res = j != 1;

    cout << (res ? "YES" : "NO ") << endl;

    // cout << "\n-----------------------------------------\n" << endl;
  }

  return 0;
}