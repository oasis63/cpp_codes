#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

void nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
  unordered_map<int, int> mp;
  int n = nums2.size();

  // monotonic stack
  stack<int> stk;

  for (int i = 0; i < n; i++) {
    while (!stk.empty() && nums2[i] > stk.top()) {
      mp[stk.top()] = nums2[i];
      stk.pop();
    }
    stk.push(nums2[i]);
  }

  while (!stk.empty()) {
    mp[stk.top()] = -1;
    stk.pop();
  }

  vector<int> ngte;

  for (int &el : nums1) {
    ngte.push_back(mp[el]);
  }

  printVector<int>(ngte);
}

int main() {
  set_io_files("input.txt", "output.txt");

  string line;
  getline(cin, line);
  vector<int> nums1 = parseVector<int>(line);
  getline(cin, line);
  vector<int> nums2 = parseVector<int>(line);

  nextGreaterElement(nums1, nums2);

  return 0;
}