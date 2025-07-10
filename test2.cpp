#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

void generateSubsets(vector<int> &S, int index, vector<int> &current, vector<vector<int>> &result) {
  if (index >= S.size()) {
    result.push_back(current);
    return;
  }
  // Ignore the current index.
  generateSubsets(S, index + 1, current, result);

  // Include the current index.
  current.push_back(S[index]);
  generateSubsets(S, index + 1, current, result);
  current.pop_back();
}

vector<vector<int>> subsets(vector<int> &S) {
  vector<vector<int>> result;
  vector<int> current;
  sort(S.begin(), S.end());
  generateSubsets(S, 0, current, result);
  sort(result.begin(), result.end());
  return result;
}

int main() {
  vector<int> nums{1, 2, 3};
  vector<vector<int>> ans = subsets(nums);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
