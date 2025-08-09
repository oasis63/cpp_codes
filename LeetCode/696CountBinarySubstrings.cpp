// 696. Count Binary Substrings

class Solution {
 public:
  int countBinarySubstrings(string s) {
    // groups of consecutive 0s, and 1s
    vector<int> groups;
    int n = s.length();

    int count = 1;
    for (int i = 1; i < n; i++) {
      if (s[i] == s[i - 1])
        count++;
      else {
        groups.push_back(count);
        count = 1;
      }
    }
    groups.push_back(count);

    int ans = 0;
    for (int i = 1; i < groups.size(); i++) {
      ans += min(groups[i], groups[i - 1]);
    }
    return ans;
  }
};