#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

#define MOD 998244353

int main() {
  fast;
  //   freopen("input2.txt", "r", stdin);
  // freopen("output2.txt", "w", stdout);

  int n;
  cin >> n;
  cin.ignore();

  //   long long ans = 0LL;
  int ans = 0;

  for (int i = n; i >= 3; i--) {
    for (int j = i - 1; j >= 2; j--) {
      for (int k = j - 1; k >= 1; k--) {
        if ((i % j == k)) {
          ans = (ans + 1) % MOD;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}

/*

8
999999999999


*/