#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

typedef long long ll;

void solve(int ind, ll sum1, ll sum2, ll &ans, vector<int> &nums) {
  if (ind >= (int)nums.size()) {
    cout << "sum1 : " << sum1 << " sum2 : " << sum2 << endl;
    ans = min(ans, abs(sum1 - sum2));
    return;
  }

  solve(ind + 1, sum1 + nums[ind], sum2, ans, nums);

  solve(ind + 1, sum1, sum2 + nums[ind], ans, nums);
}

unordered_map<string, ll> dp;

ll dp_top_down(int ind, ll sum1, ll sum2, vector<int> &nums) {
  if (ind >= (int)nums.size()) {
    return abs(sum1 - sum2);
  }

  string key = to_string(ind) + "|" + to_string(sum1);

  if (dp.count(key)) {
    return dp[key];
  }

  ll includedInSum1 = dp_top_down(ind + 1, sum1 + nums[ind], sum2, nums);
  ll includedInSum2 = dp_top_down(ind + 1, sum1, sum2 + nums[ind], nums);

  return dp[key] = min(includedInSum1, includedInSum2);
}

int main() {
  fast;
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);

  int n;
  cin >> n;
  cin.ignore();

  vector<int> nums(n);
  for (int &a : nums) {
    cin >> a;
  }

  ll ans = dp_top_down(0, 0, 0, nums);

  cout << ans << endl;

  //   brute force.. TLE
  // int grp1 = 0;
  // int grp2 = 0;

  // sort(nums.rbegin(), nums.rend());

  // int total_sum = 0;

  // for (int i : nums) {
  //   cout << i << endl;
  //   if (grp2 > grp1) {
  //     grp1 += i;
  //   } else {
  //     grp2 += i;
  //   }
  //   total_sum += i;
  // }

  // bug(grp1, grp2, total_sum);

  // cout << abs(grp1 - grp2) << endl;

  return 0;
}