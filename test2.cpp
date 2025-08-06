#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  // first ( fruits count) index less than or equal to the baskets size

  int find_search(vector<int>& fruits, int basketSize) {
    int n = fruits.size();
    for (int i = 0; i < n; i++) {
      if (fruits[i] > basketSize)
        return -1;
      if (fruits[i] != -1) {
        return i;
      }
    }

    return -1;
  }

  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = fruits.size();
    int ans = 0;

    sort(fruits.begin(), fruits.end());

    // let's try to fill the baskets

    for (const auto& basketSize : baskets) {
      int ind = find_search(fruits, basketSize);

      if (ind != -1 && ind < n) {
        fruits[ind] = -1;
      }
    }

    // for (int i = 0; i < n; i++) {
    //   bool found = false;
    //   for (int j = 0; j < n; j++) {
    //     if (baskets[j] == -1)
    //       continue;

    //     if (baskets[j] >= fruits[i]) {
    //       baskets[j] = -1;
    //       found = true;
    //       break;
    //     }
    //   }
    //   if (found) {
    //     fruits[i] = -1;
    //   }
    // }

    for (int i = 0; i < fruits.size(); i++) {
      cout << i << "  ---- > " << fruits[i] << endl;
      if (fruits[i] != -1) {
        ans++;
      }
    }

    // for (int i : fruits) {
    //     if (i != -1) {
    //         ans++;
    //     }
    // }
    return ans;
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

  vector<int> fruits = parseVector<int>(line);

  getline(cin, line);
  vector<int> baskets = parseVector<int>(line);

  cout << "Solution started ...." << endl;
  int ans = sol.numOfUnplacedFruits(fruits, baskets);

  cout << "ans : " << ans << endl;

  return 0;
}