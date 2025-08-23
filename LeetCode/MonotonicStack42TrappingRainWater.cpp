#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

// 42. Trapping Rain Water

class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    int ans = 0;

    stack<int> stk;

    for (int i = 0; i < n; i++) {
      // monotonic decreasing stack
      while (!stk.empty() && height[i] > height[stk.top()]) {
        int bottom = stk.top();
        stk.pop();

        // no more left wall
        if (stk.empty())
          break;

        int left = stk.top();

        int right = i;

        int h = min(height[left], height[right]) - height[bottom];
        int w = right - left - 1;

        if (h > 0) {
          ans += h * w;
        }
      }

      stk.push(i);
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

  vector<int> height = parseVector<int>(line);

  printVect(height);

  cout << "Solution started ...." << endl;
  int ans = sol.trap(height);

  cout << "ans : " << ans << endl;

  return 0;
}