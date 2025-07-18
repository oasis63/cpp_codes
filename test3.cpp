#include <bits/stdc++.h>

// #include "UTILS/helper.h"

using namespace std;

void test_case() {
  int n, k, t;
  cin >> n >> k;
  cin.ignore();

  // bug(n, k);

  // string line;
  // getline(cin, line);
  // vector<int> rainy = parseVector<int>(line);
  vector<int> rainy;
  for (int i = 0; i < n; i++) {
    cin >> t;
    rainy.push_back(t);
  }

  // printVector(rainy);

  vector<int> prefix(n, 0);

  int curr = 0;
  for (int i = 0; i < n; i++) {
    if (rainy[i] == 0) {
      curr++;
      prefix[i] = curr;
    } else {
      curr = 0;
    }
  }

  // cout << "Prefix sum " << endl;
  // printVector(prefix);

  int res = 0;

  for (int i = 0; i < n; i++) {
    // should not be rainy
    if (rainy[i] == 0) {
      //  i only if all aj=0  for all j (i≤ j ≤ i+k−1)
      int j = i + k - 1;
      int last_day = prefix[j];
      if (last_day) {
        int total_weather = last_day - prefix[i] + 1;

        // bug(total_weather);

        if (total_weather == k) {
          res++;
          i = j + 1;
        }
      }
    }
  }

  cout << res << endl;

  // cout << "result : " << res << endl;
  // cout << "------------------------------------------------" << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int tc;
  cin >> tc;
  cin.ignore();
  while (tc--) {
    test_case();
  }

  return 0;
}