#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    int n = fruits.size();
    int mx_fruits = 0;
    unordered_map<int, int> mp;

    int left = 0;
    for (int i = 0; i < n; i++) {
      mp[fruits[i]]++;

      while (mp.size() > 2) {
        mp[fruits[left]]--;
        if (mp[fruits[left]] == 0) {
          mp.erase(fruits[left]);
        }

        left++;
      }

      mx_fruits = max(mx_fruits, i - left + 1);
    }

    return mx_fruits;
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

  vector<int> nums = parseVector<int>(line);

  printVect(nums);

  cout << "Solution started ...." << endl;
  int ans = sol.totalFruit(nums);

  cout << "ans : " << ans << endl;

  return 0;
}

// [3,3,3,1,2,1,1,2,3,3,4]   --  5
// [0,1,6,6,4,4,6]    ---  5
// [1,0,1,4,1,4,1,2,3]  -- 5