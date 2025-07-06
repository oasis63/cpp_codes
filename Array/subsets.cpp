#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(vector<vector<int>> &ans, vector<int> &res, int currIndex, int n,
               vector<int> &nums) {
        ans.push_back(res);
        if (currIndex > n)
            return;

        for (int i = currIndex; i < n; i++) {
            res.push_back(nums[i]);
            solve(ans, res, i + 1, n, nums);
            res.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> res;
        solve(ans, res, 0, nums.size(), nums);
        return ans;
    }
};

void subset(int num[], int n) {

    int p = 1 << n; // pow(2,n) .. no. of subsets

    for (int i = 0; i < p; i++) {

        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)))
                cout << num[j] << " ";
        }
        cout << endl;
    }
}

int main() {

    int num[] = {1, 2, 3};

    subset(num, 3);
}
