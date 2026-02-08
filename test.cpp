#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  vector<string> findWords(vector<string>& words) {
    vector<string> mp = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

    vector<string> ans;

    for (string& s : mp) {
    }

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;

  int n;
  cin >> n;
  cin.ignore();

  vector<string> nums(n);
  for (auto& elem : nums) {
    cin >> elem;
  }

  printVect(nums);

  cout << "Solution started ...." << endl;
  vector<string> ans = sol.findWords(nums);

  printVect(ans);

  return 0;
}