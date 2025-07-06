#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

// This is  correct ,, need to understand the logic again  and then submit

class Solution {
 public:
  int lcp(const string& a, const string& b) {
    int len = min(a.length(), b.length());
    int ans = 0;
    for (int i = 0; i < len; i++) {
      if (a[i] != b[i]) {
        break;
      }
      ans++;
    }
    return ans;
  }

  vector<int> longestCommonPrefix(vector<string>& words) {
    int n = words.size();
    if (n == 1) return {0};

    vector<int> adj(n);
    for (int i = 0; i < n - 1; ++i) adj[i] = lcp(words[i], words[i + 1]);

    vector<int> prefixMax(n), suffixMax(n);

    prefixMax[0] = adj[0];
    for (int i = 1; i < n - 1; ++i)
      prefixMax[i] = max(prefixMax[i - 1], adj[i]);

    suffixMax[n - 1] = adj[n - 1];
    for (int i = n - 2; i >= 0; --i)
      suffixMax[i] = max(suffixMax[i + 1], adj[i]);

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      if (n == 2) {
        ans[i] = 0;
        continue;
      }

      if (i == 0) {
        ans[i] = suffixMax[1];
      } else if (i == n - 1) {
        ans[i] = prefixMax[n - 3];
      } else {
        int merged = lcp(words[i - 1], words[i + 1]);
        int left = (i >= 2) ? prefixMax[i - 2] : 0;
        int right = (i + 1 < n - 1) ? suffixMax[i + 1] : 0;
        ans[i] = max({left, right, merged});
      }
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

  string line;
  getline(cin, line);

  vector<string> words = parseStringVector(line);

  printVect(words);

  vector<int> ans = sol.longestCommonPrefix(words);

  cout << "Ans : " << endl;
  printVect(ans);

  return 0;
}

/*

Output
[1,1,0,0,1,1,1,1,1,1,1]
Expected
[1,1,0,0,2,1,1,1,1,1,1]


*/