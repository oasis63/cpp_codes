#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

typedef long long ll;

// TODO: complete this code ... correct result is not coming

// Project Euler
// 11. Largest Product in a Grid

class Solution {
 public:
  ll find_product(int a, int b, int c, int d) {
    ll prod1 = (ll)(a * b);
    ll prod2 = (ll)(c * d);

    ll prod = (ll)prod1 * prod2;

    return prod;

    // return (ll)(a * b) * (ll)(c * d);
  }

  ll solve(vector<vector<int>> &mat) {
    ll ans = 0;

    int r = mat.size();     // 20;
    int c = mat[0].size();  // 20;

    // bug(mat.size(), mat[0].size());

    for (int i = 0; i < r - 3; i++) {
      for (int j = 0; j < c - 3; j++) {
        // horizontal
        ll horizontal = find_product(mat[i][j], mat[i][j + 1], mat[i][j + 2], mat[i][j + 3]);

        // bug(mat[i][j], mat[i][j + 1], mat[i][j + 2], mat[i][j + 3], horizontal);

        // vertical
        ll vertical = find_product(mat[i][j], mat[i + 1][j], mat[i + 2][j], mat[i + 3][j]);

        // bug(mat[i][j], mat[i + 1][j], mat[i + 2][j], mat[i + 3][j], vertical);

        // diagonal
        ll diagonal = find_product(mat[i][j], mat[i + 1][j + 1], mat[i + 2][j + 2], mat[i + 3][j + 3]);

        // bug(mat[i][j], mat[i + 1][j + 1], mat[i + 2][j + 2], mat[i + 3][j + 3], diagonal);

        ans = max({ans, horizontal, vertical, diagonal});
      }
    }

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  vector<vector<int>> mat;

  int tc = 20;

  while (tc--) {
    string line;
    getline(cin, line);

    vector<int> nums = parseVector<int>(line);
    mat.push_back(nums);
  }

  // print2DVector<int>(mat);

  cout << "Solution started ...." << endl;
  int ans = sol.solve(mat);

  cout << "ans : " << ans << endl;

  return 0;
}