#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  int countDistinct(vector<int>& nums, int k, int p) {
    int res = 0;
    int n = nums.size();

    set<vector<int>> st;

    unordered_set<long long> seen;

    long long base = 200003;
    long long MOD = 1e9 + 7;

    cout << "Printing the subarrays \n";
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      // vector<int> vect;
      long long hash = 0;
      for (int j = i; j < n; j++) {
        // vect.push_back(nums[j]);
        if (nums[j] % p == 0) {
          cnt++;
        }
        if (cnt <= k) {
          res++;
          // sort(vect.begin(), vect.end());

          // polynomial rolling hash

          hash = (hash * base + nums[j]) % MOD;

          seen.insert(hash);
        } else {
          break;
        }
      }
    }

    bug(seen.size());

    return res;
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

  int k, p;
  cin >> k >> p;

  bug(k, p);

  cout << "Solution started ...." << endl;
  int ans = sol.countDistinct(nums, k, p);

  cout << "ans : " << ans << endl;

  return 0;
}