#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    // monotonic increasing stack
    stack<int> st;

    heights.push_back(0);
    int maxArea = 0;

    for (int i = 0; i < (int)heights.size(); i++) {
      while (!st.empty() && heights[i] < heights[st.top()]) {
        int h = heights[st.top()];
        st.pop();

        int left = -1;
        int right = i;

        if (!st.empty()) {
          left = st.top();
        }

        // int left = st.empty() ? -1 : st.top();
        int width = right - left - 1;
        maxArea = max(maxArea, h * width);
      }

      st.push(i);
    }
    heights.pop_back();
    return maxArea;
  }

  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty())
      return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> heights(n, 0);
    int maxArea = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == '1')
          heights[j] += 1;
        else
          heights[j] = 0;
      }
      maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
  }
};

int main() {
  Solution s;
  vector<vector<char>> matrix = {
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}};
  cout << s.maximalRectangle(matrix) << endl;  // Output: 6
}
