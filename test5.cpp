#include <bits/stdc++.h>
using namespace std;

#define printVect(a)                 \
  for (auto x : a) cout << x << " "; \
  cout << endl
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}

vector<int> parseVector(string s) {
  vector<int> result;
  string num = "";
  for (char c : s) {
    if (isdigit(c) || c == '-') {
      num += c;
    } else if (!num.empty()) {
      result.push_back(stoi(num));
      num = "";
    }
  }
  if (!num.empty()) result.push_back(stoi(num));
  return result;
}

class Solution {
 public:
  int maximumLength(vector<int>& nums, int k) {
    // seq[i] != seq[i+1]
    // at most k indices
    int ans = 0;

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

  string csvLine;
  getline(cin, csvLine);
  vector<int> prices = parseVector(csvLine);

  int k;
  cin >> k;

  for (int price : prices) {
    cout << price << "  ";
  }
  cout << " K :  " << k << endl;

  Solution sol;
  int res = sol.maximumLength(prices, k);
  cout << "Result : " << res << endl;

  return 0;
}