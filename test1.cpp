class Solution {
 public:
  vector<string> shortestSubstrings(vector<string>& arr) {
    // using brute force
    vector<string> answer;

    // generate all the substrings
    // substring, count
    unordered_map<string, int> hash;  // string, count

    for (string& str : arr) {
      // generating all the substrings
      int n = str.length();
      for (int i = n - 1; i >= 0; i--) {
        string tmp;
        for (int j = i; j < n; j++) {
          tmp.push_back(str[j]);
          hash[tmp]++;
        }
      }
    }

    // for (auto& [u, v] : hash) {
    //     cout << u << "  " << v << endl;
    // }

    for (string& str : arr) {
      // generating all the substrings
      int n = str.length();
      string ans;
      unordered_map<string, int> ref = hash;

      for (int i = n - 1; i >= 0; i--) {
        string tmp;
        for (int j = i; j < n; j++) {
          tmp.push_back(str[j]);

          ref[tmp]--;

          if (ref[tmp] <= 0) {
            if (ans.empty()) {
              ans = tmp;
            } else if (tmp.length() < ans.length()) {
              ans = tmp;
            } else if (tmp.length() == ans.length()) {
              if (tmp < ans)
                ans = tmp;
            }
          }
        }
      }
      answer.push_back(ans);
    }

    return answer;
  }
};

auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();