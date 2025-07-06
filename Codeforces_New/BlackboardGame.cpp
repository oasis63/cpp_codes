#include <bits/stdc++.h>

// Blackboard Game

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;

  int tc;
  cin >> tc;
  cin.ignore();

  int n;

  while (tc--) {
    cin >> n;
    cin.ignore();

    int rem = n % 4;

    cout << n << "   " << n % 4 << "   ";

    if (rem == 0) {
      cout << "Bob" << endl;
    } else {
      cout << " Alice" << endl;
    }

    // int winner = sol.solve(n);
    // cout << (winner == 1 ? "Alice" : "Bob") << endl;
  }

  return 0;
}