#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>
class Util {
  public:
    template <typename T> void printSet(const set<T> &s) {
        for (const auto &element : s) {
            cout << element << " ";
        }
        cout << endl;
    }
    template <typename T> void printVector(const vector<T> &v) {
        for (const auto &element : v) {
            cout << element << " ";
        }
        cout << endl;
    }
};
Util util;

class Solution {
  public:
    void solve(vector<vector<int>> &ans, vector<int> &nums, vector<int> &res,
               int n) {

        if (res.size() == n) {
            ans.push_back(res);
            return;
        }

        for (int i = 0; i < n; i++) {
            // skip the duplicates
            if (find(res.begin(), res.end(), nums[i]) != res.end())
                continue;
            res.push_back(nums[i]);
            solve(ans, nums, res, n);
            res.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> res;
        int n = nums.size();
        solve(ans, nums, res, n);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums{1, 2, 3};
    vvi result = sol.permute(nums);

    cout << "All Permutations for the given array elements " << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();