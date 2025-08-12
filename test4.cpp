#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = fruits.size();
    int ans = 0;

    vector<int> placed(n, -1);

    int m = baskets.size();

    vector<pair<int, int>> basket_pair;

    for (int i = 0; i < m; i++) {
      basket_pair.emplace_back(baskets[i], i);
    }

    sort(basket_pair.begin(), basket_pair.end());

    for (int i = 0; i < n; i++) {
      int fruit = fruits[i];

      int p_ind = lower_bound(basket_pair.begin(), basket_pair.end(), make_pair(fruit, -1),
                              [](const pair<int, int>& a, const pair<int, int>& b) { return a.first < b.first; }) -
                  basket_pair.begin();

      int value = basket_pair[p_ind].first;
      int ind = basket_pair[p_ind].second;

      bug(fruit, value, ind);
    }

    // printPairVect(basket_pair);

    // set<int> available;
    // for (int i = 0; i < n; ++i) {
    //     available.insert(i);
    // }
    for (int i = 0; i < n; i++) {
      bool found = false;
      // for (auto it = available.begin(); it != available.end(); ++it) {
      for (int j = 0; j < m; j++) {
        if (baskets[j] >= fruits[i]) {
          // available.erase(it);
          baskets[j] = -1;
          found = true;
          break;
        }
      }

      if (found) {
        fruits[i] = -1;
      }
    }

    for (int i : fruits) {
      if (i != -1) {
        ans++;
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