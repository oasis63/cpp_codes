#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

typedef long long ll;

class Solution {
 public:
  ll solve(ll n) {
    ll ans = 0;

    vector<vector<ll>> mat(n, vector<ll>(n, 0));

    for (ll i = 0; i < n; i++) {
      mat[i][0] = 1;
      mat[0][i] = 1;
    }

    // prll2DVector(mat);

    for (ll i = 1; i < n; i++) {
      for (ll j = 1; j < n; j++) {
        mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
      }
    }

    ans = mat[n - 1][n - 1];
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  ll n = 21;

  cout << "Solution started ...." << endl;
  ll ans = sol.solve(n);

  cout << "ans : " << ans << endl;

  return 0;
}